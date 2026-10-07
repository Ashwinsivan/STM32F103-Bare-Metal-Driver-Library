#ifndef PWR_DRIVER_H
#define PWR_DRIVER_H
#include "stm32f103xx.h"
#define PWR_SLEEP 0
#define PWR_STOP 1
#define PWR_STANDBY 2
void PWR_Init(void);void PWR_Enter(uint8_t mode);
#endif
