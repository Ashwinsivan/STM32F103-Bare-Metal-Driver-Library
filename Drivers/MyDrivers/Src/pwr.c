#include "pwr.h"
#include "rcc.h"
void PWR_Init(void){RCC_PWR_CLK_EN();}
void PWR_Enter(uint8_t m){PWR->CR&=~(3U<<1);if(m==PWR_STOP)PWR->CR|=1U<<1;if(m==PWR_STANDBY)PWR->CR|=3U<<1;__asm volatile("wfi");}
