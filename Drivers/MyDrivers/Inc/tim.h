#ifndef TIM_DRIVER_H
#define TIM_DRIVER_H
#include "stm32f103xx.h"
typedef struct {uint16_t Prescaler;uint32_t Period;uint8_t AutoReloadPreload;} TIM_Config_t;
typedef struct {TIM_RegDef_t*pTIMx;TIM_Config_t Config;} TIM_Handle_t;
void TIM_Init(TIM_Handle_t*);void TIM_Start(TIM_Handle_t*);void TIM_Stop(TIM_Handle_t*);void TIM_SetCounter(TIM_Handle_t*,uint32_t);uint32_t TIM_GetCounter(TIM_Handle_t*);
void TIM_SetCompare(TIM_Handle_t*,uint8_t,uint16_t);void TIM_EnableUpdateIRQ(TIM_Handle_t*);void TIM_DisableUpdateIRQ(TIM_Handle_t*);
#endif
