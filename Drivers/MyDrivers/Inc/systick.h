#ifndef SYSTICK_DRIVER_H
#define SYSTICK_DRIVER_H
#include <stdint.h>
void SysTick_Init(uint32_t tick_hz); uint32_t SysTick_GetTick(void); void SysTick_DelayMs(uint32_t ms);
void SysTick_Handler(void);
#endif
