#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H
#include "stm32f103xx.h"
#define GPIO_MODE_INPUT_ANALOG 0x0
#define GPIO_MODE_INPUT_FLOATING 0x4
#define GPIO_MODE_INPUT_PULLUP 0x8
#define GPIO_MODE_OUTPUT_PP_10MHZ 0x1
#define GPIO_MODE_OUTPUT_PP_2MHZ 0x2
#define GPIO_MODE_OUTPUT_PP_50MHZ 0x3
#define GPIO_MODE_OUTPUT_OD_10MHZ 0x5
#define GPIO_MODE_OUTPUT_OD_2MHZ 0x6
#define GPIO_MODE_OUTPUT_OD_50MHZ 0x7
#define GPIO_NO_PUPD 0
#define GPIO_PIN_SET 1
#define GPIO_PIN_RESET 0
typedef struct {uint8_t GPIO_PinNumber; uint8_t GPIO_PinMode; uint8_t GPIO_PinPuPdControl;} GPIO_PinConfig_t;
typedef struct {GPIO_RegDef_t *pGPIOx; GPIO_PinConfig_t GPIO_PinConfig;} GPIO_Handle_t;
void GPIO_Init(GPIO_Handle_t *); void GPIO_DeInit(GPIO_RegDef_t *);
void GPIO_WritePin(GPIO_RegDef_t *,uint8_t,uint8_t); uint8_t GPIO_ReadPin(GPIO_RegDef_t *,uint8_t);
void GPIO_TogglePin(GPIO_RegDef_t *,uint8_t);
#endif
