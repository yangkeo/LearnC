#include "PS_two.h"
#include "include.h"

float a_1 = 0;
float a_2 = 0;
float a_3 = 0;
float k_1 = 1.1;
float b_1 = 129;
float k_2 = 1.09;
float b_2 = 140;
float k_3 = 0.74;
float b_3 = 180;
unsigned int angle_1 = 0;
unsigned int angle_2 = 0;
unsigned int angle_3 = 0;
unsigned int out_d = 270;

unsigned int Handkey;
unsigned char Comd[2]={0x01,0x42};//开始命令
unsigned char Data[9]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}; //数据存储数组
unsigned int MASK[]={
    PSB_SELECT,
    PSB_L3,
    PSB_R3 ,
    PSB_START,
    PSB_PAD_UP,
    PSB_PAD_RIGHT,
    PSB_PAD_DOWN,
    PSB_PAD_LEFT,
    PSB_L2,
    PSB_R2,
    PSB_L1,
    PSB_R1 ,
    PSB_GREEN,
    PSB_RED,
    PSB_BLUE,
    PSB_PINK
	};	//按键值与键名




void PS2_Init(void)   //  手柄收受器端口接线 ！！！！！！！改！
{
  gpio_init (PS_DI, GPI,0);       //初始化 PTE7 管脚为输入
  gpio_init (PS_DO, GPO,0);       //初始化 PTE6 管脚为输出
  gpio_init (PS_CS, GPO,0);       //PTE8 输出   
  gpio_init (PS_CLK, GPO,0);       //PTE9 输出
}

void Mechanical_arm(void)
{
  int i = 0;
  //PS2_ClearData();   //清除缓存
  //PS2_ReadData();    //读数据
  a_1 = (( PS2_AnologData(PSS_RX) )*k_1+b_1);         
  angle_1 = (unsigned int)a_1;
  setPWM(0x0c,0,angle_1);
          
  a_2 = (( PS2_AnologData(PSS_RY) )*k_2+b_2);
  angle_2 = (unsigned int)a_2;
  setPWM(0x0d,0,angle_2);
  setPWM(0x0e,0,angle_2);
           
  a_3 = (( PS2_AnologData(PSS_LY) )*k_3+b_3);
  angle_3 = (unsigned int)a_3;
  if(angle_3 > 300)
  {
     angle_3 = 300;
  }
  setPWM(0x0f,0,angle_3);
  
  
  if(Data[3] == 0xfd)
  {
    setPWM(0x0f,0,180);
  }
  if(Data[3] == 0xfb)
  {
    setPWM(0x0f,0,290);
  }
  
  for(i = 0; i < 5; i++)
  {
    delay_PS();
  }
           
 
}



/*void Mechanical_arm(void)
{
  if(Data[3] == 0xfd)
  {
    setPWM(0x0f,0,180);
  }
  if(Data[3] == 0xfb)
  {
    setPWM(0x0f,0,290);
  }
}*/

//向遥控器发送命令
void PS2_Cmd(unsigned char CMD)
{
  volatile unsigned int ref=0x01;
  Data[1] = 0;
  for(ref=0x01;ref<0x0100;ref<<=1)
  {
    if(ref&CMD)
    {
       DO_H;                   //输出高电平
    }
    else DO_L;

    CLK_H;                    //时钟拉高
    delay_PS();
    CLK_L;
    delay_PS();
    CLK_H;
    if(DI)
     Data[1] = ref|Data[1];
   }
}


//判断是否为为红灯模式
unsigned char PS2_RedLight(void)
{
  CS_L;
  PS2_Cmd(Comd[0]);  //开始命令
  PS2_Cmd(Comd[1]);  //请求数据
  CS_H;
  if( Data[1] == 0X73)   
  {
    return 0 ;       //  红灯模式    
  }
  else 
  {
    return 1;        //  绿灯模式
  }

}


//读取遥控器数据
void PS2_ReadData(void)
{
  volatile unsigned char byte=0;
  volatile unsigned int ref=0x01;

  CS_L;

  PS2_Cmd(Comd[0]);  //开始命令
  PS2_Cmd(Comd[1]);  //请求数据

  for(byte=2;byte<9;byte++)          //开始接受数据
  {
    for(ref=0x01;ref<0x100;ref<<=1)
    {
      CLK_H;
      CLK_L;
      delay_PS();
      CLK_H;
      if(DI)
      {
        Data[byte] = ref|Data[byte];
      }      		      
    }
  delay_PS();
   }
  CS_H;	
}

//对读出来的ps2的数据进行处理     只处理了按键部分    默认数据是红灯模式    只有一个按键按下时
//按下为0， 未按下为1
unsigned char PS2_DataKey(void)
{
  unsigned char index;

  PS2_ClearData();
  PS2_ReadData();

  Handkey=(Data[4]<<8)|Data[3];     //这是16个按键  按下为0，  未按下为1
  for(index=0;index<16;index++)
  {	    
     if((Handkey&(1<<(MASK[index]-1)))==0)
     return index+1;
  }
   return 0;          //没有任何按键按下
}

//得到一个摇杆的模拟量  范围0~256
unsigned char PS2_AnologData(unsigned char button)
{
  int x = 0;
  x = Data[button];
  return Data[button];
}

//清除数据缓冲区
void PS2_ClearData()
{
  unsigned char i;
  for(i=0;i<9;i++)
  {
     Data[i]=0x00;
  }     
}



/********************************  读写函数 ************************************/
void delay_PS(void)
{
  int i;
  for(i=300;i>0;i--);
} 


unsigned char PS_DATA_IN(void)       //读遥控器输入
{
  unsigned char c = 0;
  c = gpio_get (PS_DI);
  return(c);
}

void PS_DATA_DO(unsigned char c)     //向遥控器发数据
{
  if(c==0x00)
  {
    gpio_set (PS_DO, 0);                  
  }
  else
  {
    gpio_set (PS_DO, 1);                  
  }
}

void PS_DATA_CS(unsigned char c)    //遥控器触发信号输出
{ 
  if(c==0x00)
  {
    gpio_set (PS_CS, 0);                  
  }
  else
  {
    gpio_set (PS_CS, 1);                    
  }
}

void PS_DATA_CLK(unsigned char c)    //时钟信号输出
{
  if(c==0x00)
  {
    gpio_set (PS_CLK, 0);                  
  }
  else
  {
    gpio_set (PS_CLK, 1);                    
  }
}

/*******************************************************************************/
