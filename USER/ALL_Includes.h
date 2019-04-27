/*************************************
		杭州光子物联网技术有限公司
		https://gzwelink.taobao.com
				2015.08.01
**************************************/

#ifndef  _ALL_Includes_H
#define  _ALL_Includes_H

#define uchar unsigned char
#define uint  unsigned int
#define INT8U unsigned char 
#define INT16U unsigned short
#define INT32U unsigned long

#include "stm32f10x_conf.h"
#include "delay.h"


extern void Init_lcd(void);
void display(INT8U *buff,INT8U Len);//显示函数
extern void LcdGpioConfig(void);

#endif


