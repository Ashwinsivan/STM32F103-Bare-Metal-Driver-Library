#ifndef RTC_DRIVER_H
#define RTC_DRIVER_H
#include "stm32f103xx.h"
void RTC_EnableLSE(void);void RTC_SetPrescaler(uint32_t);uint32_t RTC_GetCounter(void);void RTC_SetCounter(uint32_t);
#endif
