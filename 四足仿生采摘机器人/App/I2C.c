#include "i2c.h"     
#include "include.h"
#define I2C_SDA PTE5
#define I2C_SCL PTE4
#define PCA9685_adrr 0x80//  +A4+A3+A2+A1+A0+w/r
#define PCA9685_SUBADR1 0x2
#define PCA9685_SUBADR2 0x3
#define PCA9685_SUBADR3 0x4
#define PCA9685_MODE1 0x0
#define PCA9685_PRESCALE 0xFE
#define LED0_ON_L 0x6
#define LED0_ON_H 0x7
#define LED0_OFF_L 0x8
#define LED0_OFF_H 0x9
#define ALLLED_ON_L 0xFA
#define ALLLED_ON_H 0xFB
#define ALLLED_OFF_L 0xFC
#define ALLLED_OFF_H 0xFD
#define SERVOMIN 105 // this is the ‘minimum’ pulse length count （out of 4096）//115
#define SERVOMAX 480 // this is the ‘maximum’ pulse length count （out of 4096）//590
#define SERVO000 110 //0度                   //130
#define SERVO180 430 //180度                 //520
#define SERVO80 255  //90度                    //284
#define SERVO110 340 //110度                   //340   

    void reset(void);
    void PCA9685_write(unsigned char address,unsigned char  date);
    unsigned char  PCA9685_read(unsigned char  address);
    
    void I2C_init(void);
    
    
    void switch_sda_in(void);
    void switch_sda_out(void);
    void I2C_SCLK(unsigned char c);
    unsigned char I2C_DATA_IN(void);
    void I2C_DATA_OUT(unsigned char c);
    void sdstart(void);
    void sdstop(void);
    unsigned char sdack(void);
    void sdnoack(void);
    unsigned char read_i2b(void);      
    void delay_i2(void);
    void write_i2b(unsigned char cc);
    unsigned char I2C_Read_i2(unsigned int addr);
    void I2C_Write_i2(unsigned int addr,unsigned char cc);   
    void I2C_test(void);
 
 unsigned char  PCA9685_read(unsigned char  address);
 unsigned char  PCA9685_read(unsigned char  address);
 void setPWMFreq(float freq);
 void setPWM(unsigned int num,unsigned int on,unsigned int off);
 void test_pca9685_write(void);
 
void I2C_init(void)
    {
    gpio_init (I2C_SCL, GPO,0);    //初始化 PTE0 管脚为输入
    gpio_init (I2C_SDA, GPI,0);  
	//DDRS_DDRS6=1;   //SCLK 
	//DDRS_DDRS7=0;   //SDA 	      
	//内部运行变量初始化 例如： EK EK1  EK2 
	//配置参数初始化     例如： KP KI KD       MYDOC 	      
    }
	      
void delay_i2(void)
    {
    int i;
    for(i=300;i>0;i--);
    } 
void switch_sda_in(void)
    {
    gpio_init (I2C_SDA, GPI,0); 
	//DDRS_DDRS7=0;   //SDA 
    }	
void switch_sda_out(void)
    {
    gpio_init (I2C_SDA, GPO,0); 
	//DDRS_DDRS7=1;   //SDA 
    }	
void I2C_SCLK(unsigned char c)
    {
    if(c==0)
	{
	gpio_set (I2C_SCL, 0);    // PTE0 管脚 输出 1
	}
    else
	{
	gpio_set (I2C_SCL, 1);
	}
    delay_i2();
    }
void I2C_DATA_OUT(unsigned char c)
    {               
    switch_sda_out();
    if(c==0x00)
	{
	gpio_set (I2C_SDA, 0);                  
	}
    else
	{
	gpio_set (I2C_SDA, 1);                    
	}       
    delay_i2();
    }

unsigned char I2C_DATA_IN(void)
    {
    unsigned char c;
    switch_sda_in();
    delay_i2();
    c=gpio_get (I2C_SDA);
    return(c);
    }
//=======================================================                
void sdstart(void)
    {	
    I2C_DATA_OUT(1);
    I2C_SCLK(1);
    I2C_DATA_OUT(0);
    I2C_SCLK(0);
    }
void sdstop(void)
    {
    I2C_SCLK(0);
    I2C_DATA_OUT(0);
    I2C_SCLK(1);
    I2C_DATA_OUT(1);
    }
unsigned char sdack(void)
    {
    unsigned char ctrl,c;
    c=I2C_DATA_IN();
    I2C_SCLK(0x1);
    c=I2C_DATA_IN();
    if(c==0x1)
	ctrl=0xff;
    else
	ctrl=0x0;		
    I2C_SCLK(0);
    I2C_DATA_OUT(0);
    return(ctrl);
    }	
void sdnoack(void)
    {
    I2C_DATA_IN();
    I2C_SCLK(1);
    I2C_SCLK(0);
    I2C_DATA_OUT(0);
    }
unsigned char read_i2b(void)
    {
    char c,ccb,c1;
    ccb=0;
    (void)I2C_DATA_IN();
    for(c=0;c<8;c++)
	{
	I2C_SCLK(1);
	c1=I2C_DATA_IN();
	if(c1==0x1)
            {
	    ccb=ccb|1;
	    }
	if(c!=7)
	    {
	    ccb=ccb<<1;
	    }
	I2C_SCLK(0);
	}
    I2C_DATA_OUT(0);
    return(ccb);
    }

void write_i2b(unsigned char cc)
{
	char c;
	for(c=0;c<8;c++)
		{
		I2C_SCLK(0);
		if(cc>=0x80)
			{
			I2C_DATA_OUT(1);
			}
		else
			{
			I2C_DATA_OUT(0);
			}
		cc=cc<<1;		
		I2C_SCLK(1);
		}
	I2C_SCLK(0);
	I2C_DATA_OUT(0);
}	
//--------------------------------------------------
void test_pca9685_write(void)
    {
      int i;
      reset();
      setPWMFreq(50);//设置50hz
     
       /*setPWM(0x00,0,110);//前左上280T
     delay_i2_MS();
     setPWM(0x00,0,340);//前左上280T
     delay_i2_MS();
     setPWM(0x00,0,270);//前左上280T
     delay_i2_MS();
     

       setPWM(0x00,0,280);//前左上280T
        delay_i2_MS();
        setPWM(0x01,0,280);//前左下280T--
        delay_i2_MS();
     
     
       setPWM(0x02,0,285); //前右上285T
       delay_i2_MS();
       setPWM(0x03,0,250);//前右下250T--
       delay_i2_MS();
       
       
       setPWM(0x04,0,285);//后左上285T
       delay_i2_MS();
       setPWM(0x05,0,240);//后左下240T--
       delay_i2_MS();
       
       setPWM(0x06,0,270);////后右上270T
       delay_i2_MS();
       setPWM(0x07,0,250);//后右下250T--
       delay_i2_MS();*/

     
   
   ///////////////////////////////////////////////////////
    
    }

void setPWMFreq(float freq)
    {
    unsigned int prescale,oldmode,newmode;
    float prescaleval;
    freq *= 0.92; // Correct for overshoot in the frequency setTIng
    prescaleval = 25000000;
    prescaleval /= 4096;
    prescaleval /= freq;
    prescaleval -= 1;
    prescale = floor(prescaleval + 0.5);
    oldmode = PCA9685_read(PCA9685_MODE1);
    newmode =(oldmode&0x7F) | 0x10; // sleep
    PCA9685_write(PCA9685_MODE1,newmode); // go to sleep
    PCA9685_write(PCA9685_PRESCALE,prescale); // set the prescaler
    PCA9685_write(PCA9685_MODE1,oldmode);
   // delayms(2);
    delay_i2();
    PCA9685_write(PCA9685_MODE1,oldmode | 0xa1);
    }
void setPWM(unsigned int num,unsigned int on,unsigned int off)
    {
    PCA9685_write(LED0_ON_L+4*num,on);
    PCA9685_write(LED0_ON_H+4*num,on>>8);
    PCA9685_write(LED0_OFF_L+4*num,off);
    PCA9685_write(LED0_OFF_H+4*num,off>>8);
    }
void reset(void)
    {
    PCA9685_write(PCA9685_MODE1,0x0);
    }
//--------------------------------------------------           
void PCA9685_write(unsigned char address,unsigned char  date)
{
    unsigned char c;
    PCA9685_write_x:
    sdstart();
    write_i2b(PCA9685_adrr);
    c=sdack();
    if(c==0xff)		        
	goto PCA9685_write_x;
    write_i2b(address);
    c=sdack();
    if(c==0xff)		        
	goto PCA9685_write_x;

    write_i2b(date);
    c=sdack();
    if(c==0xff)		        
	goto PCA9685_write_x;

    sdstop();

    }
unsigned char  PCA9685_read(unsigned char  address)
    {
    unsigned char  date,c;
    PCA9685_read_x:
    sdstart();
    write_i2b(PCA9685_adrr);
    c=sdack();
    if(c==0xff)		        
	goto PCA9685_read_x;

    write_i2b(address);
    c=sdack();
    if(c==0xff)		        
    goto PCA9685_read_x;
    sdstart();
    write_i2b(PCA9685_adrr|0x01);
    c=sdack();
    if(c==0xff)		       
        goto PCA9685_read_x;

    date=read_i2b();
    sdstop();
return date;

}
//--------------------------------------------------
//24C512
void I2C_Write_i2(unsigned int addr,unsigned char cc)
{
	union i2c{
			  unsigned int ii;
				unsigned char cc[2];
				}i2c_i;
	unsigned char cc_1,c;
	i2c_i.ii=addr;
	write_i2x:
	sdstart();			
	cc_1=0xa0;
		
	write_i2b(cc_1);
	c=sdack();
	if(c==0xff)		        
		goto write_i2x;

	cc_1=i2c_i.cc[1];		   
	write_i2b(cc_1);
		c=sdack();
	if(c==0xff)		          
		goto write_i2x;

	cc_1=i2c_i.cc[0];		    
	write_i2b(cc_1);
		c=sdack();
	if(c==0xff)		           
		goto write_i2x;

	write_i2b(cc);		   
		c=sdack();
	if(c==0xff)		            
		goto write_i2x;
	sdstop();			  
}
unsigned char I2C_Read_i2(unsigned int addr)
{
	union i2c{unsigned int ii;
		  unsigned char cc[2];}i2c_i;
	unsigned char cc_1,c;
	i2c_i.ii=addr;
	read_i2x:
	sdstart();			    

	cc_1=0xa0;
	
	write_i2b(cc_1);
		c=sdack();
	if(c==0xff)	    
		goto read_i2x;

	cc_1=i2c_i.cc[1];	   
	write_i2b(cc_1);
		c=sdack();
	if(c==0xff)	   
		goto read_i2x;

	cc_1=i2c_i.cc[0];	  
	write_i2b(cc_1);
		c=sdack();
	if(c==0xff)	  
		goto read_i2x;

	sdstart();			  

	cc_1=0xa1;
		
	write_i2b(cc_1);
		c=sdack();
	if(c==0xff)	   
		goto read_i2x;

	cc_1=read_i2b();	   
	sdnoack();				
	sdstop();		     
	return(cc_1);
}
	            
//=====================================================================
//==========测试I2C======
//=====================================================================
void I2C_test(void)
{
	unsigned int p,i;
	unsigned char cc;
	
	I2C_Write_i2(0x010,0x55);
	I2C_Write_i2(0x2010,0xaa);
		
	cc=I2C_Read_i2(0x10);       	
	cc=I2C_Read_i2(0x2010);
			
	cc=0x44;
	for(p=0x0300;p<0x0310;p++)
	{
		I2C_Write_i2(p,cc);
		cc=cc+3;
	}
	i=0;		
	for(p=0x0300;p<0x0310;p++)
	{
		cc=I2C_Read_i2(p);
		i++;
		i=i+cc;
	}	
	cc=0x50;
	for(p=0x2300;p<0x2310;p++)
	{
		I2C_Write_i2(p,cc);
		cc=cc+7;
	}
	i=0;		
	for(p=0x2300;p<0x2310;p++)
	{
		cc=I2C_Read_i2(p);
		i++;
		i=i+cc;
	}	
}
             