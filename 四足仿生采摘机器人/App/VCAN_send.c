#include "include.h"

/////////////////////////////////////////////////////////////////////////////////////
//数据拆分宏定义，在发送大于1字节的数据类型时，比如int16、float等，需要把数据拆分成单独字节进行发送
#define BYTE1(dwTemp)       ( *( (char *)(&dwTemp)	  ) )
#define BYTE0(dwTemp)       ( *( (char *)(&dwTemp) + 1) )
#define BYTE3(dwTemp)       ( *( (char *)(&dwTemp) + 2) )
#define BYTE2(dwTemp)       ( *( (char *)(&dwTemp) + 3) )

uint8 vcan_to_send[20];	//发送数据缓存


void VCAN_Send(uint16 a,uint16 b,uint16 c,uint16 d,uint16 e,uint16 f,uint16 g,uint16 h)   //头文件里也有
{
	
    uint32 _cnt=0;
    uint16 temp;
    
	vcan_to_send[_cnt++]=0X03;
	vcan_to_send[_cnt++]=0xFC;
    
    temp = a;
	vcan_to_send[_cnt++]=BYTE1(temp);
	vcan_to_send[_cnt++]=BYTE0(temp);
    
    temp = b;
	vcan_to_send[_cnt++]=BYTE1(temp);
	vcan_to_send[_cnt++]=BYTE0(temp);
    
    temp = c;
	vcan_to_send[_cnt++]=BYTE1(temp);
	vcan_to_send[_cnt++]=BYTE0(temp);
    
    temp = d;
	vcan_to_send[_cnt++]=BYTE1(temp);
	vcan_to_send[_cnt++]=BYTE0(temp);
    
    temp = e;
	vcan_to_send[_cnt++]=BYTE1(temp);
	vcan_to_send[_cnt++]=BYTE0(temp);
    
    temp = f;
	vcan_to_send[_cnt++]=BYTE1(temp);
	vcan_to_send[_cnt++]=BYTE0(temp);
    
    temp = g;
	vcan_to_send[_cnt++]=BYTE1(temp);
	vcan_to_send[_cnt++]=BYTE0(temp);
    
    
    temp = h;
	vcan_to_send[_cnt++]=BYTE1(temp);
	vcan_to_send[_cnt++]=BYTE0(temp);

	vcan_to_send[_cnt++]=0xFC;
	vcan_to_send[_cnt++]=0X03;	

    
    uart_putbuff (UART0, vcan_to_send, _cnt);
}