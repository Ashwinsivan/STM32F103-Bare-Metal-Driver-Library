#include "watchdog.h"
void IWDG_Init(uint8_t p,uint16_t r){IWDG->KR=0x5555;IWDG->PR=p&7;IWDG->RLR=r&0xFFF;IWDG->KR=0xAAAA;IWDG->KR=0xCCCC;}
void IWDG_Refresh(void){IWDG->KR=0xAAAA;}
void WWDG_Init(uint8_t p,uint8_t w){WWDG->CFR=((uint32_t)(p&7)<<11)|(w&0x7F);WWDG->CR=0x7F|0x80;}
void WWDG_Refresh(uint8_t v){WWDG->CR=0x80|(v&0x7F);}
