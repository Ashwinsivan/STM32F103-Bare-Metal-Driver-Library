#include "stm32f103xx.h"
#include "stm32f103xx_i2c.h"
#include "stm32f103xx_rcc.h"


#define I2C_SR1_SB          (1U << 0)
#define I2C_SR1_ADDR        (1U << 1)
#define I2C_SR1_BTF         (1U << 2)
#define I2C_SR1_RXNE        (1U << 6)
#define I2C_SR1_TXE         (1U << 7)

#define I2C_CR1_PE          (1U << 0)
#define I2C_CR1_START       (1U << 8)
#define I2C_CR1_STOP        (1U << 9)
#define I2C_CR1_ACK         (1U << 10)


static void I2C_Start(I2C_RegDef_t *pI2Cx)
{
    pI2Cx->CR1 |= I2C_CR1_START;
}


static void I2C_Stop(I2C_RegDef_t *pI2Cx)
{
    pI2Cx->CR1 |= I2C_CR1_STOP;
}


static void I2C_ClearADDRFlag(I2C_RegDef_t *pI2Cx)
{
    volatile uint32_t dummy;

    dummy = pI2Cx->SR1;
    dummy = pI2Cx->SR2;

    (void)dummy;
}


void I2C_Init(I2C_Handle_t *pI2CHandle)
{
    if (pI2CHandle == 0)
    {
        return;
    }


    I2C_RegDef_t *pI2Cx = pI2CHandle->pI2Cx;


    if (pI2Cx == I2C1)
    {
        RCC_I2C1_CLK_EN();
    }
    else if (pI2Cx == I2C2)
    {
        RCC_I2C2_CLK_EN();
    }


    /*
     * STM32F103 Blue Pill:
     *
     * SYSCLK = 72 MHz
     * APB1   = 36 MHz
     */

    uint32_t pclk1 = 36000000U;
    uint32_t pclk1_mhz = 36U;


    /*
     * Disable I2C during configuration.
     */

    pI2Cx->CR1 = 0U;


    /*
     * APB1 frequency in MHz.
     */

    pI2Cx->CR2 = pclk1_mhz;


    /*
     * Own address.
     */

    pI2Cx->OAR1 =
        (1U << 14) |
        ((uint32_t)pI2CHandle->I2C_Config.OwnAddress & 0x7FU);


    /*
     * Default to 100 kHz.
     */

    if (pI2CHandle->I2C_Config.ClockHz == 0U)
    {
        pI2CHandle->I2C_Config.ClockHz = 100000U;
    }


    /*
     * Configure I2C clock.
     */

    if (pI2CHandle->I2C_Config.Mode == I2C_MODE_FAST)
    {
        pI2Cx->CCR =
            pclk1 /
            (3U * pI2CHandle->I2C_Config.ClockHz);

        pI2Cx->CCR |= (1U << 15);
    }
    else
    {
        pI2Cx->CCR =
            pclk1 /
            (2U * pI2CHandle->I2C_Config.ClockHz);

        pI2Cx->CCR &= ~(1U << 15);
    }


    /*
     * Maximum rise time.
     */

    pI2Cx->TRISE = pclk1_mhz + 1U;


    /*
     * ACK configuration.
     */

    if (pI2CHandle->I2C_Config.AckControl == I2C_ACK_ENABLE)
    {
        pI2Cx->CR1 |= I2C_CR1_ACK;
    }
    else
    {
        pI2Cx->CR1 &= ~I2C_CR1_ACK;
    }


    /*
     * Enable I2C.
     */

    pI2Cx->CR1 |= I2C_CR1_PE;
}


uint8_t I2C_Write(
    I2C_Handle_t *pI2CHandle,
    uint8_t SlaveAddress,
    const uint8_t *pData,
    uint16_t Length
)
{
    if ((pI2CHandle == 0) ||
        (pData == 0) ||
        (Length == 0U))
    {
        return I2C_ERROR;
    }


    I2C_RegDef_t *pI2Cx = pI2CHandle->pI2Cx;


    /*
     * Generate START.
     */

    I2C_Start(pI2Cx);


    while (!(pI2Cx->SR1 & I2C_SR1_SB))
    {
    }


    /*
     * Send slave address + write.
     */

    pI2Cx->DR =
        ((uint32_t)SlaveAddress << 1);


    /*
     * Wait for ADDR.
     */

    while (!(pI2Cx->SR1 & I2C_SR1_ADDR))
    {
    }


    I2C_ClearADDRFlag(pI2Cx);


    /*
     * Send data.
     */

    for (uint16_t i = 0U; i < Length; i++)
    {
        while (!(pI2Cx->SR1 & I2C_SR1_TXE))
        {
        }

        pI2Cx->DR = pData[i];
    }


    /*
     * Wait for final byte.
     */

    while (!(pI2Cx->SR1 & I2C_SR1_BTF))
    {
    }


    /*
     * Generate STOP.
     */

    I2C_Stop(pI2Cx);


    return I2C_OK;
}


uint8_t I2C_Read(
    I2C_Handle_t *pI2CHandle,
    uint8_t SlaveAddress,
    uint8_t *pData,
    uint16_t Length
)
{
    if ((pI2CHandle == 0) ||
        (pData == 0) ||
        (Length == 0U))
    {
        return I2C_ERROR;
    }


    I2C_RegDef_t *pI2Cx = pI2CHandle->pI2Cx;


    /*
     * Generate START.
     */

    I2C_Start(pI2Cx);


    while (!(pI2Cx->SR1 & I2C_SR1_SB))
    {
    }


    /*
     * Send slave address + read.
     */

    pI2Cx->DR =
        ((uint32_t)SlaveAddress << 1) | 1U;


    /*
     * Wait for ADDR.
     */

    while (!(pI2Cx->SR1 & I2C_SR1_ADDR))
    {
    }


    /*
     * Single byte reception.
     */

    if (Length == 1U)
    {
        pI2Cx->CR1 &= ~I2C_CR1_ACK;

        I2C_ClearADDRFlag(pI2Cx);

        I2C_Stop(pI2Cx);


        while (!(pI2Cx->SR1 & I2C_SR1_RXNE))
        {
        }


        pData[0] = (uint8_t)pI2Cx->DR;

        pI2Cx->CR1 |= I2C_CR1_ACK;

        return I2C_OK;
    }


    /*
     * Multiple byte reception.
     */

    I2C_ClearADDRFlag(pI2Cx);


    for (uint16_t i = 0U; i < Length; i++)
    {
        if (i == (Length - 1U))
        {
            pI2Cx->CR1 &= ~I2C_CR1_ACK;

            I2C_Stop(pI2Cx);
        }


        while (!(pI2Cx->SR1 & I2C_SR1_RXNE))
        {
        }


        pData[i] = (uint8_t)pI2Cx->DR;
    }


    pI2Cx->CR1 |= I2C_CR1_ACK;


    return I2C_OK;
}
