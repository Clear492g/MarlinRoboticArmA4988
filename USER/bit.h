#ifndef BITBAND_H
#define BITBAND_H

#include "bit.h"

#define Periph_BASE         0x40000000  // 外设基地址 
#define Periph_BB_BASE      0x42000000  // 外设别名区基地址 

/* 应该传常量参数*/
/* 位带对应地址计算方法
	Peripheral_BB_BASE+偏移地址*32+4*位数
*/

#define Periph_BB(PeriphAddr, BitNumber)    \
          *(__IO uint32_t *) (Periph_BB_BASE + ((PeriphAddr - Periph_BASE) << 5) + ((BitNumber) << 2))

/* 外设GPIO输入输出别名区定义，n为bit位置范围为0到15    */
/* 我们对GPIOA.15操作，首先要初始化GPIO，然后使用方法： */
/* 对GPIOA.15输出低电平：   PAOutBit(15) = 0;           */
/* 对GPIOA.15输出低电平：   PAOutBit(15) = 1;           */
/* 读取GPIOA.15输入的电平： data = PAInBit(15);         */
#define PAOUT(n)     Periph_BB((uint32_t)&GPIOA->ODR,n)  //输出 
#define PAIN(n)      Periph_BB((uint32_t)&GPIOA->IDR,n)  //输入 

#define PBOUT(n)     Periph_BB((uint32_t)&GPIOB->ODR,n)  //输出 
#define PBIN(n)     Periph_BB((uint32_t)&GPIOB->IDR,n)  //输入 

#define PCOUT(n)     Periph_BB((uint32_t)&GPIOC->ODR,n)  //输出 
#define PCIN(n)      Periph_BB((uint32_t)&GPIOC->IDR,n)  //输入 

#define PDOUT(n)     Periph_BB((uint32_t)&GPIOD->ODR,n)  //输出 
#define PDIN(n)      Periph_BB((uint32_t)&GPIOD->IDR,n)  //输入 

#define PEOUT(n)     Periph_BB((uint32_t)&GPIOE->ODR,n)  //输出 
#define PEIN(n)      Periph_BB((uint32_t)&GPIOE->IDR,n)  //输入 

#define PFOUT(n)     Periph_BB((uint32_t)&GPIOF->ODR,n)  //输出 
#define PFIN(n)      Periph_BB((uint32_t)&GPIOF->IDR,n)  //输入 

#define PGOUT(n)     Periph_BB((uint32_t)&GPIOG->ODR,n)  //输出 
#define PGIN(n)      Periph_BB((uint32_t)&GPIOG->IDR,n)  //输入 



/* 内部SRAM别名区 对32MB SRAM别名区的访问映射为对1MB SRAMbit-band区的访问(实际大小根据芯片有关) */
#define RAM_BASE            0x20000000  // 内部SRAM基地址  
#define RAM_BB_BASE         0x22000000  // 内部SRAM别名区基地址

#define SRAM_ResetBit_BB(VarAddr, BitNumber)    \
          (*(__IO uint32_t *) (RAM_BB_BASE | ((VarAddr - RAM_BASE) << 5) | ((BitNumber) << 2)) = 0)
   
#define SRAM_SetBit_BB(VarAddr, BitNumber)       \
          (*(__IO uint32_t *) (RAM_BB_BASE | ((VarAddr - RAM_BASE) << 5) | ((BitNumber) << 2)) = 1)

#define SRAM_GetBit_BB(VarAddr, BitNumber)       \
          (*(__IO uint32_t *) (RAM_BB_BASE | ((VarAddr - RAM_BASE) << 5) | ((BitNumber) << 2)))
					
					
#endif
