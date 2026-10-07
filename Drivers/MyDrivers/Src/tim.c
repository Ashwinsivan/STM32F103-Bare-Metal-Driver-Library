#include "tim.h"
#include "rcc.h"
static void en(TIM_RegDef_t*t){if(t==TIM1)RCC_TIM1_CLK_EN();else if(t==TIM2)RCC_TIM2_CLK_EN();else if(t==TIM3)RCC_TIM3_CLK_EN();else if(t==TIM4)RCC_TIM4_CLK_EN();}
void TIM_Init(TIM_Handle_t*h){TIM_RegDef_t*t=h->pTIMx;en(t);t->CR1=0;t->PSC=h->Config.Prescaler;t->ARR=h->Config.Period;t->EGR=1;if(h->Config.AutoReloadPreload)t->CR1|=1<<7;}
void TIM_Start(TIM_Handle_t*h){h->pTIMx->CR1|=1;}void TIM_Stop(TIM_Handle_t*h){h->pTIMx->CR1&=~1U;}void TIM_SetCounter(TIM_Handle_t*h,uint32_t n){h->pTIMx->CNT=n;}uint32_t TIM_GetCounter(TIM_Handle_t*h){return h->pTIMx->CNT;}
void TIM_SetCompare(TIM_Handle_t*h,uint8_t ch,uint16_t v){if(ch==1)h->pTIMx->CCR1=v;else if(ch==2)h->pTIMx->CCR2=v;else if(ch==3)h->pTIMx->CCR3=v;else if(ch==4)h->pTIMx->CCR4=v;}
void TIM_EnableUpdateIRQ(TIM_Handle_t*h){h->pTIMx->DIER|=1;}void TIM_DisableUpdateIRQ(TIM_Handle_t*h){h->pTIMx->DIER&=~1U;}
