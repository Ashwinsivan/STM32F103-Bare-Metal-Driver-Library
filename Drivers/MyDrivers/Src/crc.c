#include "crc.h"
#include "rcc.h"
void CRC_Init(void){RCC_CRC_CLK_EN();}
uint32_t CRC_Calc(const uint32_t*d,uint32_t n){CRC_Init();CRC->CR=1;for(uint32_t i=0;i<n;i++)CRC->DR=d[i];return CRC->DR;}
