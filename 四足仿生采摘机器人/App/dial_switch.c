//-------------------------------------------------------------------------*
// 文件名: dial_switch.c                                                        *
// 说  明: 8位拨码开关驱动函数文件                                         *
//-------------------------------------------------------------------------*
#include "common.h"
#include "include.h"
#include "MK60_gpio.h"
#include "dial_switch.h"

uint8 switch_state;       //8位拨码开关状态量
uint8 switch_1_8;         //1~8位拨码开关状态量                                             *
//-------------------------------------------------------------------------*
void switch_init_all(void)
{
	gpio_init(switch1,GPI,1);//初始化拨码开关1
	gpio_init(switch2,GPI,1);//初始化拨码开关2
	gpio_init(switch3,GPI,1);//初始化拨码开关3
	gpio_init(switch4,GPI,1);//初始化拨码开关4
	gpio_init(switch5,GPI,1);//初始化拨码开关5
	gpio_init(switch6,GPI,1);//初始化拨码开关6
	gpio_init(switch7,GPI,1);//初始化拨码开关7
	gpio_init(switch8,GPI,1);//初始化拨码开关8
	Read_switch();
}
//-------------------------------------------------------------------------*
//函数名: Read_switch                                                     
//功  能: 读取拨码开关值                                                  
//说  明：通过全局变量出口开关数值
//
//-------------------------------------------------------------------------*
void Read_switch(void)
{
	switch_state = 0x00;
	switch_state |= gpio_get(switch1);
	switch_state |= gpio_get(switch2)<<1;
	switch_state |= gpio_get(switch3)<<2;
	switch_state |= gpio_get(switch4)<<3;	
	switch_state |= gpio_get(switch5)<<4;
	switch_state |= gpio_get(switch6)<<5;
	switch_state |= gpio_get(switch7)<<6;
	switch_state |= gpio_get(switch8)<<7;
}