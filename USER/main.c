#include "stm32f10x.h"    
#include "bit.h"
#include "usart1.h"
#include "delay.h"
#include "motor.h"
#include "misc.h"
#include "string.h"
#include "io.h"


u8 command_success =0;

int main(void)
{   
		u16 len;
		char *sp = NULL;
		
	
	
	  SystemInit();  /* ����ϵͳʱ��Ϊ72M */
		Delay_Init(72);
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
		uart_init(9600);
		GPIOINIT( );


		XM(1);XM(2);XM(3);
	
	
	

	 	while(1)
		{
				


				if(USART_RX_STA&0x8000)
				{					   

						len=USART_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
						JSML();


	
							if(command_success == 1)
						{
								
						command_success = 0;
							
						USART_SendData(USART2,'Z');
						while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART2,'Z');	
						while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);//�ȴ����ͽ���							
						USART_SendData(USART2,'o');
						while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART2,'k');
						while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART2,'\r');
						while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
						USART_SendData(USART2,'\n');
 
						}	
						USART_RX_STA=0;
		
				}			 

	
	}


}



