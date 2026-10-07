#ifndef ADC_DRIVER_H
#define ADC_DRIVER_H
#include "stm32f103xx.h"
#define ADC_CHANNEL_0 0
#define ADC_CHANNEL_1 1
#define ADC_CHANNEL_2 2
#define ADC_CHANNEL_3 3
#define ADC_CHANNEL_4 4
#define ADC_CHANNEL_5 5
#define ADC_CHANNEL_6 6
#define ADC_CHANNEL_7 7
#define ADC_CHANNEL_8 8
#define ADC_CHANNEL_9 9
#define ADC_CHANNEL_10 10
#define ADC_CHANNEL_11 11
#define ADC_CHANNEL_12 12
#define ADC_CHANNEL_13 13
#define ADC_CHANNEL_14 14
#define ADC_CHANNEL_15 15
#define ADC_SAMPLE_1_5 0
#define ADC_SAMPLE_7_5 1
#define ADC_SAMPLE_13_5 2
#define ADC_SAMPLE_28_5 3
#define ADC_SAMPLE_41_5 4
#define ADC_SAMPLE_55_5 5
#define ADC_SAMPLE_71_5 6
#define ADC_SAMPLE_239_5 7
typedef struct {uint8_t Channel;uint8_t SampleTime;uint8_t Continuous;uint8_t DMAEnable;} ADC_Config_t;
typedef struct {ADC_RegDef_t*pADCx;ADC_Config_t Config;} ADC_Handle_t;
uint8_t ADC_Init(ADC_Handle_t*); void ADC_Start(ADC_RegDef_t*); uint8_t ADC_Read(ADC_RegDef_t*,uint16_t*,uint32_t); void ADC_Stop(ADC_RegDef_t*); void ADC_Calibrate(ADC_RegDef_t*);
#endif
