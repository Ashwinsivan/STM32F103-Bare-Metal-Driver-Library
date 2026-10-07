#include "can.h"
#include "rcc.h"
void CAN_Init(CAN_Handle_t*h){RCC_CAN1_CLK_EN();CAN_RegDef_t*c=h->pCANx;c->MCR=1;while(!(c->MSR&1)){}c->BTR=0;c->BTR|=(h->Config.SJW-1)&3;c->BTR|=((h->Config.BS1-1)&15)<<16;c->BTR|=((h->Config.BS2-1)&7)<<20;c->BTR|=((h->Config.Prescaler-1)&1023)<<0;c->MCR&=~1U;}
uint8_t CAN_Send(CAN_Handle_t*h,uint32_t id,const uint8_t*d,uint8_t n){CAN_RegDef_t*c=h->pCANx;if(n>8)return 1;while(c->TSR&(1U<<26)){}uint8_t mb=(c->TSR>>24)&3U;volatile uint32_t*tir=(volatile uint32_t*)&c->TI0R+mb*8;volatile uint32_t*tdtr=tir+1;volatile uint32_t*tdlr=tir+2;volatile uint32_t*tdhr=tir+3;*tdtr=n;uint32_t lo=0,hi=0;for(uint8_t i=0;i<n&&i<4;i++)lo|=(uint32_t)d[i]<<(8*i);for(uint8_t i=4;i<n;i++)hi|=(uint32_t)d[i]<<(8*(i-4));*tdlr=lo;*tdhr=hi;*tir=(id<<21)|1;return 0;}
