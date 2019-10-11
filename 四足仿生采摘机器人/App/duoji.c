#include "i2c.h"     
#include "include.h"
#include "tuxiang.h"
//////////////////    步长10    ///////////////////////////
#define ZQS_ZL 270
#define ZQD_HL ZQD_ZL+25
#define ZQX_HL ZQX_ZL-25
#define ZQD_ZL 278
#define ZQX_ZL 267
#define ZQD_QL ZQD_ZL-25
#define ZQX_QL ZQX_ZL+25
#define ZQX_SL ZQX_ZL-130

#define ZHS_ZL 270
#define ZHD_HL ZHD_ZL+25
#define ZHX_HL ZHX_ZL-25
#define ZHD_ZL 270
#define ZHX_ZL 252
#define ZHD_QL ZHD_ZL-25
#define ZHX_QL ZHX_ZL+25
#define ZHX_SL ZHX_ZL-130

#define YQS_ZL 250
#define YQD_HL YQD_ZL-25
#define YQX_HL YQX_ZL+25
#define YQD_ZL 256
#define YQX_ZL 270
#define YQD_QL YQD_ZL+25
#define YQX_QL YQX_ZL-25
#define YQX_SL YQX_ZL+130

#define YHS_ZL 290
#define YHD_HL YHD_ZL-25
#define YHX_HL YHX_ZL+25
#define YHD_ZL 270
#define YHX_ZL 257
#define YHD_QL YHD_ZL+25
#define YHX_QL YHX_ZL-25
#define YHX_SL YHX_ZL+130
int shuchuX0L[4][3]={{ZQS_ZL,ZQD_QL,ZQX_QL},{ZHS_ZL,ZHD_ZL,ZHX_ZL},{YQS_ZL,YQD_ZL,YQX_ZL},{YHS_ZL,YHD_QL,YHX_QL}};

int shuchuX1L[4][3]={{ZQS_ZL,ZQD_QL,ZQX_QL},{ZHS_ZL,ZHD_HL,ZHX_ZL},{YQS_ZL,YQD_HL,YQX_ZL},{YHS_ZL,YHD_QL,YHX_QL}};
int shuchuX2L[4][3]={{ZQS_ZL,ZQD_QL,ZQX_QL},{ZHS_ZL,ZHD_HL,ZHX_HL},{YQS_ZL,YQD_HL,YQX_HL},{YHS_ZL,YHD_QL,YHX_QL}};

int shuchuX3L[4][3]={{ZQS_ZL,ZQD_ZL,ZQX_QL},{ZHS_ZL,ZHD_HL,ZHX_HL},{YQS_ZL,YQD_HL,YQX_HL},{YHS_ZL,YHD_ZL,YHX_QL}};
int shuchuX4L[4][3]={{ZQS_ZL,ZQD_ZL,ZQX_ZL},{ZHS_ZL,ZHD_HL,ZHX_HL},{YQS_ZL,YQD_HL,YQX_HL},{YHS_ZL,YHD_ZL,YHX_ZL}};

int shuchuX5L[4][3]={{ZQS_ZL,ZQD_ZL,ZQX_ZL},{ZHS_ZL,ZHD_HL,ZHX_SL},{YQS_ZL,YQD_HL,YQX_SL},{YHS_ZL,YHD_ZL,YHX_ZL}};

int shuchuX6L[4][3]={{ZQS_ZL,ZQD_ZL,ZQX_ZL},{ZHS_ZL,ZHD_QL,ZHX_QL},{YQS_ZL,YQD_QL,YQX_QL},{YHS_ZL,YHD_ZL,YHX_ZL}};

int shuchuX7L[4][3]={{ZQS_ZL,ZQD_HL,ZQX_ZL},{ZHS_ZL,ZHD_QL,ZHX_QL},{YQS_ZL,YQD_QL,YQX_QL},{YHS_ZL,YHD_HL,YHX_ZL}};
int shuchuX8L[4][3]={{ZQS_ZL,ZQD_HL,ZQX_HL},{ZHS_ZL,ZHD_QL,ZHX_QL},{YQS_ZL,YQD_QL,YQX_QL},{YHS_ZL,YHD_HL,YHX_HL}};

int shuchuX9L[4][3]={{ZQS_ZL,ZQD_HL,ZQX_HL},{ZHS_ZL,ZHD_ZL,ZHX_QL},{YQS_ZL,YQD_ZL,YQX_QL},{YHS_ZL,YHD_HL,YHX_HL}};
int shuchuX10L[4][3]={{ZQS_ZL,ZQD_HL,ZQX_HL},{ZHS_ZL,ZHD_ZL,ZHX_ZL},{YQS_ZL,YQD_ZL,YQX_ZL},{YHS_ZL,YHD_HL,YHX_HL}};

int shuchuX11L[4][3]={{ZQS_ZL,ZQD_HL,ZQX_SL},{ZHS_ZL,ZHD_ZL,ZHX_ZL},{YQS_ZL,YQD_ZL,YQX_ZL},{YHS_ZL,YHD_HL,YHX_SL}};


////////////////////    步长15   ///////////////ok/////////////////////

#define ZQS_ZM 270
#define ZQD_HM ZQD_ZM+40//48
#define ZQX_HM ZQX_ZM-40//48
#define ZQD_ZM 278       //之前 278
#define ZQX_ZM 267
#define ZQD_QM ZQD_ZM-48
#define ZQX_QM ZQX_ZM+48
#define ZQX_SM ZQX_ZM-130

#define ZHS_ZM 270
#define ZHD_HM ZHD_ZM+48
#define ZHX_HM ZHX_ZM-48
#define ZHD_ZM 270
#define ZHX_ZM 252
#define ZHD_QM ZHD_ZM-48
#define ZHX_QM ZHX_ZM+48
#define ZHX_SM ZHX_ZM-130

#define YQS_ZM 250
#define YQD_HM YQD_ZM-40//48
#define YQX_HM YQX_ZM+40//48
#define YQD_ZM 256
#define YQX_ZM 270
#define YQD_QM YQD_ZM+48
#define YQX_QM YQX_ZM-48
#define YQX_SM YQX_ZM+130

#define YHS_ZM 290
#define YHD_HM YHD_ZM-48
#define YHX_HM YHX_ZM+48
#define YHD_ZM 270
#define YHX_ZM 257
#define YHD_QM YHD_ZM+48
#define YHX_QM YHX_ZM-48
#define YHX_SM YHX_ZM+130

int shuchuX0M[4][3]={{ZQS_ZM,ZQD_QM,ZQX_QM},{ZHS_ZM,ZHD_ZM,ZHX_ZM},{YQS_ZM,YQD_ZM,YQX_ZM},{YHS_ZM,YHD_QM,YHX_QM}};

int shuchuX1M[4][3]={{ZQS_ZM,ZQD_QM,ZQX_QM},{ZHS_ZM,ZHD_HM,ZHX_ZM},{YQS_ZM,YQD_HM,YQX_ZM},{YHS_ZM,YHD_QM,YHX_QM}};
int shuchuX2M[4][3]={{ZQS_ZM,ZQD_QM,ZQX_QM},{ZHS_ZM,ZHD_HM,ZHX_HM},{YQS_ZM,YQD_HM,YQX_HM},{YHS_ZM,YHD_QM,YHX_QM}};

int shuchuX3M[4][3]={{ZQS_ZM,ZQD_ZM,ZQX_QM},{ZHS_ZM,ZHD_HM,ZHX_HM},{YQS_ZM,YQD_HM,YQX_HM},{YHS_ZM,YHD_ZM,YHX_QM}};
int shuchuX4M[4][3]={{ZQS_ZM,ZQD_ZM,ZQX_ZM},{ZHS_ZM,ZHD_HM,ZHX_HM},{YQS_ZM,YQD_HM,YQX_HM},{YHS_ZM,YHD_ZM,YHX_ZM}};

int shuchuX5M[4][3]={{ZQS_ZM,ZQD_ZM,ZQX_ZM},{ZHS_ZM,ZHD_HM,ZHX_SM},{YQS_ZM,YQD_HM,YQX_SM},{YHS_ZM,YHD_ZM,YHX_ZM}};

int shuchuX6M[4][3]={{ZQS_ZM,ZQD_ZM,ZQX_ZM},{ZHS_ZM,ZHD_QM,ZHX_QM},{YQS_ZM,YQD_QM,YQX_QM},{YHS_ZM,YHD_ZM,YHX_ZM}};

int shuchuX7M[4][3]={{ZQS_ZM,ZQD_HM,ZQX_ZM},{ZHS_ZM,ZHD_QM,ZHX_QM},{YQS_ZM,YQD_QM,YQX_QM},{YHS_ZM,YHD_HM,YHX_ZM}};
int shuchuX8M[4][3]={{ZQS_ZM,ZQD_HM,ZQX_HM},{ZHS_ZM,ZHD_QM,ZHX_QM},{YQS_ZM,YQD_QM,YQX_QM},{YHS_ZM,YHD_HM,YHX_HM}};

int shuchuX9M[4][3]={{ZQS_ZM,ZQD_HM,ZQX_HM},{ZHS_ZM,ZHD_ZM,ZHX_QM},{YQS_ZM,YQD_ZM,YQX_QM},{YHS_ZM,YHD_HM,YHX_HM}};
int shuchuX10M[4][3]={{ZQS_ZM,ZQD_HM,ZQX_HM},{ZHS_ZM,ZHD_ZM,ZHX_ZM},{YQS_ZM,YQD_ZM,YQX_ZM},{YHS_ZM,YHD_HM,YHX_HM}};

int shuchuX11M[4][3]={{ZQS_ZM,ZQD_HM,ZQX_SM},{ZHS_ZM,ZHD_ZM,ZHX_ZM},{YQS_ZM,YQD_ZM,YQX_ZM},{YHS_ZM,YHD_HM,YHX_SM}};

/*///////////////////    步长20    ///////////////////////////
#define ZQS_ZH 270
#define ZQD_HH ZQD_ZH+60
#define ZQX_HH ZQX_ZH-60
#define ZQD_ZH 278
#define ZQX_ZH 267
#define ZQD_QH ZQD_ZH-60
#define ZQX_QH ZQX_ZH+60
#define ZQX_SH 120

#define ZHS_ZH 270
#define ZHD_HH ZHD_ZH+60
#define ZHX_HH ZHX_ZH-60
#define ZHD_ZH 270
#define ZHX_ZH 252
#define ZHD_QH ZHD_ZH-60
#define ZHX_QH ZHX_ZH+60
#define ZHX_SH 120

#define YQS_ZH 250
#define YQD_HH YQD_ZH-60
#define YQX_HH YQX_ZH+60
#define YQD_ZH 256
#define YQX_ZH 270
#define YQD_QH YQD_ZH+60
#define YQX_QH YQX_ZH-60
#define YQX_SH 400

#define YHS_ZH 290
#define YHD_HH YHD_ZH-60
#define YHX_HH YHX_ZH+60
#define YHD_ZH 270
#define YHX_ZH 257
#define YHD_QH YHD_ZH+60
#define YHX_QH YHX_ZH-60
#define YHX_SH 400
int shuchuX0H[4][3]={{ZQS_ZH,ZQD_QH,ZQX_QH},{ZHS_ZH,ZHD_ZH,ZHX_ZH},{YQS_ZH,YQD_ZH,YQX_ZH},{YHS_ZH,YHD_QH,YHX_QH}};

int shuchuX1H[4][3]={{ZQS_ZH,ZQD_QH,ZQX_QH},{ZHS_ZH,ZHD_HH,ZHX_ZH},{YQS_ZH,YQD_HH,YQX_ZH},{YHS_ZH,YHD_QH,YHX_QH}};
int shuchuX2H[4][3]={{ZQS_ZH,ZQD_QH,ZQX_QH},{ZHS_ZH,ZHD_HH,ZHX_HH},{YQS_ZH,YQD_HH,YQX_HH},{YHS_ZH,YHD_QH,YHX_QH}};

int shuchuX3H[4][3]={{ZQS_ZH,ZQD_ZH,ZQX_QH},{ZHS_ZH,ZHD_HH,ZHX_HH},{YQS_ZH,YQD_HH,YQX_HH},{YHS_ZH,YHD_ZH,YHX_QH}};
int shuchuX4H[4][3]={{ZQS_ZH,ZQD_ZH,ZQX_ZH},{ZHS_ZH,ZHD_HH,ZHX_HH},{YQS_ZH,YQD_HH,YQX_HH},{YHS_ZH,YHD_ZH,YHX_ZH}};

int shuchuX5H[4][3]={{ZQS_ZH,ZQD_ZH,ZQX_ZH},{ZHS_ZH,ZHD_HH,ZHX_SH},{YQS_ZH,YQD_HH,YQX_SH},{YHS_ZH,YHD_ZH,YHX_ZH}};

int shuchuX6H[4][3]={{ZQS_ZH,ZQD_ZH,ZQX_ZH},{ZHS_ZH,ZHD_QH,ZHX_QH},{YQS_ZH,YQD_QH,YQX_QH},{YHS_ZH,YHD_ZH,YHX_ZH}};

int shuchuX7H[4][3]={{ZQS_ZH,ZQD_HH,ZQX_ZH},{ZHS_ZH,ZHD_QH,ZHX_QH},{YQS_ZH,YQD_QH,YQX_QH},{YHS_ZH,YHD_HH,YHX_ZH}};
int shuchuX8H[4][3]={{ZQS_ZH,ZQD_HH,ZQX_HH},{ZHS_ZH,ZHD_QH,ZHX_QH},{YQS_ZH,YQD_QH,YQX_QH},{YHS_ZH,YHD_HH,YHX_HH}};

int shuchuX9H[4][3]={{ZQS_ZH,ZQD_HH,ZQX_HH},{ZHS_ZH,ZHD_ZH,ZHX_QH},{YQS_ZH,YQD_ZH,YQX_QH},{YHS_ZH,YHD_HH,YHX_HH}};
int shuchuX10H[4][3]={{ZQS_ZH,ZQD_HH,ZQX_HH},{ZHS_ZH,ZHD_ZH,ZHX_ZH},{YQS_ZH,YQD_ZH,YQX_ZH},{YHS_ZH,YHD_HH,YHX_HH}};

int shuchuX11H[4][3]={{ZQS_ZH,ZQD_HH,ZQX_SH},{ZHS_ZH,ZHD_ZH,ZHX_ZH},{YQS_ZH,YQD_ZH,YQX_ZH},{YHS_ZH,YHD_HH,YHX_SH}};
*/
//左 前  上A      大腿4    小腿5
//左 后  上8     大腿0     小腿1
//右 前  上B     大腿6     小腿7
//右 后  上9     大腿2     小腿3
//110-----430
//16  
int youqian_ddd,zuohou_ddd;
int youhou_ddd,zuoqian_ddd;
void qu_zhongzhi(void);
int *shuchu_shuju_p;

void song_zhi_x(void);
void song_zhi(void);
/*//////////////////////////////////步长10和15//////////////////////////////////////////////////////////////////
#define ZQS_ZH 270
#define ZQD_ZH 270
#define ZQX_ZH 270
#define ZQX_SH 145

#define ZHS_ZH 270
#define ZHD_ZH 270
#define ZHX_ZH 270
#define ZHX_SH 145

#define YQS_ZH 270
#define YQD_ZH 270
#define YQX_ZH 270
#define YQX_SH 405

#define YHS_ZH 270
#define YHD_ZH 270
#define YHX_ZH 270
#define YHX_SH 370*/
int shuchu_qian[4][3]={{ZQS_ZM,ZQD_QM,ZQX_QM},{ZHS_ZM,ZHD_QM,ZHX_QM},{YQS_ZM,YQD_QM,YQX_QM},{YHS_ZM,YHD_QM,YHX_QM}};//四脚向后
int shuchu_li[4][3]={{ZQS_ZM,ZQD_ZM,ZQX_ZM},{ZHS_ZM,ZHD_ZM,ZHX_ZM},{YQS_ZM,YQD_ZM,YQX_ZM},{YHS_ZM,YHD_ZM,YHX_ZM}};//中  
int shuchu_hou[4][3]={{ZQS_ZM,ZQD_HM,ZQX_HM},{ZHS_ZM,ZHD_HM,ZHX_HM},{YQS_ZM,YQD_HM,YQX_HM},{YHS_ZM,YHD_HM,YHX_HM}}; //四脚向前

int shuchuX0[4][3];

int shuchuX1[4][3];
int shuchuX2[4][3];

int shuchuX3[4][3];
int shuchuX4[4][3];

int shuchuX5[4][3];

int shuchuX6[4][3];

int shuchuX7[4][3];
int shuchuX8[4][3];

int shuchuX9[4][3];
int shuchuX10[4][3];

int shuchuX11[4][3];



char kongzhi_fangxiang;
float xuanzhuan_shuch;
void duoji_init(void);
void duoji_test(void);
void reset_tui(void);
void start_tui(void);
//-------------------------------------
int *out9685_p;
void shuchu_outxxx(void);
void delay_i2_MS(int count);
//--------------------------------------
float skewing_p;
float ek,ek1,ek2;
float KP,KD,KI;
float uk,uk1,Auk;
unsigned char kongzhi_mode;
int time,time1,time2;
void init_canshu_l(void);
void init_canshu_m(void);
void init_canshu_h(void);
void delay_i2_MS_Y(void);


void init_canshu_l(void)
    {
     int i,j;
     KP=24;KD=2.2;KI=0;   //  36.5   2.5    
     time=16; time1=8;   time2=6;//有3改为2       之前 8  4  3
     for(i=0;i<4;i++)
        {
        for(j=0;j<3;j++)
            {
            shuchuX0[i][j]=shuchuX0L[i][j];
            shuchuX1[i][j]=shuchuX1L[i][j];
            shuchuX2[i][j]=shuchuX2L[i][j];
            shuchuX3[i][j]=shuchuX3L[i][j];
            shuchuX4[i][j]=shuchuX4L[i][j];
            shuchuX5[i][j]=shuchuX5L[i][j];
            shuchuX6[i][j]=shuchuX6L[i][j];
            shuchuX7[i][j]=shuchuX7L[i][j];
            shuchuX8[i][j]=shuchuX8L[i][j];
            shuchuX9[i][j]=shuchuX9L[i][j];
            shuchuX10[i][j]=shuchuX10L[i][j];
            shuchuX11[i][j]=shuchuX11L[i][j];
            }
        }  
    }
void init_canshu_m(void)
    {
    KP=38.2;KD=2.8;KI=0;   //  37     2.7
    time=10;//8
    time1=8;//2
    time2=6;//有3改为2      之前  6  4  2
    int i,j;
     for(i=0;i<4;i++)
        {
        for(j=0;j<3;j++)
            {
            shuchuX0[i][j]=shuchuX0M[i][j];
            shuchuX1[i][j]=shuchuX1M[i][j];
            shuchuX2[i][j]=shuchuX2M[i][j];
            shuchuX3[i][j]=shuchuX3M[i][j];
            shuchuX4[i][j]=shuchuX4M[i][j];
            shuchuX5[i][j]=shuchuX5M[i][j];
            shuchuX6[i][j]=shuchuX6M[i][j];
            shuchuX7[i][j]=shuchuX7M[i][j];
            shuchuX8[i][j]=shuchuX8M[i][j];
            shuchuX9[i][j]=shuchuX9M[i][j];
            shuchuX10[i][j]=shuchuX10M[i][j];
            shuchuX11[i][j]=shuchuX11M[i][j];
            }
        }  
    }
/*void init_canshu_h(void)
    {
    KP=33;KD=3;KI=0;   //  36.5   2.5  
    time=10;
    time1=4;
    time2=3;//有3改为2  
    int i,j;
     for(i=0;i<4;i++)
        {
        for(j=0;j<3;j++)
            {
            shuchuX0[i][j]=shuchuX0H[i][j];
            shuchuX1[i][j]=shuchuX1H[i][j];
            shuchuX2[i][j]=shuchuX2H[i][j];
            shuchuX3[i][j]=shuchuX3H[i][j];
            shuchuX4[i][j]=shuchuX4H[i][j];
            shuchuX5[i][j]=shuchuX5H[i][j];
            shuchuX6[i][j]=shuchuX6H[i][j];
            shuchuX7[i][j]=shuchuX7H[i][j];
            shuchuX8[i][j]=shuchuX8H[i][j];
            shuchuX9[i][j]=shuchuX9H[i][j];
            shuchuX10[i][j]=shuchuX10H[i][j];
            shuchuX11[i][j]=shuchuX11H[i][j];
            }
        }  
    }*/
void init_canshu(void)
    {
     switch(kongzhi_mode)
        {
        case 'L':
              init_canshu_l();
              break;
        case 'M':
              init_canshu_m();
              break;
        /*default:
              init_canshu_h();
              break;*/
        }
    }
//float skewing_x,skewing_y;
void shujuchuli(void)
    {
     if(faxiang=='R')
        {
        if(skewing>1.5)
            {
            skewing=1.5;  
            }
        skewing_p=skewing;
        }
    else
        {
        if(skewing>1.5)
            {
            skewing=1.5;  
            }
        skewing_p=0.0-skewing;
        }
    }

void kongzhi_main(void)
    {
   //   KP=37;KD=2.7;KI=0;   //  36.5   2.5
      ek = skewing;
      Auk=KP*(ek-ek1)+KD*(ek-2*ek1+ek2);    //  KI*ek;
      uk=uk1+Auk; 
      ek2=ek1;
      ek1=ek;
      uk1=uk;
     
      if(uk<0)
        { 
         if(uk<-100)    //
            {
            uk=-100;  
            }
        kongzhi_fangxiang='R';      
        xuanzhuan_shuch=0-uk;
         }
        else
          {
           if(uk>100)
              {
               uk=100;  
              }  
        kongzhi_fangxiang='L';          
        xuanzhuan_shuch=uk;
        }
    } 
     
//--------------------------------------------------
void duoji_init(void)
      {
      ek=0; ek1=0; ek2=0;
      uk=0; uk1=0;
      init_canshu();
      xuanzhuan_shuch=0; 
      qu_zhongzhi();
      reset();
      setPWMFreq(50);//设置50hz 
  //---------------------20180725测试T--进门复位-----------------------//
      reset_tui();
      
     } 
void qu_zhongzhi(void)
    {
    zuoqian_ddd=shuchu_li[0][0]; 
    zuohou_ddd=shuchu_li[1][0];
    youqian_ddd=shuchu_li[2][0]; 
    youhou_ddd=shuchu_li[3][0];
    }

void song_zhi_x(void)
    {
    *shuchu_shuju_p=zuoqian_ddd; shuchu_shuju_p=shuchu_shuju_p+3;  
    *shuchu_shuju_p=zuohou_ddd;  shuchu_shuju_p=shuchu_shuju_p+3; 
    *shuchu_shuju_p=youqian_ddd; shuchu_shuju_p=shuchu_shuju_p+3;   
    *shuchu_shuju_p=youhou_ddd;  shuchu_shuju_p=shuchu_shuju_p+3;
    }
void song_zhi(void)
    {
      /////////////////////////////////10  15////////////////////
    shuchu_shuju_p=&shuchuX0[0][0];    song_zhi_x();
    shuchu_shuju_p=&shuchuX1[0][0];    song_zhi_x();
    shuchu_shuju_p=&shuchuX2[0][0];    song_zhi_x();
    shuchu_shuju_p=&shuchuX3[0][0];    song_zhi_x();
    shuchu_shuju_p=&shuchuX4[0][0];    song_zhi_x();
    shuchu_shuju_p=&shuchuX5[0][0];    song_zhi_x();
    shuchu_shuju_p=&shuchuX6[0][0];    song_zhi_x();
    shuchu_shuju_p=&shuchuX7[0][0];    song_zhi_x();
    shuchu_shuju_p=&shuchuX8[0][0];    song_zhi_x();
    shuchu_shuju_p=&shuchuX9[0][0];    song_zhi_x();
    shuchu_shuju_p=&shuchuX10[0][0];    song_zhi_x();
    shuchu_shuju_p=&shuchuX11[0][0];    song_zhi_x();

    }
//------------------------------------------------
void reset_tui(void)
    {
    out9685_p=&shuchu_li[0][0];
    shuchu_outxxx();
    delay_i2_MS(30); 
   // out9685_p=&shuchu_qian[0][0];
  //  shuchu_outxxx();
    //delay_i2_MS(30);  
    //out9685_p=&shuchu_hou[0][0];
    //shuchu_outxxx();
   // delay_i2_MS(30);  
  
    }
void shuju_caiji(void)
    {
    int i;
    //delay_i2_MS(2);
     /*for(i=0;i<3;i++)
          {
          tuxing_main_no();
          }*/
    tuxing_main();
    shujuchuli(); 
    
      kongzhi_main();
     if(faxiang=='L')
        {
        kongzhi_fangxiang='R';
        }
     else
        {
          kongzhi_fangxiang='L';  
        }
      
    }
void zuo_xuanzhuan(void)
    {
     youhou_ddd=shuchu_li[3][0];
     zuoqian_ddd=shuchu_li[0][0]; 
     if(kongzhi_fangxiang=='R')
         { 
          zuoqian_ddd=zuoqian_ddd+xuanzhuan_shuch;//加向右          
          youhou_ddd=youhou_ddd-xuanzhuan_shuch; //减向左
         }
    else
          {
          zuoqian_ddd=zuoqian_ddd-xuanzhuan_shuch;
          youhou_ddd=youhou_ddd+xuanzhuan_shuch;  
          }
     song_zhi();  
    }
void you_xuanzhuan(void)
    {
     youqian_ddd=shuchu_li[2][0];    
     zuohou_ddd=shuchu_li[1][0];
     if(kongzhi_fangxiang=='R')
         {       
          youqian_ddd=youqian_ddd+xuanzhuan_shuch;    //加向右      
          zuohou_ddd=zuohou_ddd-xuanzhuan_shuch;      //减向左
          }
     else
          {
          youqian_ddd=youqian_ddd-xuanzhuan_shuch;          
          zuohou_ddd=zuohou_ddd+xuanzhuan_shuch;
          }   
     song_zhi(); 
    }
void duiji_test(void)
     { 
     int i;
    
     //修改旋转值  左
     ///////////////////////////////////10  15////////////////////////////////////////////
     zuo_xuanzhuan();
     out9685_p=&shuchuX0[0][0];  shuchu_outxxx();   delay_i2_MS(time);//迈左腿
     
     //out9685_p=&shuchuX1[0][0];  shuchu_outxxx();   delay_i2_MS(time1);//弯右腿
     out9685_p=&shuchuX2[0][0];  shuchu_outxxx();   delay_i2_MS(time2);  //之前为time2
     //采集一次
    // shuju_caiji();
     
     //out9685_p=&shuchuX3[0][0];  shuchu_outxxx();   delay_i2_MS(time1); //立左腿
     out9685_p=&shuchuX4[0][0];  shuchu_outxxx();   delay_i2_MS(time2);
     
     out9685_p=&shuchuX5[0][0];  shuchu_outxxx();   delay_i2_MS(time); //收右腿
     //修改旋转值  右
     you_xuanzhuan();
     out9685_p=&shuchuX6[0][0];  shuchu_outxxx();   delay_i2_MS(time); //迈右腿
     //out9685_p=&shuchuX7[0][0];  shuchu_outxxx();   delay_i2_MS(time1); //左立蹬
     out9685_p=&shuchuX8[0][0];  shuchu_outxxx();   delay_i2_MS(time2);//之前为time2
     //采集一次  
    /* if(kongzhi_mode=='H')
          {
          shuju_caiji();
          }*/
     //out9685_p=&shuchuX9[0][0];  shuchu_outxxx();   delay_i2_MS(time1); //右立
     out9685_p=&shuchuX10[0][0];  shuchu_outxxx();   delay_i2_MS(time2);
     
     out9685_p=&shuchuX11[0][0];  shuchu_outxxx();   delay_i2_MS(time); //收左腿 
     
     }

void  shuchu_outxxx(void)
    {
    int ddd;
    /////////////////////////10  15///////////////////////////////////
    ddd=*out9685_p;setPWM(0x0a,0,ddd);out9685_p++;
    ddd=*out9685_p;setPWM(0x04,0,ddd);out9685_p++; 
    ddd=*out9685_p;setPWM(0x05,0,ddd);out9685_p++;
   
    ddd=*out9685_p;setPWM(0x08,0,ddd);out9685_p++;
    ddd=*out9685_p;setPWM(0x00,0,ddd);out9685_p++;
    ddd=*out9685_p;setPWM(0x01,0,ddd);out9685_p++;
    
    ddd=*out9685_p;setPWM(0x0b,0,ddd);out9685_p++;
    ddd=*out9685_p;setPWM(0x06,0,ddd);out9685_p++; 
    ddd=*out9685_p;setPWM(0x07,0,ddd);out9685_p++;
    
    ddd=*out9685_p;setPWM(0x09,0,ddd);out9685_p++; 
    ddd=*out9685_p;setPWM(0x02,0,ddd);out9685_p++;
    ddd=*out9685_p;setPWM(0x03,0,ddd);out9685_p++; 
    
    
    }

void delay_i2_MS_X(void)
    {
    int i,j,k;
    for(i=60000;i>0;i--)
        { 
         for(j=10;j>0;j--)//128
              k=i+j;
         
        }  
    }
void delay_i2_MS_Y(void)
    {
    int i,j,k;
    for(i=30000;i>0;i--)
        { 
         for(j=10;j>0;j--)//128
              k=i+j;
         
        }  
    }
void delay_i2_MS(int count)
    {
     int i;
     //tuxing_main_no();
     for(i=0;i<count;i++)
       {       
        delay_i2_MS_X();
        }
    } 


/*******************************机械臂调试*****************************************/




/**************************************

 对于抓手舵机，极限值为270，张开时给270减数



**************************************/








