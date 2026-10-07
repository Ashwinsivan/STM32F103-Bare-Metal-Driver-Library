#ifndef EXTI_DRIVER_H
#define EXTI_DRIVER_H
#include "stm32f103xx.h"
#define EXTI_RISING 0
#define EXTI_FALLING 1
#define EXTI_BOTH 2
typedef void (*EXTI_Callback_t)(void);
void EXTI_Init(uint8_t line,uint8_t port,uint8_t trigger);
void EXTI_Enable(uint8_t line); void EXTI_Disable(uint8_t line);
void EXTI_SetCallback(uint8_t line,EXTI_Callback_t cb);
void EXTI0_IRQHandler(void); void EXTI1_IRQHandler(void); void EXTI2_IRQHandler(void); void EXTI3_IRQHandler(void); void EXTI4_IRQHandler(void);
void EXTI9_5_IRQHandler(void); void EXTI15_10_IRQHandler(void);
#endif
