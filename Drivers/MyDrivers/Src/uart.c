#include "uart.h"
#include "rcc.h"
#include "stm32f1xx.h"


static uint32_t UART_GetPCLK(USART_RegDef_t *pUSARTx)
{
    if (pUSARTx == USART1)
    {
        return SystemCoreClock;
    }

    return SystemCoreClock / 2U;
}


void UART_Init(UART_Handle_t *pUARTHandle)
{
    if (pUARTHandle == 0)
    {
        return;
    }

    USART_RegDef_t *pUSARTx = pUARTHandle->pUSARTx;


    /* Enable peripheral clock */

    if (pUSARTx == USART1)
    {
        RCC_USART1_CLK_EN();
    }
    else if (pUSARTx == USART2)
    {
        RCC_USART2_CLK_EN();
    }
    else if (pUSARTx == USART3)
    {
        RCC_USART3_CLK_EN();
    }


    /* Disable USART before configuration */

    pUSARTx->CR1 = 0U;
    pUSARTx->CR2 = 0U;
    pUSARTx->CR3 = 0U;


    /* Word length */

    if (pUARTHandle->Config.WordLength)
    {
        pUSARTx->CR1 |= (1U << 12);
    }


    /* Parity */

    if (pUARTHandle->Config.Parity)
    {
        pUSARTx->CR1 |= (1U << 10);

        if (pUARTHandle->Config.Parity == UART_PARITY_ODD)
        {
            pUSARTx->CR1 |= (1U << 9);
        }
    }


    /* Stop bits */

    pUSARTx->CR2 |=
        ((uint32_t)pUARTHandle->Config.StopBits & 0x3U) << 12;


    /* Baud rate */

    pUSARTx->BRR =
        (UART_GetPCLK(pUSARTx) +
         (pUARTHandle->Config.BaudRate / 2U)) /
        pUARTHandle->Config.BaudRate;


    /* Enable transmitter */

    pUSARTx->CR1 |= (1U << 3);


    /* Enable receiver */

    pUSARTx->CR1 |= (1U << 2);


    /* Enable USART */

    pUSARTx->CR1 |= (1U << 13);


    /* Enable interrupt if requested */

    if (pUARTHandle->Config.EnableIRQ)
    {
        UART_EnableIRQ(pUARTHandle);
    }
}


void UART_SendByte(
    UART_Handle_t *pUARTHandle,
    uint8_t Data
)
{
    if (pUARTHandle == 0)
    {
        return;
    }

    USART_RegDef_t *pUSARTx = pUARTHandle->pUSARTx;


    while (!(pUSARTx->SR & (1U << 7)))
    {
    }


    pUSARTx->DR = Data;
}


void UART_Send(
    UART_Handle_t *pUARTHandle,
    const uint8_t *pData,
    uint16_t Length
)
{
    if ((pUARTHandle == 0) || (pData == 0))
    {
        return;
    }


    for (uint16_t i = 0U; i < Length; i++)
    {
        UART_SendByte(pUARTHandle, pData[i]);
    }
}


uint8_t UART_ReceiveByte(
    UART_Handle_t *pUARTHandle,
    uint8_t *pData,
    uint32_t Timeout
)
{
    if ((pUARTHandle == 0) || (pData == 0))
    {
        return 1U;
    }


    USART_RegDef_t *pUSARTx = pUARTHandle->pUSARTx;


    while (Timeout--)
    {
        if (pUSARTx->SR & (1U << 5))
        {
            *pData = (uint8_t)pUSARTx->DR;

            return 0U;
        }
    }


    return 1U;
}


void UART_EnableIRQ(UART_Handle_t *pUARTHandle)
{
    if (pUARTHandle == 0)
    {
        return;
    }


    USART_RegDef_t *pUSARTx = pUARTHandle->pUSARTx;


    /* RXNE interrupt */

    pUSARTx->CR1 |= (1U << 5);


    if (pUSARTx == USART1)
    {
        NVIC_ISER1 |= (1U << 5);
    }
    else if (pUSARTx == USART2)
    {
        NVIC_ISER1 |= (1U << 6);
    }
    else if (pUSARTx == USART3)
    {
        NVIC_ISER1 |= (1U << 7);
    }
}


void UART_DisableIRQ(UART_Handle_t *pUARTHandle)
{
    if (pUARTHandle == 0)
    {
        return;
    }


    pUARTHandle->pUSARTx->CR1 &= ~(1U << 5);
}
