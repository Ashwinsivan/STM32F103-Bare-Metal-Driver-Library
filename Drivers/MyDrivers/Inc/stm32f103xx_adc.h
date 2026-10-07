#ifndef STM32F103XX_ADC_H_
#define STM32F103XX_ADC_H_

#include "stm32f103xx.h"

/********************************************************************
 * ADC Channels
 ********************************************************************/
#define ADC_CHANNEL_0      0U
#define ADC_CHANNEL_1      1U
#define ADC_CHANNEL_2      2U
#define ADC_CHANNEL_3      3U
#define ADC_CHANNEL_4      4U
#define ADC_CHANNEL_5      5U
#define ADC_CHANNEL_6      6U
#define ADC_CHANNEL_7      7U
#define ADC_CHANNEL_8      8U
#define ADC_CHANNEL_9      9U
#define ADC_CHANNEL_10     10U
#define ADC_CHANNEL_11     11U
#define ADC_CHANNEL_12     12U
#define ADC_CHANNEL_13     13U
#define ADC_CHANNEL_14     14U
#define ADC_CHANNEL_15     15U

/********************************************************************
 * ADC Sample Time
 ********************************************************************/
#define ADC_SAMPLE_1_5_CYCLES       0U
#define ADC_SAMPLE_7_5_CYCLES       1U
#define ADC_SAMPLE_13_5_CYCLES      2U
#define ADC_SAMPLE_28_5_CYCLES      3U
#define ADC_SAMPLE_41_5_CYCLES      4U
#define ADC_SAMPLE_55_5_CYCLES      5U
#define ADC_SAMPLE_71_5_CYCLES      6U
#define ADC_SAMPLE_239_5_CYCLES     7U

/********************************************************************
 * ADC Conversion Mode
 ********************************************************************/
#define ADC_MODE_SINGLE_CONVERSION      0U
#define ADC_MODE_CONTINUOUS_CONVERSION 1U

/********************************************************************
 * ADC Status
 ********************************************************************/
#define ADC_OK                 0U
#define ADC_ERROR              1U
#define ADC_TIMEOUT            2U

/********************************************************************
 * ADC Configuration
 ********************************************************************/
typedef struct
{
    uint8_t Channel;
    uint8_t SampleTime;
    uint8_t ConversionMode;
} ADC_Config_t;

/********************************************************************
 * ADC Handle
 ********************************************************************/
typedef struct
{
    ADC_RegDef_t *pADCx;
    ADC_Config_t ADC_Config;
} ADC_Handle_t;

/********************************************************************
 * ADC Driver APIs
 ********************************************************************/
uint8_t ADC_Init(ADC_Handle_t *pADCHandle);

uint8_t ADC_StartConversion(ADC_RegDef_t *pADCx);

uint8_t ADC_IsConversionComplete(ADC_RegDef_t *pADCx);

uint16_t ADC_ReadValue(ADC_RegDef_t *pADCx);

uint8_t ADC_Read(ADC_RegDef_t *pADCx,
                 uint16_t *pData,
                 uint32_t Timeout);

void ADC_StopConversion(ADC_RegDef_t *pADCx);

void ADC_Calibrate(ADC_RegDef_t *pADCx);
/********************************************************************
 * ADC DMA
 ********************************************************************/
#define ADC_DMA_DISABLE       0U
#define ADC_DMA_ENABLE        1U

#endif
