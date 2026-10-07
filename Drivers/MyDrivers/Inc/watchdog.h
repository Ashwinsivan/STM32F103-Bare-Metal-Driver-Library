#ifndef WATCHDOG_DRIVER_H
#define WATCHDOG_DRIVER_H
#include "stm32f103xx.h"
void IWDG_Init(uint8_t prescaler,uint16_t reload);void IWDG_Refresh(void);
void WWDG_Init(uint8_t prescaler,uint8_t window);void WWDG_Refresh(uint8_t value);
#endif
