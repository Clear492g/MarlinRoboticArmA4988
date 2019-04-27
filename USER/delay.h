#ifndef DELAY_H
#define DELAY_H

#include "stm32f10x.h"   
//#include "Peripheral.h"

void delay_ms(u16 nms);
void Delay_Init(u8 SYSCLK);
void delay_us(u32 nus);

#endif

