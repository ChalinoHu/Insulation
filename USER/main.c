#include "stm32f10x.h"
#include "lcd.h"
#include "touch.h"
#include "adc.h"
#include "delay.h"
#include "relay.h"
//C��
#include <stdio.h>
#include <math.h>


typedef struct
{
	u8 x;
	u8 y;
}ctnum;



void hardware_init()
{
	u8 n;
	delay_init();
	
	LCD_Init();
	
	POINT_COLOR = DARKBLUE;
	
	relay_init();

	Adc_Init();
	
//	tp_dev.init();   //������ʼ��

	
//�Զ����¾�Ե���װ��
	for(n=0;n<10;n++)
	 {
		 LCD_ShowHz_48(0+48*n,6,n,0);
	 }

}


int main()
{
	float value0,value1;
	u8 i = 0,j = 0;	
	
	
/***�������ദ��***/
	u8 cutnum1[16];
	u8 cutnum1_len = 0;
	u8 cut_num1 = 0;
	
	ctnum ctnums[240];
	
	u16 ctnums_len = 0;
	u16 ct_num = 0;
/******************/
	
	u8 continueflag = 0;
	
	
	
//	//����λ�ñ���
	u8 n =0, k = 0;
	hardware_init();

		//��鵥���߶Եض�·���
		for(i=1;i<17;i++)
		 {
		/**********************************/	 
			for(cut_num1=0;cut_num1< cutnum1_len;cut_num1++)
			{
				if(i==cutnum1[cut_num1++])
				{
					continueflag = 1;
					break;
				}
			}
			
			if(continueflag)
			{
				continueflag = 0;
				continue;
			}
		/************************************/	
			
			 
			 value0 = AD_con();
			 xihe(i);
			 delay_ms(1000);
			 value1 = AD_con();

			//�жϾ�Ե
			 if(fabs(value0-value1)>300)  
			 {
				 cutnum1[cutnum1_len++] = i;
				 
				 
	 	LCD_printf(10+167*k,60+n*40,256,32,32,"L%d--GND",i);	
		n++;
		if(n==5)
		{
			n = 0;
			k++;
		}		 
			 }
			 duankai(i);			 		 
			 delay_ms(1000);
		}
		 
		
		
		//���߲�����..
		for(i=1;i<17;i++)
		{
			
		/**********���Եض�·****************/	
			
			for(cut_num1=0;cut_num1< cutnum1_len;cut_num1++)
			{
				if(i== cutnum1[cut_num1]) 
				{
					continueflag = 1;
					break;
				}
			}
			if(continueflag)
			{
				continueflag =0;
				continue;
			}
			
	/**********************************/
			
			xihe(i);
			delay_ms(1000);
			value1 = AD_con();

			for(j=17;j<33;j++)
			{
	
		/********************���Եض�·***************/
				for(cut_num1=0; cut_num1<cutnum1_len;cut_num1++)
			{
				if(j==cutnum1[cut_num1]) 
				{
					continueflag = 1;
					break;
				}
			}
			if(continueflag)
			{
				continueflag =0;
				continue;
			}
		/*****************************************/

			/***************���������ݳ���******************/
				for(ct_num =0;ct_num<ctnums_len;ct_num++)
			{
				if((ctnums[ct_num].x ==i&&ctnums[ct_num].y==j)||(ctnums[ct_num].x=j&&ctnums[ct_num].y ==i) )
				{
					continueflag = 1;
					break;
				}
			}
			if(continueflag)
			{
				continueflag = 0;
				continue;
			}			
			
			/*******************************************/
			
				xihe(j);
							
				delay_ms(1000);
				value1 = AD_con();
				if(fabs(value0-value1)>300)
				{
					if(i!=j-16)
					{
							ctnums[ctnums_len].x =i;
							ctnums[ctnums_len++].y =j;
						
								LCD_printf(10+167*k,60+n*40,256,32,32,"L%d--L%d",i,j-16);	
								n++;
								if(n==5)
								{
									n = 0;
									k++;
								}	
					}
				}
				duankai(j);
			}
			duankai(i);
			delay_ms(1000);
		} 
		
		
		//�������
			for(n=10;n<14;n++)
	 {
		 LCD_ShowHz_48(48*(n-7),260,n,0);
	 }
	
	 while(1);
	
}

