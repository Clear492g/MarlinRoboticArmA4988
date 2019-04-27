#ifndef BITBAND_H
#define BITBAND_H

#include "bit.h"

#define Periph_BASE         0x40000000  // �������ַ 
#define Periph_BB_BASE      0x42000000  // �������������ַ 

/* Ӧ�ô���������*/
/* λ����Ӧ��ַ���㷽��
	Peripheral_BB_BASE+ƫ�Ƶ�ַ*32+4*λ��
*/

#define Periph_BB(PeriphAddr, BitNumber)    \
          *(__IO uint32_t *) (Periph_BB_BASE + ((PeriphAddr - Periph_BASE) << 5) + ((BitNumber) << 2))

/* ����GPIO����������������壬nΪbitλ�÷�ΧΪ0��15    */
/* ���Ƕ�GPIOA.15����������Ҫ��ʼ��GPIO��Ȼ��ʹ�÷����� */
/* ��GPIOA.15����͵�ƽ��   PAOutBit(15) = 0;           */
/* ��GPIOA.15����͵�ƽ��   PAOutBit(15) = 1;           */
/* ��ȡGPIOA.15����ĵ�ƽ�� data = PAInBit(15);         */
#define PAOUT(n)     Periph_BB((uint32_t)&GPIOA->ODR,n)  //��� 
#define PAIN(n)      Periph_BB((uint32_t)&GPIOA->IDR,n)  //���� 

#define PBOUT(n)     Periph_BB((uint32_t)&GPIOB->ODR,n)  //��� 
#define PBIN(n)     Periph_BB((uint32_t)&GPIOB->IDR,n)  //���� 

#define PCOUT(n)     Periph_BB((uint32_t)&GPIOC->ODR,n)  //��� 
#define PCIN(n)      Periph_BB((uint32_t)&GPIOC->IDR,n)  //���� 

#define PDOUT(n)     Periph_BB((uint32_t)&GPIOD->ODR,n)  //��� 
#define PDIN(n)      Periph_BB((uint32_t)&GPIOD->IDR,n)  //���� 

#define PEOUT(n)     Periph_BB((uint32_t)&GPIOE->ODR,n)  //��� 
#define PEIN(n)      Periph_BB((uint32_t)&GPIOE->IDR,n)  //���� 

#define PFOUT(n)     Periph_BB((uint32_t)&GPIOF->ODR,n)  //��� 
#define PFIN(n)      Periph_BB((uint32_t)&GPIOF->IDR,n)  //���� 

#define PGOUT(n)     Periph_BB((uint32_t)&GPIOG->ODR,n)  //��� 
#define PGIN(n)      Periph_BB((uint32_t)&GPIOG->IDR,n)  //���� 



/* �ڲ�SRAM������ ��32MB SRAM�������ķ���ӳ��Ϊ��1MB SRAMbit-band���ķ���(ʵ�ʴ�С����оƬ�й�) */
#define RAM_BASE            0x20000000  // �ڲ�SRAM����ַ  
#define RAM_BB_BASE         0x22000000  // �ڲ�SRAM����������ַ

#define SRAM_ResetBit_BB(VarAddr, BitNumber)    \
          (*(__IO uint32_t *) (RAM_BB_BASE | ((VarAddr - RAM_BASE) << 5) | ((BitNumber) << 2)) = 0)
   
#define SRAM_SetBit_BB(VarAddr, BitNumber)       \
          (*(__IO uint32_t *) (RAM_BB_BASE | ((VarAddr - RAM_BASE) << 5) | ((BitNumber) << 2)) = 1)

#define SRAM_GetBit_BB(VarAddr, BitNumber)       \
          (*(__IO uint32_t *) (RAM_BB_BASE | ((VarAddr - RAM_BASE) << 5) | ((BitNumber) << 2)))
					
					
#endif
