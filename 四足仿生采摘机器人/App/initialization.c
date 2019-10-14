/*=============================================================================*/
//file：  initialization.c
//brief：  初始化各部件
/*============================================================================*/
#include "common.h"
#include "include.h"
#include "dial_switch.h"
#include "i2c.h"
#include "time.h"
#include "buzzer.h"
#include "PS_two.h"

#define INT_COUNT  0xFFFF          //LPT 产生中断的计数次数

extern uint8 imgbuff[OV7725_EAGLE_SIZE];

void system_init()
{
     switch_init_all();
    // ov7725_eagle_init(imgbuff); //
     I2C_init();      //i2c初始化  i2c_init(I2C1,400*1000);山外库i2c初始化
     PS2_Init();
     time_init();
     uart_init (UART4, 115200);
    // uart_init (UART5, 115200);
     //buzzer_init();
    // buzzer_test();  
     //Ultrasonic_init();   //超声波测距初始化
}

