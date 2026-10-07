#ifndef UART_DRIVER_H
#define UART_DRIVER_H
#include "stm32f103xx.h"
#define UART_WORDLEN_8 0
#define UART_WORDLEN_9 1
#define UART_STOP_1 0
#define UART_STOP_2 2
#define UART_PARITY_NONE 0
#define UART_PARITY_EVEN 1
#define UART_PARITY_ODD 2
typedef struct {uint32_t BaudRate;uint8_t WordLength;uint8_t StopBits;uint8_t Parity;uint8_t EnableIRQ;} UART_Config_t;
typedef struct {USART_RegDef_t *pUSARTx;UART_Config_t Config;} UART_Handle_t;
void UART_Init(UART_Handle_t *); void UART_SendByte(UART_Handle_t *,uint8_t); void UART_Send(UART_Handle_t *,const uint8_t *,uint16_t); uint8_t UART_ReceiveByte(UART_Handle_t *,uint8_t *,uint32_t); void UART_EnableIRQ(UART_Handle_t *); void UART_DisableIRQ(UART_Handle_t *);
#endif
