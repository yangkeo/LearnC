#include "common.h"
#include "include.h"
#include "initialization.h"
#include "tuxiang.h"
//-------------------------------------
int tuxing_hang_main;
int tuxing_hang;
void tuxing_main(void);
//-------------------------------------
//硬件函数
void tuxing_lubo(void);
//-------------------------------------
int tuxing_geshu;
int tuxing_leixing[7];
int tuxing_dizhi[7];
int tuxing_changdu[7];
int tuxing_zhuangtai;
void tuxing_hb_paiduan_main(void);
void tuxing_hb_paiduan_main_x(void);
void tuxing_hb_paiduan(void);
//----------------------------------------
char faxiang;
float skewing=0;          //偏移量
void tuxing_chuli_main(void);
void tuxing_chuli_main_1(void);		//
void tuxing_chuli_main_2(void);
void tuxing_chuli_main_3(void);
void tuxing_chuli_main_4(void);
void tuxing_chuli_main_5(void);
void tuxing_chuli_main_6(void);
void tuxing_chuli_main_7(void);
void jisuan_pianyi(int adr);
//-------------------------------------
 uint8 tuxing_xiuzheng_data;
//-------------------------------------

//========================================================================
//===**************************************************************=======
//===**************************************************************=======
//========================================================================
void tuxing_main(void)
	{
        //图像采集
        skewing = 0;
	ov7725_eagle_get_img();                                              //摄像头获取图像
        img_extract(img, imgbuff, OV7725_EAGLE_SIZE);
        tuxing_hang_main=25;
	tuxing_hang=tuxing_hang_main;
	tuxing_hb_paiduan_main();
	tuxing_chuli_main();
        img_condense(imgbuff, img, OV7725_image_SIZE);                  //将处理后的二维数组压缩成一维数组，方便上位机显示     
        vcan_sendimg(imgbuff, sizeof(imgbuff));  
	}
void tuxing_main_no(void)
        {
        ov7725_eagle_get_img();                                              //摄像头获取图像
        img_extract(img, imgbuff, OV7725_EAGLE_SIZE);
      
        }
//=======================================================================	
//=======================================================================
//=======================================================================
void tuxing_lubo(void)
	{
	unsigned char xxx;
	int i;
	for(i=0;i<160;i++)
		{
		xxx=img[tuxing_hang][i];
		if(i>2&&i<156)
			{
			if(xxx!=img[tuxing_hang][i-1]&&xxx!=img[tuxing_hang][i+1])
				{	
				if(xxx!=img[tuxing_hang][i-2]&&xxx!=img[tuxing_hang][i+2])
					{
					img[tuxing_hang][i]=img[tuxing_hang][i-2];
					}				
				}
			}
		}
	}
//=======================================================================	
//=======================================================================
//=======================================================================	
void tuxing_hb_paiduan_main(void)
	{
	tuxing_zhuangtai=0;
	tuxing_hb_paiduan_main_x();
	if(tuxing_geshu<2||tuxing_geshu>5)
		{
                //图像采集
		ov7725_eagle_get_img();                                              //摄像头获取图像
                img_extract(img, imgbuff, OV7725_EAGLE_SIZE);                
		tuxing_hb_paiduan_main_x();
		if(tuxing_geshu<2||tuxing_geshu>5)
			{
                        //图像采集  
			ov7725_eagle_get_img();                                              //摄像头获取图像
                        img_extract(img, imgbuff, OV7725_EAGLE_SIZE);
                        //图像修正
                        //SCCB_WriteByte(OV7725_CNST , 0X45);
			tuxing_hb_paiduan_main_x();
			}
		else
			{
			tuxing_zhuangtai=255;
			}
		}
	else
		{
		tuxing_zhuangtai=255;
		}
	}
//================================================
void tuxing_hb_paiduan_main_x(void)
	{
	tuxing_lubo();
	tuxing_hb_paiduan();
	if(tuxing_geshu<2||tuxing_geshu>5)
		{
		tuxing_hang=tuxing_hang_main-10;
		tuxing_lubo();
		tuxing_hb_paiduan();
		if(tuxing_geshu<2||tuxing_geshu>5)
			{	
			tuxing_hang=tuxing_hang_main+10;
			tuxing_lubo();
			tuxing_hb_paiduan();
			}
		}
	}
//============================
void tuxing_hb_paiduan(void)
	{
	int i;
	int hei_count,bai_count;
	int hei_ctrl,bai_ctrl;
	//---------------------
	tuxing_zhuangtai=0;
	tuxing_geshu=0;
	for(i=0;i<7;i++)
		{			
		tuxing_leixing[i]=255;
		tuxing_dizhi[i]=500;
		tuxing_changdu[i]=500;
		}
	//--------------------
	hei_count=0;
	bai_count=0;	
	hei_ctrl=0;
	bai_ctrl=0;
	for(i=0;i<160;i++)
		{	
		if(img[tuxing_hang][i]==0xff)
			{
			if(hei_ctrl==0xff)
				{				
				tuxing_changdu[tuxing_geshu-1]=i-tuxing_dizhi[tuxing_geshu-1]-2;
				}	
			hei_count=0;
			bai_count++;
			if(bai_ctrl==0x0)
				{	
				if(bai_count>=3)
					{
					tuxing_zhuangtai=0xff;
					bai_ctrl=0xff;					
					tuxing_leixing[tuxing_geshu]=1;
					tuxing_dizhi[tuxing_geshu]=i-2;							
					tuxing_geshu++;
					if(tuxing_geshu>5)
						{
						i=200;
						}
					hei_ctrl=0;				
					}
				}
			}
		else
			{
			if(bai_ctrl==0xff)
				{				
				tuxing_changdu[tuxing_geshu-1]=i-tuxing_dizhi[tuxing_geshu-1]-2;
				}			
			bai_count=0;
			hei_count++;
			if(hei_ctrl==0x0)
				{	
				if(hei_count>=3)
					{	
					tuxing_zhuangtai=0xff;
					hei_ctrl=0xff;					
					tuxing_leixing[tuxing_geshu]=0;
					tuxing_dizhi[tuxing_geshu]=i-2;							
					tuxing_geshu++;
					if(tuxing_geshu>5)
						{
						i=200;
						}
					bai_ctrl=0;					
					}
				}
			}
		}	
	tuxing_changdu[tuxing_geshu-1]=160-tuxing_dizhi[tuxing_geshu-1];			
	}
//=======================================================================	
//=======================================================================
//=======================================================================
//车 在线左面  负
void tuxing_chuli_main(void)
	{
	int ctrl_x;
	if(tuxing_zhuangtai==255)
		{
		if(tuxing_geshu==3)
			{
			if((tuxing_leixing[0]==1)&&(tuxing_leixing[1]==0)&&(tuxing_leixing[2]==1))
				{
				ctrl_x=1;	                //“白黑白（最佳）”情况
				}
			if((tuxing_leixing[0]==0)&&(tuxing_leixing[1]==1)&&(tuxing_leixing[2]==0))
				{
				ctrl_x=2;	               //“黑白黑（注意有两种）”情况
				}
			}

	        if(tuxing_geshu==4)
			{
                        if((tuxing_leixing[0]==1)&&(tuxing_leixing[1]==0)&&(tuxing_leixing[2]==1)&&(tuxing_leixing[3]==0))
		               {
			        ctrl_x=3;            //“白黑白黑（中线靠左）”情况
				}
                        if((tuxing_leixing[0]==0)&&(tuxing_leixing[1]==1)&&(tuxing_leixing[2]==0)&&(tuxing_leixing[3]==1))
				{
				ctrl_x=4;            //“黑白黑白（中线靠右）”情况
				}
			}
                if(tuxing_geshu==2)
                       {
                        if((tuxing_leixing[0]==0)&&(tuxing_leixing[1]==1)) //“黑白（冲出左侧赛道）”情况
                              {
                               ctrl_x=6; 
                              }
                        if((tuxing_leixing[0]==1)&&(tuxing_leixing[1]==0)) //“白黑（冲出右侧赛道）”情况
                              {
                               ctrl_x=7; 
                              }
                       }
		if(tuxing_geshu==5)
			{
                        ctrl_x=5;            //“黑白黑白黑”情况 
			}
			
		}
	//------------------------
	switch(ctrl_x)
		{
		case 1:
			//白 黑 白
			tuxing_chuli_main_1();
			break;
		case 2:
			tuxing_chuli_main_2();
			break;
		case 3:
			tuxing_chuli_main_3();
			break;
		case 4:
			tuxing_chuli_main_4();
			break;
		case 5:
			tuxing_chuli_main_5();
			break;
                case 6:
                        tuxing_chuli_main_6();
                        break;
                case 7:
                        tuxing_chuli_main_7();
		}
	}
//=======================================================================
//“白黑白（最佳）”情况
//黑线  10个线速 
void tuxing_chuli_main_1(void)
	{	
	int kkk;
	kkk=tuxing_dizhi[1]+tuxing_changdu[1]/2;
	jisuan_pianyi(kkk);	
	}
//“黑白黑（注意有两种）”情况
void tuxing_chuli_main_2(void)
	{
	 int kkk;
	 if(tuxing_changdu[0]<tuxing_changdu[2])
		{
                kkk=tuxing_dizhi[0]+tuxing_changdu[0]/2;
                jisuan_pianyi(kkk);	
		}
          else
		{
                kkk=tuxing_dizhi[2]+tuxing_changdu[2]/2;
                jisuan_pianyi(kkk);	
		}
	 }
void tuxing_chuli_main_3(void)
	{
	int kkk;
	kkk=tuxing_dizhi[1]+tuxing_changdu[1]/2;
	jisuan_pianyi(kkk);	
	}
void tuxing_chuli_main_4(void)
	{
	int kkk;
	kkk=tuxing_dizhi[2]+tuxing_changdu[2]/2;
	jisuan_pianyi(kkk);	
	}
void tuxing_chuli_main_5(void)
	{
	int kkk;
	kkk=tuxing_dizhi[2]+tuxing_changdu[2]/2;
	jisuan_pianyi(kkk);	
	}
void tuxing_chuli_main_6(void)
        {
         int i=0;
         int x=0;
         int y=0;
         for(i=0;i<160;i++)
            {
             if(img[tuxing_hang][i]==0)
                {
                 x++;
                }
            }
         y=160-x;
         if(x/y>1)
            {
             skewing=1.5;             
            }
         else
            {
             skewing=1.2;
            }
         faxiang='L';
        }
void tuxing_chuli_main_7(void)
        {
         int i=0;
         int x=0;
         int y=0;
         for(i=0;i<160;i++)
            {
             if(img[tuxing_hang][i]==255)
                {
                 x++;
                }
            }
         y=160-x;
         if(x/y>1)
            {
             skewing=1.2;             
            }
         else
            {
             skewing=1.5;
            }
         faxiang='R';
        }
//=================================
void jisuan_pianyi(int adr)
	{
	if(adr>80)
		{
		faxiang='L';
		skewing=adr-80;
		skewing=skewing/80;
		}
	else
		{
		faxiang='R';
		skewing=80-adr;
		skewing=skewing/80;
		}
	}
//========================================================================
//===**************************************************************=======
//===**************************************************************=======
//========================================================================