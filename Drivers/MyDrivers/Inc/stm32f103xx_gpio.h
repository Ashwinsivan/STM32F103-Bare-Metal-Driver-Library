#ifndef STM32F103XX_GPIO_H_
#define STM32F103XX_GPIO_H_

#include "stm32f103xx.h"

/********************************************************************
 * GPIO Pin Numbers
 ********************************************************************/

#define GPIO_PIN_0     0
#define GPIO_PIN_1     1
#define GPIO_PIN_2     2
#define GPIO_PIN_3     3
#define GPIO_PIN_4     4
#define GPIO_PIN_5     5
#define GPIO_PIN_6     6
#define GPIO_PIN_7     7
#define GPIO_PIN_8     8
#define GPIO_PIN_9     9
#define GPIO_PIN_10    10
#define GPIO_PIN_11    11
#define GPIO_PIN_12    12
#define GPIO_PIN_13    13
#define GPIO_PIN_14    14
#define GPIO_PIN_15    15

/********************************************************************
 * GPIO Modes
 ********************************************************************/

/* Input modes */

#define GPIO_MODE_INPUT_ANALOG       0x0
#define GPIO_MODE_INPUT_FLOATING     0x4
#define GPIO_MODE_INPUT_PULLUP       0x8

/* Output Push-Pull */

#define GPIO_MODE_OUTPUT_PP_10MHZ    0x1
#define GPIO_MODE_OUTPUT_PP_2MHZ     0x2
#define GPIO_MODE_OUTPUT_PP_50MHZ    0x3

/* Output Open-Drain */

#define GPIO_MODE_OUTPUT_OD_10MHZ    0x5
#define GPIO_MODE_OUTPUT_OD_2MHZ     0x6
#define GPIO_MODE_OUTPUT_OD_50MHZ    0x7

/********************************************************************
 * GPIO Pin State
 ********************************************************************/

#define GPIO_PIN_SET                1
#define GPIO_PIN_RESET              0

/********************************************************************
 * GPIO Configuration Structure
 ********************************************************************/

typedef struct
{
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinMode;

} GPIO_PinConfig_t;

typedef struct
{
    GPIO_RegDef_t *pGPIOx;

    GPIO_PinConfig_t GPIO_PinConfig;

} GPIO_Handle_t;

/********************************************************************
 * GPIO APIs
 ********************************************************************/

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);

void GPIO_WritePin(GPIO_RegDef_t *pGPIOx,
                   uint8_t PinNumber,
                   uint8_t PinState);

uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx,
                     uint8_t PinNumber);

void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx,
                    uint8_t PinNumber);

void GPIO_WritePort(GPIO_RegDef_t *pGPIOx,
                    uint16_t Value);

uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx);

#endif /* STM32F103XX_GPIO_H_ */
