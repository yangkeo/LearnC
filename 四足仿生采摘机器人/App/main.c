/*=============================================================================
** file： main.c

** brief： 工程的主函数

// 1车 蓝  （慢车） 在前   

==============================================================================*/
#include "common.h"
#include "include.h"
#include "initialization.h"
#include "i2c.h"
#include "buzzer.h"
#include "time.h"
#include "dial_switch.h"
#include "tuxiang.h"
#include "duoji.h"
#include "PS_two.h"
/*==================================函数声明===================================*/
void  main(void);
uint8 imgbuff[OV7725_EAGLE_SIZE];                                             //定义存储接收图像的数组
uint8 img[OV7725_EAGLE_H][OV7725_EAGLE_W];

void main(void)   
    {   
     unsigned char ctrl,ddd;
     system_init();    
//-----------------
     Read_switch();
     ctrl=switch_state;
     kongzhi_mode=switch_state;
     ctrl=ctrl&0x07;    //    ctrl=ctrl&0x07;   // 1111 1111
    
     switch(ctrl)
        {
        case 0:      //0000
            ddd=0x30;
            break;
        case 1:     //0001
            ddd=0x35;
            break;
        case 2:      //0010
            ddd=0x40;
            break;
        case 3:       //0011
            ddd=0x45;
            break; 
        case 4:        //0100
            ddd=0x50;
            break;
        case 5:      //0101
            ddd=0x55;
            break;
        case 6:      //0110
            ddd=0x60;
            break;
        case 7:         // 0111
            ddd=0x90;
            break; 
        }
     kongzhi_mode=kongzhi_mode&0xc0;
     switch(kongzhi_mode)
        {
        case 0x00:
              kongzhi_mode='L';
              break;
        case 0xC0:
              kongzhi_mode='M';
              break;
       /* default:
              kongzhi_mode='H';
              break;*/
        }
      kongzhi_mode='M';    //强制
     duoji_init();
     SCCB_WriteByte(OV7725_CNST , ddd);
//-----------------
     EnableInterrupts;
     int i=0; 
 /**********************************/
    //enable_irq(PIT0_IRQn);                                                    //开定时器0中断
     
     setPWM(0x0c,0,270);
     setPWM(0x0d,0,280);
     setPWM(0x0e,0,280);
     setPWM(0x0f,0,270);
     
     while(1)  
         {
           PS2_ClearData();   //清除缓存
           PS2_ReadData();    //读数据
           
          // PS2_DataKey();
           
          switch(Data[1])
           {
             case 0X41:
               duiji_test();
               break;
             case 0X73: 
               Mechanical_arm();
               break;
           }      
        }
    }