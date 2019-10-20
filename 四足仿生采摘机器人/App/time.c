#include "common.h"
#include "include.h"
#include "time.h"
#include "dial_switch.h"

  
void PIT0_IRQHandler(void);                    //定时器中断服务程序：舵机主函数及测试舵机
void PIT1_IRQHandler(void);
void time_init()
{
     pit_init_ms(PIT0,50);                                    //初始化PIT0，定时时间为： 3ms
     set_vector_handler(PIT0_VECTORn ,PIT0_IRQHandler);       //设置PIT0的中断服务函数为 PIT0_IRQHandler
     disable_irq(PIT0_IRQn);
}
/*! 
 *  @brief      PIT0中断服务函数
 *  @since      v5.0
 */
void PIT0_IRQHandler(void)
{
   
     
     PIT_Flag_Clear(PIT0);                        //清中断标志位
   
}




