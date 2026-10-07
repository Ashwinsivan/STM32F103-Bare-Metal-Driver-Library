#include "bkp.h"
#include "rcc.h"
void BKP_Write(uint8_t n,uint16_t v){RCC_BKP_CLK_EN();if(n>=1&&n<=10)*(&BKP->DR1+n-1)=v;}
uint16_t BKP_Read(uint8_t n){if(n<1||n>10)return 0;return (uint16_t)*(&BKP->DR1+n-1);}
