#include "systick.h"
#include "stm32f1xx.h"


#define SYST_CSR    (*(volatile uint32_t *)0xE000E010UL)
#define SYST_RVR    (*(volatile uint32_t *)0xE000E014UL)
#define SYST_CVR    (*(volatile uint32_t *)0xE000E018UL)


static volatile uint32_t ticks = 0U;


void SysTick_Init(uint32_t hz)
{
    if (hz == 0U)
    {
        hz = 1000U;
    }


    uint32_t load =
        (SystemCoreClock / hz) - 1U;


    SYST_RVR = load;

    SYST_CVR = 0U;


    /*
     * CLKSOURCE = processor clock
     * TICKINT   = enable interrupt
     * ENABLE    = enable SysTick
     */

    SYST_CSR = 7U;
}


void SysTick_Handler(void)
{
    ticks++;
}


uint32_t SysTick_GetTick(void)
{
    return ticks;
}


void SysTick_DelayMs(uint32_t ms)
{
    uint32_t start = ticks;


    while ((ticks - start) < ms)
    {
    }
}
