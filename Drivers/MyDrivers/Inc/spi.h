#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H
#include "stm32f103xx.h"
#define SPI_MASTER 1
#define SPI_SLAVE 0
#define SPI_CPOL_LOW 0
#define SPI_CPOL_HIGH 1
#define SPI_CPHA_1EDGE 0
#define SPI_CPHA_2EDGE 1
typedef struct {uint8_t Master;uint8_t CPOL;uint8_t CPHA;uint8_t BaudDiv;} SPI_Config_t;
typedef struct {SPI_RegDef_t*pSPIx;SPI_Config_t Config;} SPI_Handle_t;
void SPI_Init(SPI_Handle_t*); uint8_t SPI_TransferByte(SPI_Handle_t*,uint8_t); void SPI_Enable(SPI_Handle_t*); void SPI_Disable(SPI_Handle_t*);
#endif
