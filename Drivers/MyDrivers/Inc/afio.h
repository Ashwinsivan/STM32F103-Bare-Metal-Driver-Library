#ifndef AFIO_DRIVER_H
#define AFIO_DRIVER_H
#include "stm32f103xx.h"
void AFIO_SetEXTI_Port(uint8_t line,uint8_t port);
void AFIO_DisableJTAG(void);
void AFIO_DisableJTAG_EnableSWD(void);
#endif
