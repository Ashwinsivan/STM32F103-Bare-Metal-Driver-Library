#ifndef DMA_DRIVER_H
#define DMA_DRIVER_H
#include "stm32f103xx.h"
#define DMA_DIR_P2M 0
#define DMA_DIR_M2P 1
#define DMA_DIR_M2M 2
#define DMA_SIZE_8 0
#define DMA_SIZE_16 1
#define DMA_SIZE_32 2
#define DMA_NORMAL 0
#define DMA_CIRCULAR 1
typedef struct {uint8_t Channel;uint8_t Direction;uint8_t PeripheralInc;uint8_t MemoryInc;uint8_t PeripheralSize;uint8_t MemorySize;uint8_t Mode;uint8_t Priority;} DMA_Config_t;
typedef struct {DMA_RegDef_t*pDMAx;DMA_Config_t Config;} DMA_Handle_t;
uint8_t DMA_Init(DMA_Handle_t*);void DMA_SetPeripheralAddress(DMA_Handle_t*,uint32_t);void DMA_SetMemoryAddress(DMA_Handle_t*,uint32_t);void DMA_SetLength(DMA_Handle_t*,uint16_t);void DMA_Enable(DMA_Handle_t*);void DMA_Disable(DMA_Handle_t*);
uint8_t DMA_GetTC(DMA_Handle_t*);void DMA_ClearTC(DMA_Handle_t*);
#endif
