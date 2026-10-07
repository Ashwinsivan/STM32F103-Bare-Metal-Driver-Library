#ifndef STM32F103XX_EXTI_H_
#define STM32F103XX_EXTI_H_

#include "stm32f103xx.h"

/********************************************************************
 * EXTI Trigger Modes
 ********************************************************************/

#define EXTI_TRIGGER_RISING             0
#define EXTI_TRIGGER_FALLING            1
#define EXTI_TRIGGER_RISING_FALLING     2

/********************************************************************
 * EXTI Port Codes
 *
 * AFIO EXTICR encoding:
 *
 * 0000 = GPIOA
 * 0001 = GPIOB
 * 0010 = GPIOC
 * 0011 = GPIOD
 * 0100 = GPIOE
 ********************************************************************/

#define EXTI_PORT_GPIOA                 0
#define EXTI_PORT_GPIOB                 1
#define EXTI_PORT_GPIOC                 2
#define EXTI_PORT_GPIOD                 3
#define EXTI_PORT_GPIOE                 4

/********************************************************************
 * EXTI Configuration Structure
 ********************************************************************/

typedef struct
{
    uint8_t EXTI_Line;
    uint8_t EXTI_PortCode;
    uint8_t EXTI_Trigger;

} EXTI_Config_t;

/********************************************************************
 * EXTI APIs
 ********************************************************************/

void EXTI_Init(EXTI_Config_t *pEXTIConfig);

void EXTI_Enable(uint8_t EXTI_Line);

void EXTI_Disable(uint8_t EXTI_Line);

void EXTI_ClearPending(uint8_t EXTI_Line);

uint8_t EXTI_GetPending(uint8_t EXTI_Line);

void EXTI_SoftwareTrigger(uint8_t EXTI_Line);

void EXTI_EnableIRQ(uint8_t EXTI_Line);

void EXTI_DisableIRQ(uint8_t EXTI_Line);

/********************************************************************
 * EXTI Interrupt Handlers
 ********************************************************************/

void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);

void EXTI9_5_IRQHandler(void);
void EXTI15_10_IRQHandler(void);

/********************************************************************
 * EXTI Callback
 ********************************************************************/

typedef void (*EXTI_Callback_t)(void);

void EXTI_RegisterCallback(uint8_t EXTI_Line,
                           EXTI_Callback_t callback);

#endif /* STM32F103XX_EXTI_H_ */
