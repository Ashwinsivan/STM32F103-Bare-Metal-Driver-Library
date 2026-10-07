#ifndef CAN_DRIVER_H
#define CAN_DRIVER_H
#include "stm32f103xx.h"
typedef struct {uint16_t Prescaler;uint8_t BS1;uint8_t BS2;uint8_t SJW;} CAN_Config_t;
typedef struct {CAN_RegDef_t*pCANx;CAN_Config_t Config;} CAN_Handle_t;
void CAN_Init(CAN_Handle_t*);uint8_t CAN_Send(CAN_Handle_t*,uint32_t,const uint8_t*,uint8_t);
#endif
