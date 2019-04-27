/*************************************
		杭州光子物联网技术有限公司
		https://gzwelink.taobao.com
				2015.08.01
**************************************/

#include "ALL_Includes.h"
#include "delay.h"

u16 fac_ms;//全局变量
u8 fac_us;//全局变量
#define BIT(x)	(1 << (x))

/****************************************************
函数功能：ms级延时
输入参数：nms : 毫秒
输出参数：无
备    注：调用此函数前，需要初始化Delay_Init()函数
*****************************************************/							    
void delay_ms(u16 nms)
{
   	 SysTick->LOAD = (u32)fac_ms*nms-1;//加载时间值
	  SysTick->VAL = 1;//随便写个值，清除加载寄存器的值
	  SysTick->CTRL |= BIT(0);//SysTick使能
	  while(!(SysTick->CTRL&(1<<16)));//判断是否减到0
	  SysTick->CTRL &=~BIT(0);//关闭SysTick
}

/****************************************************
函数功能：延时初始化
输入参数：SYSCLK : 系统时钟(72)MHZ
输出参数：无
备    注：无
*****************************************************/
void Delay_Init(u8 SYSCLK)
{
     SysTick->CTRL &=~BIT(2);//选择外部时钟
	 SysTick->CTRL &=~BIT(1);//关闭定时器减到0后的中断请求
	 fac_us = SYSCLK/8;//计算好SysTick加载值
	 fac_ms = (u16)fac_us*1000;	 
}

/****************************************************
函数功能：us级延时
输入参数：nus : 微秒
输出参数：无
备    注：调用此函数前，需要初始化Delay_Init()函数
*****************************************************/		    								   
void delay_us(u32 nus)
{		
	  SysTick->LOAD = (u32)fac_us*nus-1;//加载时间值
	  SysTick->VAL = 1;//随便写个值，清除加载寄存器的值
	  SysTick->CTRL |= BIT(0);//SysTick使能
	  while(!(SysTick->CTRL&(1<<16)));//判断是否减到0
	  SysTick->CTRL &=~BIT(0);//关闭SysTick
}


