#ifndef CRC_DRIVER_H
#define CRC_DRIVER_H
#include "stm32f103xx.h"
void CRC_Init(void);uint32_t CRC_Calc(const uint32_t*,uint32_t);
#endif
