#include "gpio.h"
#include "rcc.h"
static void clk(GPIO_RegDef_t *p){if(p==GPIOA)RCC_GPIOA_CLK_EN();else if(p==GPIOB)RCC_GPIOB_CLK_EN();else if(p==GPIOC)RCC_GPIOC_CLK_EN();}
void GPIO_Init(GPIO_Handle_t *h){if(!h||h->GPIO_PinConfig.GPIO_PinNumber>15)return;clk(h->pGPIOx);uint8_t p=h->GPIO_PinConfig.GPIO_PinNumber;uint32_t v=h->GPIO_PinConfig.GPIO_PinMode;if(p<8){h->pGPIOx->CRL&=~(0xFU<<(p*4));h->pGPIOx->CRL|=v<<(p*4);}else{p-=8;h->pGPIOx->CRH&=~(0xFU<<(p*4));h->pGPIOx->CRH|=v<<(p*4);}if(h->GPIO_PinConfig.GPIO_PinMode==GPIO_MODE_INPUT_PULLUP)h->pGPIOx->ODR|=1U<<h->GPIO_PinConfig.GPIO_PinNumber;}
void GPIO_DeInit(GPIO_RegDef_t *p){if(p==GPIOA)RCC->APB2ENR|=(1U<<2);else if(p==GPIOB)RCC->APB2ENR|=(1U<<3);else if(p==GPIOC)RCC->APB2ENR|=(1U<<4);}
void GPIO_WritePin(GPIO_RegDef_t *p,uint8_t n,uint8_t v){if(v)p->BSRR=1U<<n;else p->BRR=1U<<n;}
uint8_t GPIO_ReadPin(GPIO_RegDef_t *p,uint8_t n){return (p->IDR>>n)&1U;}
void GPIO_TogglePin(GPIO_RegDef_t *p,uint8_t n){p->ODR^=1U<<n;}
