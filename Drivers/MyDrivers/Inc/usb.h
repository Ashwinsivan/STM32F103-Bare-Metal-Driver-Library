#ifndef USB_DRIVER_H
#define USB_DRIVER_H
#include "stm32f103xx.h"
void USB_Init(void);uint16_t USB_GetFrame(void);void USB_SetAddress(uint8_t);
#endif
