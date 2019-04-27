#include "stm32f10x.h"
#include "stm32f10x.h"
#include "bit.h"



#define motor1_step  PAOUT(10)
#define motor2_step  PAOUT(4)
#define motor3_step  PAOUT(5)


#define motor1_dir  PAOUT(0)
#define motor2_dir  PAOUT(1)
#define motor3_dir  PAOUT(9)

#define motor1_ms1  PBOUT(8)
#define motor2_ms1  PAOUT(7)
#define motor3_ms1  PBOUT(0)

#define motor1_ms2  PBOUT(1)
#define motor2_ms2  PBOUT(5)
#define motor3_ms2  PBOUT(9)

#define motor1_ms3  PBOUT(12)
#define motor2_ms3  PBOUT(13)
#define motor3_ms3  PBOUT(14)

#define motor1_en  PBOUT(15)
#define motor2_en  PBOUT(10)
#define motor3_en  PBOUT(11)

#define motor1_limit  PAIN(6)
#define motor2_limit  PBIN(6)
#define motor3_limit  PBIN(7)

//SLEEP?RES¶Ì½Ó   VDDÊä³ö3.3V  VMOT12V



void SN(int motornum );
void XM(int motornum );
void ZYB(int motornum );
void JDSZ(int motornum , int jd );
void FXSZ(int motornum , int dir );
void JSML(void);
void LIMIT (int motornum);
void SETX(int bs,int jd,int fx);
void SETY(int bs,int jd,int fx);
void SETZ(int bs,int jd,int fx);










