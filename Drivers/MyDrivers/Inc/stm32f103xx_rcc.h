#ifndef STM32F103XX_RCC_H_
#define STM32F103XX_RCC_H_

#include "stm32f103xx.h"

void RCC_GPIOA_CLK_EN(void);
void RCC_GPIOB_CLK_EN(void);
void RCC_GPIOC_CLK_EN(void);
void RCC_GPIOD_CLK_EN(void);
void RCC_GPIOE_CLK_EN(void);

void RCC_AFIO_CLK_EN(void);

void RCC_ADC1_CLK_EN(void);
void RCC_ADC2_CLK_EN(void);
void RCC_ADC_SetClockDiv2(void);
void RCC_DMA1_CLK_EN(void);
void RCC_DMA2_CLK_EN(void);
void RCC_I2C1_CLK_EN(void);
void RCC_I2C2_CLK_EN(void);

#endif /* STM32F103XX_RCC_H_ */
