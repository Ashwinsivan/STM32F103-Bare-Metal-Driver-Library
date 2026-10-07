#include "exti.h"
#include "afio.h"
static EXTI_Callback_t cb[16];
static void en_irq(uint8_t l){if(l<=4)NVIC_ISER0|=1U<<(6+l);else if(l<=9)NVIC_ISER0|=1U<<23;else NVIC_ISER1|=1U<<8;}
void EXTI_Init(uint8_t l,uint8_t p,uint8_t t){if(l>15)return;AFIO_SetEXTI_Port(l,p);EXTI->IMR|=1U<<l;if(t==EXTI_RISING)EXTI->RTSR|=1U<<l;else if(t==EXTI_FALLING)EXTI->FTSR|=1U<<l;else{EXTI->RTSR|=1U<<l;EXTI->FTSR|=1U<<l;}en_irq(l);}
void EXTI_Enable(uint8_t l){EXTI->IMR|=1U<<l;} void EXTI_Disable(uint8_t l){EXTI->IMR&=~(1U<<l);}
void EXTI_SetCallback(uint8_t l,EXTI_Callback_t f){if(l<16)cb[l]=f;}
static void h(uint8_t l){if(EXTI->PR&(1U<<l)){EXTI->PR=1U<<l;if(cb[l])cb[l]();}}
void EXTI0_IRQHandler(void){h(0);}void EXTI1_IRQHandler(void){h(1);}void EXTI2_IRQHandler(void){h(2);}void EXTI3_IRQHandler(void){h(3);}void EXTI4_IRQHandler(void){h(4);}
void EXTI9_5_IRQHandler(void){for(uint8_t i=5;i<=9;i++)h(i);}
void EXTI15_10_IRQHandler(void){for(uint8_t i=10;i<=15;i++)h(i);}
