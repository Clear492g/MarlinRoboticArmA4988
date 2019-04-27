
#include "stm32f10x.h"
#include "stm32f10x.h"

void TIM2_NVIC_Configuration(void);
void TIM2_Configuration(void);
void TIM3_Interrupt_Init(u16 arr,u16 psc) ;
void TIM4_PWM_Init(u16 arr,u16 psc) ;

#define CLI()      __set_PRIMASK(1)		/* 关闭总中断 */  
#define SEI() __set_PRIMASK(0)				/* 开放总中断 */ 
