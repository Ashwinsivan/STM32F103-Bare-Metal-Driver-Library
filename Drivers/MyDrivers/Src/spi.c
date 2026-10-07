#include "spi.h"
#include "rcc.h"
void SPI_Init(SPI_Handle_t*h){SPI_RegDef_t*s=h->pSPIx;if(s==SPI1)RCC_SPI1_CLK_EN();else RCC_SPI2_CLK_EN();s->CR1=0;s->CR1|=(h->Config.Master?1U<<2:0)|(h->Config.CPOL?1U<<1:0)|(h->Config.CPHA?1U:0);s->CR1|=((uint32_t)(h->Config.BaudDiv&7U))<<3;s->CR1|=1U<<9|1U<<8;SPI_Enable(h);}
void SPI_Enable(SPI_Handle_t*h){h->pSPIx->CR1|=1U<<6;}void SPI_Disable(SPI_Handle_t*h){h->pSPIx->CR1&=~(1U<<6);}
uint8_t SPI_TransferByte(SPI_Handle_t*h,uint8_t d){while(!(h->pSPIx->SR&2U)){}h->pSPIx->DR=d;while(!(h->pSPIx->SR&1U)){}return (uint8_t)h->pSPIx->DR;}
