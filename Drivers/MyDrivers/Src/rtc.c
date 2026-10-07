#include "rtc.h"
#include "rcc.h"
void RTC_EnableLSE(void){RCC_BKP_CLK_EN();RCC_PWR_CLK_EN();RCC->BDCR|=1;while(!(RCC->BDCR&(1U<<1))){}RCC->BDCR|=1U<<15;}
void RTC_SetPrescaler(uint32_t n){RTC->CRL=0;RTC->PRLH=(n>>16)&0xFU;RTC->PRLL=n&0xFFFFU;}
uint32_t RTC_GetCounter(void){return ((uint32_t)RTC->CNTH<<16)|RTC->CNTL;}
void RTC_SetCounter(uint32_t n){RTC->CRL&=~1U;RTC->CNTH=n>>16;RTC->CNTL=n&0xFFFFU;RTC->CRL|=1U;}
