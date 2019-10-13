#ifndef _I2C_H_
#define _I2C_H_
#include "common.h" 
#include "include.h" 

//512K= 512*1024×Ö½Ú   
    void I2C_init(void);    
    //=====================================
    void I2C_test(void);        
    //=====================================  
    //peizhi    
      //=====================================     
    unsigned char I2C_Read_i2(unsigned int addr);
    void I2C_Write_i2(unsigned int addr,unsigned char cc);
    //=====================================
   void test_pca9685_write(void);
   void setPWMFreq(float freq);
   void setPWM(unsigned int num,unsigned int on,unsigned int off);
   void reset(void);


    
#endif