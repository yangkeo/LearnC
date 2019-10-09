#include "common.h"
#include "include.h"
//蜂鸣器端口配置
//========================================================
#define BUZZER_ON()               gpio_set (PTE10, 0); //响gpio_ctrl(PORTE,10,0);
#define BUZZER_OFF()              gpio_set (PTE10, 1); //不响 
/////////////////////////////////////////////////////////////////
void buzzer_on_off(uint8 num);   //蜂鸣器引脚取反
void buzzer_main(void);     //蜂鸣器中断控制函数
void buzzer_test(void);     //蜂鸣器测试函数，鸣一秒
void buzzer_init(void);    //蜂鸣器初始化函数
void buzzer_config(void);   //蜂鸣器配置函数
//////////////////////////////////////////////////////////////// 
uint8 buzzer_count;
/*========================================================================================================================
                             物理层                                                                                        
=========================================================================================================================*/
void buzzer_config(void) 
{
	gpio_init (PTE10,GPO,1); 
}
void buzzer_init(void) 
{
	buzzer_config();
	BUZZER_OFF(); 
	buzzer_count=0;
}
/*========================================================================================================================
                             应用层                                                                                      
=========================================================================================================================*/
///////////////////////////////////////////////////////////////////////////////
void buzzer_Delay(void)  //1ms 
{
	unsigned int xx,xxx;
	for(xx=0;xx<1;xx++)                       
	for(xxx=0;xxx<36000;xxx++);
}
//蜂鸣器测试函数，鸣一秒
void buzzer_test(void) 
{
	uint8 i;
	for(i=0;i<100;i++)
	{
		BUZZER_ON();
		buzzer_Delay(); 
		BUZZER_OFF();
		buzzer_Delay();
	}
}
/*//蜂鸣器引脚取反
void buzzer_on_off(uint8 num) 
{
    buzzer_count++;
	if(buzzer_count>=num)
	{
		gpio_reverse(PORTD,15);
		buzzer_count=0;
	}
}*/
void buzzer_main(void) 
{

	
}
  
  
  
  
  
  
  