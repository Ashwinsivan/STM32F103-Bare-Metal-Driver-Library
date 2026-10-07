#include "afio.h"
#include "rcc.h"
void AFIO_SetEXTI_Port(uint8_t l,uint8_t p){if(l>15||p>7)return;RCC_AFIO_CLK_EN();uint8_t i=l/4,s=(l%4)*4;AFIO->EXTICR[i]&=~(0xFU<<s);AFIO->EXTICR[i]|=((uint32_t)p)<<s;}
void AFIO_DisableJTAG(void){RCC_AFIO_CLK_EN();AFIO->MAPR|=(1U<<25);AFIO->MAPR|=(1U<<24);}
void AFIO_DisableJTAG_EnableSWD(void){RCC_AFIO_CLK_EN();AFIO->MAPR&=~(7U<<24);AFIO->MAPR|=(2U<<24);}
