#include "stm32f103xx.h"
#include "stm32f103xx_rcc.h"
#include "stm32f103xx_gpio.h"
#include "systick.h"

int main(void)
{
    GPIO_Handle_t LED;

    /* 1. Enable GPIOA clock */
    RCC_GPIOA_CLK_EN();

    /* 2. Configure PA0 as push-pull output */
    LED.pGPIOx = GPIOA;

    LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_0;
    LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT_PP_2MHZ;

    GPIO_Init(&LED);

    /* 3. Initialize SysTick */
    SysTick_Init(1000);

    /* 4. Initial LED state = OFF */
    GPIO_WritePin(GPIOA,
                  GPIO_PIN_0,
                  GPIO_PIN_RESET);

    /* 5. Blink LED using SysTick delay */
    while (1)
    {
        GPIO_TogglePin(GPIOA, GPIO_PIN_0);

        SysTick_DelayMs(500);
    }

    return 0;
}
