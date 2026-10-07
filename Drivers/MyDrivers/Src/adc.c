#include "adc.h"
#include "rcc.h"
static void ain(uint8_t c){GPIO_RegDef_t*g=(c<8)?GPIOA:(c<10?GPIOB:GPIOC);uint8_t p=(c<8)?c:(c<10?c-8:c-10);if(g==GPIOA)RCC_GPIOA_CLK_EN();else if(g==GPIOB)RCC_GPIOB_CLK_EN();else RCC_GPIOC_CLK_EN();if(p<8){g->CRL&=~(0xFU<<(p*4));}else{p-=8;g->CRH&=~(0xFU<<(p*4));}}
uint8_t ADC_Init(ADC_Handle_t*h){if(!h)return 1;ADC_RegDef_t*a=h->pADCx;if(a==ADC1)RCC_ADC1_CLK_EN();else if(a==ADC2)RCC_ADC2_CLK_EN();else return 1;RCC_ADC_SetClockDiv2();ain(h->Config.Channel);a->CR2=0;a->SQR1=0;a->SQR2=0;a->SQR3=h->Config.Channel;if(h->Config.Channel<=9){uint8_t s=h->Config.Channel*3;a->SMPR2&=~(7U<<s);a->SMPR2|=(uint32_t)(h->Config.SampleTime&7)<<s;}else{uint8_t s=(h->Config.Channel-10)*3;a->SMPR1&=~(7U<<s);a->SMPR1|=(uint32_t)(h->Config.SampleTime&7)<<s;}if(h->Config.Continuous)a->CR2|=1U<<1;a->CR2|=(7U<<17)|(1U<<20);a->CR2|=1;a->CR2|=1U<<3;a->CR2&=~(1U<<3);ADC_Calibrate(a);return 0;}
void ADC_Start(ADC_RegDef_t*a){a->CR2|=1U<<22;}
uint8_t ADC_Read(ADC_RegDef_t*a,uint16_t*v,uint32_t to){ADC_Start(a);while(!(a->SR&2U)){if(!to--)return 2;}*v=(uint16_t)(a->DR&0xFFF);return 0;}
void ADC_Stop(ADC_RegDef_t*a){a->CR2&=~1U;}
void ADC_Calibrate(ADC_RegDef_t*a){a->CR2|=1U<<2;while(a->CR2&(1U<<2)){}a->CR2|=1U<<3;while(a->CR2&(1U<<3)){}}
