#include "common.h"
#include "include.h"

#define Trig  PTE4
#define Echo  PTE5

#define flag_wait  0XFFFFF

uint32 timevar;

void Ultrasonic_init()
{
       gpio_init(Trig,GPO,0);
       gpio_init(Echo,GPI,0);
}
void Ultrasonic_ranging()
{
        uint32 flag;
        flag = 0;
        gpio_set(Trig,1);               //产生触发脉冲
        pit_delay_us(PIT1,15);
        gpio_set(Trig,0);
      
        while(gpio_get(Echo) == 0);             //等待电平变高，低电平一直等待
        
        pit_time_start  (PIT0);                 //开始计时
        
        while(gpio_get(Echo) == 1)              //等待电平变低，高电平一直等待
        {
            flag++;
            if(flag >flag_wait)
            {
                break;
            }
        };             
        
        timevar = pit_time_get_us(PIT0);    //停止计时，获取计时时间
        if(flag <flag_wait)
        {
            timevar = timevar * 340 /2/1000;
                
            if(timevar > 5)
            {
                printf("\n\n距离为：%dmm",timevar); //打印延时时间
            }
        }
        VCAN_Send(timevar,2,3,4,5,6,7,8);
        //Delay_ms(10); 
        //DELAY_MS(1000); 
    }
