#ifndef RCC_DRIVER_H
#define RCC_DRIVER_H
#include "stm32f103xx.h"
void RCC_GPIOA_CLK_EN(void); void RCC_GPIOB_CLK_EN(void); void RCC_GPIOC_CLK_EN(void);
void RCC_AFIO_CLK_EN(void); void RCC_ADC1_CLK_EN(void); void RCC_ADC2_CLK_EN(void);
void RCC_DMA1_CLK_EN(void); void RCC_DMA2_CLK_EN(void);
void RCC_USART1_CLK_EN(void); void RCC_USART2_CLK_EN(void); void RCC_USART3_CLK_EN(void);
void RCC_SPI1_CLK_EN(void); void RCC_SPI2_CLK_EN(void);
void RCC_I2C1_CLK_EN(void); void RCC_I2C2_CLK_EN(void);
void RCC_TIM1_CLK_EN(void); void RCC_TIM2_CLK_EN(void); void RCC_TIM3_CLK_EN(void); void RCC_TIM4_CLK_EN(void);
void RCC_CAN1_CLK_EN(void); void RCC_USB_CLK_EN(void); void RCC_PWR_CLK_EN(void); void RCC_BKP_CLK_EN(void);
void RCC_CRC_CLK_EN(void); void RCC_ADC_SetClockDiv2(void);
#endif
