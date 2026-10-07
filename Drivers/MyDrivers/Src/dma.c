#include "dma.h"
#include "rcc.h"
static DMA_Channel_RegDef_t*c(DMA_Handle_t*h){return &h->pDMAx->CHANNEL[h->Config.Channel-1];}
uint8_t DMA_Init(DMA_Handle_t*h){if(!h||h->Config.Channel<1||h->Config.Channel>7)return 1;if(h->pDMAx==DMA1)RCC_DMA1_CLK_EN();else if(h->pDMAx==DMA2)RCC_DMA2_CLK_EN();else return 1;DMA_Channel_RegDef_t*x=c(h);x->CCR=0;x->CCR|=(h->Config.Direction==DMA_DIR_M2P?1U<<4:0);if(h->Config.Direction==DMA_DIR_M2M)x->CCR|=1U<<14;if(h->Config.Mode)x->CCR|=1U<<5;if(h->Config.PeripheralInc)x->CCR|=1U<<6;if(h->Config.MemoryInc)x->CCR|=1U<<7;x->CCR|=(h->Config.PeripheralSize&3U)<<8;x->CCR|=(h->Config.MemorySize&3U)<<10;x->CCR|=(h->Config.Priority&3U)<<12;return 0;}
void DMA_SetPeripheralAddress(DMA_Handle_t*h,uint32_t a){c(h)->CPAR=a;}void DMA_SetMemoryAddress(DMA_Handle_t*h,uint32_t a){c(h)->CMAR=a;}void DMA_SetLength(DMA_Handle_t*h,uint16_t n){c(h)->CNDTR=n;}void DMA_Enable(DMA_Handle_t*h){c(h)->CCR|=1;}void DMA_Disable(DMA_Handle_t*h){c(h)->CCR&=~1U;}
uint8_t DMA_GetTC(DMA_Handle_t*h){uint8_t s=(h->Config.Channel-1)*4;return (h->pDMAx->ISR>>(s+1))&1U;}void DMA_ClearTC(DMA_Handle_t*h){uint8_t s=(h->Config.Channel-1)*4;h->pDMAx->IFCR=1U<<(s+1);}
