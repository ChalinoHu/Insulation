/***********

32个电磁继电器 需要32个引脚控制


PA------1 2 3 4 5 6 7     11 12 
PF------0 1 2 3 4 5 6 7
PB------3 56 7 8 9 12 13 14 15
PC------ 1 2          3 6 7 8 9 0
PG------ 1 2 3 4 5 6  8 9 10 11  13 14 15

***********/


#include "relay.h"
#include "stm32f10x_gpio.h"




/************
函数说明：电磁继电器引脚的初始化
************/
void relay_init()
{
     
    
	GPIO_InitTypeDef GPIO_InitStructure1,GPIO_InitStructure2,GPIO_InitStructure3,GPIO_InitStructure4;
 	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF|RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOG|RCC_APB2Periph_GPIOB,ENABLE);
    
	GPIO_InitStructure1.GPIO_Pin  = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_11|GPIO_Pin_12;
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_2MHz;
 	GPIO_Init(GPIOA, &GPIO_InitStructure1);
  GPIO_ResetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_11|GPIO_Pin_12);

	
	GPIO_InitStructure2.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure2.GPIO_Mode = GPIO_Mode_Out_PP;	
	GPIO_InitStructure2.GPIO_Speed = GPIO_Speed_2MHz;	
	GPIO_Init(GPIOF, &GPIO_InitStructure2);
  GPIO_ResetBits(GPIOF,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
  

  
  GPIO_InitStructure3.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure3.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure3.GPIO_Speed =GPIO_Speed_2MHz;
	GPIO_Init(GPIOG,&GPIO_InitStructure3);
	GPIO_ResetBits(GPIOG,GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
	
	
	
	
	
	GPIO_InitStructure4.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_15;
	GPIO_InitStructure4.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure4.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure4);
	GPIO_ResetBits(GPIOB,GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_15);
}



void xihe(u8 num)
{
	switch(num)
	{
		case 1:J1_ON;break;
		case 2:J2_ON;break;
		case 3:J3_ON;break;
		case 4:J4_ON;break;
		case 5:J5_ON;break;
		case 6:J6_ON;break;
		case 7:J7_ON;break;
		case 8:J8_ON;break;
		case 9:J9_ON;break;
		case 10:J10_ON;break;
		case 11:J11_ON;break;
		case 12:J12_ON;break;
		case 13:J13_ON;break;
		case 14:J14_ON;break;
		case 15:J15_ON;break;
		case 16:J16_ON;break;
		case 17:J17_ON;break;
		case 18:J18_ON;break;
		case 19:J19_ON;break;
		case 20:J20_ON;break;
		case 21:J21_ON;break;
		case 22:J22_ON;break;
		case 23:J23_ON;break;
		case 24:J24_ON;break;
		case 25:J25_ON;break;
		case 26:J26_ON;break;
		case 27:J27_ON;break;
		case 28:J28_ON;break;
		case 29:J29_ON;break;
		case 30:J30_ON;break;
		case 31:J31_ON;break;
		case 32:J32_ON;break;
		
		default: break;
	}
}

void duankai(u8 num)
{
	switch(num)
	{
		case 1:J1_OFF;break;
		case 2:J2_OFF;break;
		case 3:J3_OFF;break;
		case 4:J4_OFF;break;
		case 5:J5_OFF;break;
		case 6:J6_OFF;break;
		case 7:J7_OFF;break;
		case 8:J8_OFF;break;
		case 9:J9_OFF;break;
		case 10:J10_OFF;break;
		case 11:J11_OFF;break;
		case 12:J12_OFF;break;
		case 13:J13_OFF;break;
		case 14:J14_OFF;break;
		case 15:J15_OFF;break;
		case 16:J16_OFF;break;
		case 17:J17_OFF;break;
		case 18:J18_OFF;break;
		case 19:J19_OFF;break;
		case 20:J20_OFF;break;
		case 21:J21_OFF;break;
		case 22:J22_OFF;break;
		case 23:J23_OFF;break;
		case 24:J24_OFF;break;
		case 25:J25_OFF;break;
		case 26:J26_OFF;break;
		case 27:J27_OFF;break;
		case 28:J28_OFF;break;
		case 29:J29_OFF;break;
		case 30:J30_OFF;break;
		case 31:J31_OFF;break;
		case 32:J32_OFF;break;
		
		default: break;
	}
}
