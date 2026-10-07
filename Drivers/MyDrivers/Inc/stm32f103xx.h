#ifndef STM32F103XX_H
#define STM32F103XX_H

#include <stdint.h>

/*
 * STM32F103C8T6
 *
 * Peripheral memory map
 */

#define PERIPH_BASE       0x40000000UL

#define APB1PERIPH_BASE   PERIPH_BASE
#define APB2PERIPH_BASE   0x40010000UL
#define AHBPERIPH_BASE    0x40020000UL


/* ============================================================
 * Peripheral base addresses
 * ============================================================ */

/* GPIO / AFIO / EXTI / RCC */

#define AFIO_BASEADDR     (APB2PERIPH_BASE + 0x0000UL)

#define EXTI_BASEADDR     (APB2PERIPH_BASE + 0x0400UL)

#define GPIOA_BASEADDR    (APB2PERIPH_BASE + 0x0800UL)
#define GPIOB_BASEADDR    (APB2PERIPH_BASE + 0x0C00UL)
#define GPIOC_BASEADDR    (APB2PERIPH_BASE + 0x1000UL)

#define RCC_BASEADDR      (AHBPERIPH_BASE + 0x1000UL)


/* USART */

#define USART1_BASEADDR   (APB2PERIPH_BASE + 0x3800UL)

#define USART2_BASEADDR   (APB1PERIPH_BASE + 0x4400UL)

#define USART3_BASEADDR   (APB1PERIPH_BASE + 0x4800UL)


/* SPI */

#define SPI1_BASEADDR     (APB2PERIPH_BASE + 0x3000UL)

#define SPI2_BASEADDR     (APB1PERIPH_BASE + 0x3800UL)


/* I2C */

#define I2C1_BASEADDR     (APB1PERIPH_BASE + 0x5400UL)

#define I2C2_BASEADDR     (APB1PERIPH_BASE + 0x5800UL)


/* Timers */

#define TIM1_BASEADDR     (APB2PERIPH_BASE + 0x2C00UL)

#define TIM2_BASEADDR     (APB1PERIPH_BASE + 0x0000UL)

#define TIM3_BASEADDR     (APB1PERIPH_BASE + 0x0400UL)

#define TIM4_BASEADDR     (APB1PERIPH_BASE + 0x0800UL)


/* ADC */

#define ADC1_BASEADDR     (APB2PERIPH_BASE + 0x2400UL)

#define ADC2_BASEADDR     (APB2PERIPH_BASE + 0x2800UL)


/* DMA */

#define DMA1_BASEADDR     (AHBPERIPH_BASE + 0x0000UL)

#define DMA2_BASEADDR     (AHBPERIPH_BASE + 0x0400UL)


/* Backup / power / RTC */

#define BKP_BASEADDR      (APB1PERIPH_BASE + 0x6C00UL)

#define PWR_BASEADDR      (APB1PERIPH_BASE + 0x7000UL)

#define RTC_BASEADDR      (APB1PERIPH_BASE + 0x2800UL)


/* Watchdogs */

#define WWDG_BASEADDR     (APB1PERIPH_BASE + 0x2C00UL)

#define IWDG_BASEADDR     (APB1PERIPH_BASE + 0x3000UL)


/* CAN */

#define CAN1_BASEADDR     (APB1PERIPH_BASE + 0x6400UL)


/* USB */

#define USB_BASEADDR      (APB1PERIPH_BASE + 0x5C00UL)


/* CRC */

#define CRC_BASEADDR      (AHBPERIPH_BASE + 0x3000UL)



/* ============================================================
 * GPIO register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;

} GPIO_RegDef_t;



/* ============================================================
 * AFIO register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t EVCR;
    volatile uint32_t MAPR;
    volatile uint32_t EXTICR[4];
    volatile uint32_t MAPR2;

} AFIO_RegDef_t;



/* ============================================================
 * EXTI register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;

} EXTI_RegDef_t;



/* ============================================================
 * RCC register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t AHBENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t AHBRSTR;
    volatile uint32_t CFGR2;
    volatile uint32_t CFGR3;
    volatile uint32_t CFGR4;

} RCC_RegDef_t;



/* ============================================================
 * USART register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t BRR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t CR3;
    volatile uint32_t GTPR;

} USART_RegDef_t;



/* ============================================================
 * SPI register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t CRCPR;
    volatile uint32_t RXCRCR;
    volatile uint32_t TXCRCR;
    volatile uint32_t I2SCFGR;
    volatile uint32_t I2SPR;

} SPI_RegDef_t;



/* ============================================================
 * I2C register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t OAR1;
    volatile uint32_t OAR2;
    volatile uint32_t DR;
    volatile uint32_t SR1;
    volatile uint32_t SR2;
    volatile uint32_t CCR;
    volatile uint32_t TRISE;
    volatile uint32_t FLTR;

} I2C_RegDef_t;



/* ============================================================
 * Timer register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMCR;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t CCMR1;
    volatile uint32_t CCMR2;
    volatile uint32_t CCER;
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
    volatile uint32_t RCR;
    volatile uint32_t CCR1;
    volatile uint32_t CCR2;
    volatile uint32_t CCR3;
    volatile uint32_t CCR4;
    volatile uint32_t BDTR;
    volatile uint32_t DCR;
    volatile uint32_t DMAR;

} TIM_RegDef_t;



/* ============================================================
 * ADC register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t SR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;

    volatile uint32_t SMPR1;
    volatile uint32_t SMPR2;

    volatile uint32_t JOFR1;
    volatile uint32_t JOFR2;
    volatile uint32_t JOFR3;
    volatile uint32_t JOFR4;

    volatile uint32_t HTR;
    volatile uint32_t LTR;

    volatile uint32_t SQR1;
    volatile uint32_t SQR2;
    volatile uint32_t SQR3;

    volatile uint32_t JSQR;

    volatile uint32_t JDR1;
    volatile uint32_t JDR2;
    volatile uint32_t JDR3;
    volatile uint32_t JDR4;

    volatile uint32_t DR;

} ADC_RegDef_t;



/* ============================================================
 * DMA channel register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t CCR;
    volatile uint32_t CNDTR;
    volatile uint32_t CPAR;
    volatile uint32_t CMAR;

} DMA_Channel_RegDef_t;



/* ============================================================
 * DMA controller register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t ISR;
    volatile uint32_t IFCR;

    DMA_Channel_RegDef_t CHANNEL[7];

} DMA_RegDef_t;



/* ============================================================
 * PWR register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t CSR;

} PWR_RegDef_t;



/* ============================================================
 * Backup register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t DR1;
    volatile uint32_t DR2;
    volatile uint32_t DR3;
    volatile uint32_t DR4;
    volatile uint32_t DR5;
    volatile uint32_t DR6;
    volatile uint32_t DR7;
    volatile uint32_t DR8;
    volatile uint32_t DR9;
    volatile uint32_t DR10;

    volatile uint32_t RTCCR;
    volatile uint32_t CR;
    volatile uint32_t CSR;

} BKP_RegDef_t;



/* ============================================================
 * RTC register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t CRH;
    volatile uint32_t CRL;

    volatile uint32_t PRLH;
    volatile uint32_t PRLL;

    volatile uint32_t DIVH;
    volatile uint32_t DIVL;

    volatile uint32_t CNTH;
    volatile uint32_t CNTL;

    volatile uint32_t ALRH;
    volatile uint32_t ALRL;

} RTC_RegDef_t;



/* ============================================================
 * Independent watchdog
 * ============================================================ */

typedef struct
{
    volatile uint32_t KR;
    volatile uint32_t PR;
    volatile uint32_t RLR;
    volatile uint32_t SR;

} IWDG_RegDef_t;



/* ============================================================
 * Window watchdog
 * ============================================================ */

typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t CFR;
    volatile uint32_t SR;

} WWDG_RegDef_t;



/* ============================================================
 * CRC register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t DR;
    volatile uint32_t IDR;
    volatile uint32_t CR;
    volatile uint32_t INIT;

} CRC_RegDef_t;



/* ============================================================
 * CAN register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t MCR;
    volatile uint32_t MSR;
    volatile uint32_t TSR;
    volatile uint32_t RF0R;
    volatile uint32_t RF1R;
    volatile uint32_t IER;
    volatile uint32_t ESR;
    volatile uint32_t BTR;

    volatile uint32_t RESERVED0[88];

    volatile uint32_t TI0R;
    volatile uint32_t TDT0R;
    volatile uint32_t TDL0R;
    volatile uint32_t TDH0R;

    volatile uint32_t RI0R;
    volatile uint32_t RDT0R;
    volatile uint32_t RDL0R;
    volatile uint32_t RDH0R;

    volatile uint32_t TI1R;
    volatile uint32_t TDT1R;
    volatile uint32_t TDL1R;
    volatile uint32_t TDH1R;

    volatile uint32_t RI1R;
    volatile uint32_t RDT1R;
    volatile uint32_t RDL1R;
    volatile uint32_t RDH1R;

    volatile uint32_t TI2R;
    volatile uint32_t TDT2R;
    volatile uint32_t TDL2R;
    volatile uint32_t TDH2R;

    volatile uint32_t RI2R;
    volatile uint32_t RDT2R;
    volatile uint32_t RDL2R;
    volatile uint32_t RDH2R;

} CAN_RegDef_t;



/* ============================================================
 * USB register definition
 * ============================================================ */

typedef struct
{
    volatile uint32_t EPnR[8];

    volatile uint32_t RESERVED[8];

    volatile uint32_t CNTR;
    volatile uint32_t ISTR;
    volatile uint32_t FNR;
    volatile uint32_t DADDR;
    volatile uint32_t BTABLE;

} USB_RegDef_t;



/* ============================================================
 * Peripheral pointers
 * ============================================================ */

#define GPIOA   ((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB   ((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC   ((GPIO_RegDef_t *)GPIOC_BASEADDR)

#define AFIO    ((AFIO_RegDef_t *)AFIO_BASEADDR)

#define EXTI    ((EXTI_RegDef_t *)EXTI_BASEADDR)

#define RCC     ((RCC_RegDef_t *)RCC_BASEADDR)


#define USART1  ((USART_RegDef_t *)USART1_BASEADDR)
#define USART2  ((USART_RegDef_t *)USART2_BASEADDR)
#define USART3  ((USART_RegDef_t *)USART3_BASEADDR)


#define SPI1    ((SPI_RegDef_t *)SPI1_BASEADDR)
#define SPI2    ((SPI_RegDef_t *)SPI2_BASEADDR)


#define I2C1    ((I2C_RegDef_t *)I2C1_BASEADDR)
#define I2C2    ((I2C_RegDef_t *)I2C2_BASEADDR)


#define TIM1    ((TIM_RegDef_t *)TIM1_BASEADDR)
#define TIM2    ((TIM_RegDef_t *)TIM2_BASEADDR)
#define TIM3    ((TIM_RegDef_t *)TIM3_BASEADDR)
#define TIM4    ((TIM_RegDef_t *)TIM4_BASEADDR)


#define ADC1    ((ADC_RegDef_t *)ADC1_BASEADDR)
#define ADC2    ((ADC_RegDef_t *)ADC2_BASEADDR)


#define DMA1    ((DMA_RegDef_t *)DMA1_BASEADDR)
#define DMA2    ((DMA_RegDef_t *)DMA2_BASEADDR)


#define PWR     ((PWR_RegDef_t *)PWR_BASEADDR)

#define BKP     ((BKP_RegDef_t *)BKP_BASEADDR)

#define RTC     ((RTC_RegDef_t *)RTC_BASEADDR)


#define IWDG    ((IWDG_RegDef_t *)IWDG_BASEADDR)

#define WWDG    ((WWDG_RegDef_t *)WWDG_BASEADDR)


#define CAN1    ((CAN_RegDef_t *)CAN1_BASEADDR)

#define USB     ((USB_RegDef_t *)USB_BASEADDR)

#define CRC     ((CRC_RegDef_t *)CRC_BASEADDR)



/* ============================================================
 * RCC APB2 enable bits
 * ============================================================ */

#define RCC_APB2ENR_AFIOEN       (1U << 0)

#define RCC_APB2ENR_IOPAEN       (1U << 2)
#define RCC_APB2ENR_IOPBEN       (1U << 3)
#define RCC_APB2ENR_IOPCEN       (1U << 4)

#define RCC_APB2ENR_ADC1EN       (1U << 9)
#define RCC_APB2ENR_ADC2EN       (1U << 10)

#define RCC_APB2ENR_TIM1EN       (1U << 11)

#define RCC_APB2ENR_SPI1EN       (1U << 12)

#define RCC_APB2ENR_USART1EN     (1U << 14)



/* ============================================================
 * RCC APB1 enable bits
 * ============================================================ */

#define RCC_APB1ENR_TIM2EN       (1U << 0)
#define RCC_APB1ENR_TIM3EN       (1U << 1)
#define RCC_APB1ENR_TIM4EN       (1U << 2)

#define RCC_APB1ENR_SPI2EN       (1U << 14)

#define RCC_APB1ENR_USART2EN     (1U << 17)
#define RCC_APB1ENR_USART3EN     (1U << 18)

#define RCC_APB1ENR_I2C1EN       (1U << 21)
#define RCC_APB1ENR_I2C2EN       (1U << 22)

#define RCC_APB1ENR_USBEN        (1U << 23)

#define RCC_APB1ENR_CAN1EN       (1U << 25)

#define RCC_APB1ENR_BKPEN        (1U << 27)

#define RCC_APB1ENR_PWREN        (1U << 28)



/* ============================================================
 * RCC AHB enable bits
 * ============================================================ */

#define RCC_AHBENR_DMA1EN        (1U << 0)

#define RCC_AHBENR_DMA2EN        (1U << 1)

#define RCC_AHBENR_CRCEN        (1U << 6)



/* ============================================================
 * NVIC registers
 * ============================================================ */

#define NVIC_ISER0              (*(volatile uint32_t *)0xE000E100UL)
#define NVIC_ISER1              (*(volatile uint32_t *)0xE000E104UL)

#define NVIC_ICER0              (*(volatile uint32_t *)0xE000E180UL)
#define NVIC_ICER1              (*(volatile uint32_t *)0xE000E184UL)



/* ============================================================
 * GPIO ports
 * ============================================================ */

#define GPIO_PORT_A             0
#define GPIO_PORT_B             1
#define GPIO_PORT_C             2



/* ============================================================
 * GPIO pins
 * ============================================================ */

#define GPIO_PIN_0              0
#define GPIO_PIN_1              1
#define GPIO_PIN_2              2
#define GPIO_PIN_3              3
#define GPIO_PIN_4              4
#define GPIO_PIN_5              5
#define GPIO_PIN_6              6
#define GPIO_PIN_7              7
#define GPIO_PIN_8              8
#define GPIO_PIN_9              9
#define GPIO_PIN_10             10
#define GPIO_PIN_11             11
#define GPIO_PIN_12             12
#define GPIO_PIN_13             13
#define GPIO_PIN_14             14
#define GPIO_PIN_15             15


#endif /* STM32F103XX_H */
