#ifndef STM32F103XX_I2C_H
#define STM32F103XX_I2C_H

#include "stm32f103xx.h"


/* I2C modes */

#define I2C_MODE_STANDARD       0U
#define I2C_MODE_FAST           1U


/* ACK control */

#define I2C_ACK_ENABLE         1U
#define I2C_ACK_DISABLE        0U


/* Return values */

#define I2C_OK                 0U
#define I2C_ERROR              1U
#define I2C_TIMEOUT            2U


/* I2C configuration */

typedef struct
{
    uint32_t ClockHz;
    uint8_t  Mode;
    uint8_t  AckControl;
    uint8_t  OwnAddress;

} I2C_Config_t;


/* I2C handle */

typedef struct
{
    I2C_RegDef_t *pI2Cx;

    I2C_Config_t I2C_Config;

} I2C_Handle_t;


/* I2C initialization */

void I2C_Init(I2C_Handle_t *pI2CHandle);


/* I2C master transmit */

uint8_t I2C_Write(
    I2C_Handle_t *pI2CHandle,
    uint8_t SlaveAddress,
    const uint8_t *pData,
    uint16_t Length
);


/* I2C master receive */

uint8_t I2C_Read(
    I2C_Handle_t *pI2CHandle,
    uint8_t SlaveAddress,
    uint8_t *pData,
    uint16_t Length
);


#endif /* STM32F103XX_I2C_H */
