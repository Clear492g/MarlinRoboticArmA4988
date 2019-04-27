#include "stm32f10x.h"   
#include "delay.h"
#include "motor.h"
#include "bit.h"
#include "usart1.h"	
#include "string.h"

extern u8 command_success;

void SN(int motornum )	//使能
{
	
			switch(motornum)
					{
						case 1 : motor1_en=0;delay_us(10);break;
						case 2 : motor2_en=0;delay_us(10);break;
						case 3 : motor3_en=0;delay_us(10);break;
						default : break;
					}


}

void XM(int motornum )	//休眠
{
				switch(motornum)
					{
						case 1 : motor1_en=1;delay_us(10);break;
						case 2 : motor2_en=1;delay_us(10);break;
						case 3 : motor3_en=1;delay_us(10);break;
						default : break;
					}



}





void ZYB(int motornum )	  //指定某个电机走一步
{
		switch(motornum)
					{
						case 1 : motor1_step=1;delay_us(200);motor1_step=0;delay_us(200); break; 
						case 2 : motor2_step=1;delay_us(200);motor2_step=0;delay_us(200);break; 
						case 3 : motor3_step=1;delay_us(200);motor3_step=0;delay_us(200); break; 
						default : break;
					}


}



void JDSZ(int motornum , int jd )//精度设置  1是1 16是1/16   
{
	
	
	if(motornum==1)
	{

				
			 switch(jd)
					{
						case 1 : motor1_ms1=0;delay_us(10);motor1_ms2=0;delay_us(10);motor1_ms3=0;delay_us(10); break; 
						case 2 : motor1_ms1=1;delay_us(10);motor1_ms2=0;delay_us(10);motor1_ms3=0;delay_us(10); break; 
						case 4 : motor1_ms1=0;delay_us(10);motor1_ms2=1;delay_us(10);motor1_ms3=0;delay_us(10); break; 
						case 8 : motor1_ms1=1;delay_us(10);motor1_ms2=1;delay_us(10);motor1_ms3=0;delay_us(10); break;
						case 16 :motor1_ms1=1;delay_us(10);motor1_ms2=1;delay_us(10);motor1_ms3=1;delay_us(10); break;
						default : break;
					}

	 }
	
	 if(motornum==2)
	{

				
			 switch(jd)
					{
						case 1 : motor2_ms1=0;delay_us(10);motor2_ms2=0;delay_us(10);motor2_ms3=0;delay_us(10); break; 
						case 2 : motor2_ms1=1;delay_us(10);motor2_ms2=0;delay_us(10);motor2_ms3=0;delay_us(10); break; 
						case 4 : motor2_ms1=0;delay_us(10);motor2_ms2=1;delay_us(10);motor2_ms3=0;delay_us(10); break; 
						case 8 : motor2_ms1=1;delay_us(10);motor2_ms2=1;delay_us(10);motor2_ms3=0;delay_us(10); break;
						case 16 : motor2_ms1=1;delay_us(10);motor2_ms2=1;delay_us(10);motor2_ms3=1;delay_us(10); break;
						default : break;
					}

	 }
	
	 if(motornum==3)
	{

				
			 switch(jd)
					{
						case 1 : motor3_ms1=0;delay_us(10);motor3_ms2=0;delay_us(10);motor3_ms3=0;delay_us(10); break; 
						case 2 : motor3_ms1=1;delay_us(10);motor3_ms2=0;delay_us(10);motor3_ms3=0;delay_us(10); break; 
						case 4 : motor3_ms1=0;delay_us(10);motor3_ms2=1;delay_us(10);motor3_ms3=0;delay_us(10); break; 
						case 8 : motor3_ms1=1;delay_us(10);motor3_ms2=1;delay_us(10);motor3_ms3=0;delay_us(10); break;
						case 16 : motor3_ms1=1;delay_us(10);motor3_ms2=1;delay_us(10);motor3_ms3=1;delay_us(10); break;
						default : break;
					}

	 }






}








void FXSZ(int motornum , int dir )   //方向设置
{
		if(motornum==1)
	{if(dir==1) motor1_dir=1;delay_us(10);
	 if(dir==0)  motor1_dir=0;delay_us(10);}
	
	if(motornum==2)
	{if(dir==1) motor2_dir=1;delay_us(10);
	 if(dir==0)  motor2_dir=0;delay_us(10);}
	
	 if(motornum==3)
	{if(dir==1) motor3_dir=1;delay_us(10);
	 if(dir==0)  motor3_dir=0;delay_us(10);}
	


}	






void SETX(int bs,int jd,int fx) //电机1
{
	int i;
	SN(1);
	JDSZ(1,jd);
	FXSZ(1,fx);

	for(i=0 ; i<bs ;i++)
	{
	   ZYB(1);
		delay_us(1000);
	}
	XM(1);
}

void SETY(int bs,int jd,int fx)//电机2
{
	int i;
	SN(2);
	JDSZ(2,jd);
	FXSZ(2,fx);

	for(i=0 ; i<bs ;i++)
	{
	   ZYB(2);
		delay_us(500);
	}
	XM(2);
}

void SETZ(int bs,int jd,int fx)//电机3
{
	int i;
	SN(3);
	JDSZ(3,jd);
	FXSZ(3,fx);

	for(i=0 ; i<bs ;i++)
	{
	   ZYB(3);
		delay_us(500);
	}
	XM(3);
}







void LIMIT (int motornum)
{ 
	
	int i;
	SN(motornum);
	JDSZ(motornum,4);
	FXSZ(motornum,1);

	for(i=0 ; i<8000 ;i++)
	{
	   ZYB(motornum);
		delay_us(500);
		if((motornum==1)&&(motor1_limit==0)) break;
		if((motornum==2)&&(motor2_limit==0)) break;
		if((motornum==3)&&(motor3_limit==0)) break;	
		
	}
	XM(motornum);



}















void   JSML(void)  //接受命令
{
	char *sp = NULL;
	int bs1=0 ; int bs2 =0; int bs3=0 ;
	int jd1=1 ; int jd2 =1; int jd3=1 ; 
	int fx1=0 ; int fx2=0 ; int fx3=0;
	int limit1=0;	int limit2=0;	int limit3=0;
	


	if(strstr((const char *)USART_RX_BUF,"@ZZ") != 0x00000000)	//@ZZ,0500,0900,2000,16,04,01,1,1,0#
			{
				
			  sp = strstr((const char *)USART_RX_BUF,"@ZZ");
				if((*(sp+3) == ',')&&(*(sp+8)== ',')&&(*(sp+13) == ',')&&(*(sp+18) == ',')&&(*(sp+21) == ',')
					&&(*(sp+24) == ',')&&(*(sp+27) == ',')&&(*(sp+29) == ',')&&(*(sp+31) == ',')&&(*(sp+33) == '#'))

								{
													
										bs1=(*(sp+4)-0x30)*1000+(*(sp+5)-0x30)*100+(*(sp+6)-0x30)*10+(*(sp+7)-0x30);
										bs2=(*(sp+9)-0x30)*1000+(*(sp+10)-0x30)*100+(*(sp+11)-0x30)*10+(*(sp+12)-0x30);
										bs3=(*(sp+14)-0x30)*1000+(*(sp+15)-0x30)*100+(*(sp+16)-0x30)*10+(*(sp+17)-0x30);
										
										jd1=(*(sp+19)-0x30)*10+(*(sp+20)-0x30);
										jd2=(*(sp+22)-0x30)*10+(*(sp+23)-0x30);
										jd3=(*(sp+25)-0x30)*10+(*(sp+26)-0x30);
										
										fx1=(*(sp+28)-0x30);
										fx2=(*(sp+30)-0x30);
										fx3=(*(sp+32)-0x30);
									
											SETX(bs1,jd1,fx1);
											SETY(bs2,jd2,fx2);
											SETZ(bs3,jd3,fx3);

								
								}
									
									
											command_success = 1;			
			}
			
			
	if(strstr((const char *)USART_RX_BUF,"@ZZINIT") != 0x00000000)//@ZZINIT,1,0,1  1为归位
			{
				
			  sp = strstr((const char *)USART_RX_BUF,"@ZZINIT");
				if((*(sp+7) == ',')&&(*(sp+9)== ',')&&(*(sp+11) == ',')&&(*(sp+13) == '#'))
					
								{
													
										limit1=(*(sp+8)-0x30);
										limit2=(*(sp+10)-0x30);
										limit3=(*(sp+12)-0x30);
									
										if(limit1==1)  LIMIT (1);
										if(limit2==1)  LIMIT (2);
										if(limit3==1)  LIMIT (3);

								}
									
									
											command_success = 1;			
			}


}	





