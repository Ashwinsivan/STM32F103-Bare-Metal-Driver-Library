#ifndef STM32F103XX_DMA_H_
#define STM32F103XX_DMA_H_

#include "stm32f103xx.h"

/********************************************************************
 * DMA Channels
 ********************************************************************/
#define DMA_CHANNEL_1       1U
#define DMA_CHANNEL_2       2U
#define DMA_CHANNEL_3       3U
#define DMA_CHANNEL_4       4U
#define DMA_CHANNEL_5       5U
#define DMA_CHANNEL_6       6U
#define DMA_CHANNEL_7       7U

/********************************************************************
 * DMA Direction
 ********************************************************************/
#define DMA_DIRECTION_PERIPHERAL_TO_MEMORY     0U
#define DMA_DIRECTION_MEMORY_TO_PERIPHERAL     1U

/********************************************************************
 * DMA Peripheral Increment
 ********************************************************************/
#define DMA_PERIPH_INCREMENT_DISABLE           0U
#define DMA_PERIPH_INCREMENT_ENABLE            1U

/********************************************************************
 * DMA Memory Increment
 ********************************************************************/
#define DMA_MEMORY_INCREMENT_DISABLE           0U
#define DMA_MEMORY_INCREMENT_ENABLE            1U

/********************************************************************
 * DMA Peripheral Data Size
 ********************************************************************/
#define DMA_PDATA_SIZE_8BIT                    0U
#define DMA_PDATA_SIZE_16BIT                   1U
#define DMA_PDATA_SIZE_32BIT                   2U

/********************************************************************
 * DMA Memory Data Size
 ********************************************************************/
#define DMA_MDATA_SIZE_8BIT                    0U
#define DMA_MDATA_SIZE_16BIT                   1U
#define DMA_MDATA_SIZE_32BIT                   2U

/********************************************************************
 * DMA Mode
 ********************************************************************/
#define DMA_MODE_NORMAL                        0U
#define DMA_MODE_CIRCULAR                      1U

/********************************************************************
 * DMA Priority
 ********************************************************************/
#define DMA_PRIORITY_LOW                       0U
#define DMA_PRIORITY_MEDIUM                    1U
#define DMA_PRIORITY_HIGH                      2U
#define DMA_PRIORITY_VERY_HIGH                 3U

/********************************************************************
 * DMA Configuration
 ********************************************************************/
typedef struct
{
    uint8_t Channel;

    uint8_t Direction;

    uint8_t PeripheralIncrement;

    uint8_t MemoryIncrement;

    uint8_t PeripheralDataSize;

    uint8_t MemoryDataSize;

    uint8_t Mode;

    uint8_t Priority;

} DMA_Config_t;

/********************************************************************
 * DMA Handle
 ********************************************************************/
typedef struct
{
    DMA_RegDef_t *pDMAx;
    DMA_Config_t DMA_Config;

} DMA_Handle_t;

/********************************************************************
 * DMA APIs
 ********************************************************************/
uint8_t DMA_Init(DMA_Handle_t *pDMAHandle);

void DMA_SetPeripheralAddress(DMA_Handle_t *pDMAHandle,
                              uint32_t Address);

void DMA_SetMemoryAddress(DMA_Handle_t *pDMAHandle,
                          uint32_t Address);

void DMA_SetTransferLength(DMA_Handle_t *pDMAHandle,
                           uint16_t Length);

void DMA_Enable(DMA_Handle_t *pDMAHandle);

void DMA_Disable(DMA_Handle_t *pDMAHandle);

uint8_t DMA_IsTransferComplete(DMA_Handle_t *pDMAHandle);

void DMA_ClearTransferComplete(DMA_Handle_t *pDMAHandle);
/********************************************************************
 * DMA Interrupt Sources
 ********************************************************************/
#define DMA_INTERRUPT_TRANSFER_COMPLETE     0U
#define DMA_INTERRUPT_HALF_TRANSFER        1U
#define DMA_INTERRUPT_TRANSFER_ERROR       2U


/********************************************************************
 * DMA Status
 ********************************************************************/
#define DMA_STATUS_TRANSFER_COMPLETE       0U
#define DMA_STATUS_HALF_TRANSFER            1U
#define DMA_STATUS_TRANSFER_ERROR           2U


/********************************************************************
 * DMA APIs
 ********************************************************************/
void DMA_EnableInterrupt(DMA_Handle_t *pDMAHandle,
                         uint8_t Interrupt);

void DMA_DisableInterrupt(DMA_Handle_t *pDMAHandle,
                          uint8_t Interrupt);

uint8_t DMA_GetStatus(DMA_Handle_t *pDMAHandle,
                      uint8_t Status);

void DMA_ClearStatus(DMA_Handle_t *pDMAHandle,
                     uint8_t Status);

#endif /* STM32F103XX_DMA_H_ */
