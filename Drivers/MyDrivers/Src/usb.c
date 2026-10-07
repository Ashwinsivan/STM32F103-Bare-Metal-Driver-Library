#include "usb.h"
#include "rcc.h"
void USB_Init(void){RCC_USB_CLK_EN();USB->CNTR=0;USB->ISTR=0;USB->CNTR=1;}
uint16_t USB_GetFrame(void){return (uint16_t)(USB->FNR&0x7FF);}
void USB_SetAddress(uint8_t a){USB->DADDR=(1U<<7)|(a&0x7F);}
