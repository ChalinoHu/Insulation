
#include "stm32f10x_tim.h"
#include "hwtimer.h"
#include "lcd.h"
#include "adc.h"
#include "touch.h"

int count = 0;
int value;
u8 test_flag = 0;


void TIM3_Int_Init(void)
{
 
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟使能
	
	
	
	//定时器TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = 199; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =7199; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断,允许更新中断

	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器


	TIM_Cmd(TIM3, ENABLE);  //使能TIMx				//根据合适情况打开或者关闭定时器	 
}



//25ms检测上升沿高电平
void TIM4_Int_Init(void)
{
 
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); //时钟使能
	
	
	//定时器TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = 249; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =7199; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断,允许更新中断

	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器
	TIM_Cmd(TIM4, ENABLE);  //使能TIMx				//根据合适情况打开或者关闭定时器	 
}




//10ms采集一次屏幕状态
void  TIM3_IRQHandler(void)   //TIM3中断
{

			                   
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  	//检查TIM3更新中断发生与否
		{
			TIM_ClearITPendingBit(TIM3, TIM_IT_Update  ); 	 //清除TIMx更新中断标志 
             tp_dev.scan(0);	
				if((tp_dev.sta))     //确定按下状态    
				{
					
					if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)//判断按下的位置
					{
						
						
						
						
						
						
						
						
//						if(tp_dev.x[0]>96&&tp_dev.x[0]<144 && tp_dev.y[0]>600&&tp_dev.y[0]<800)
//						{
//							//单线测试
//							test_flag = 0;
//								
//						}
//						else if(tp_dev.x[0]>288&&tp_dev.x[0]<236&&tp_dev.y[0]>600&&tp_dev.y[0]<800)
//						{
//							//多线测试
//							test_flag = 1;
//						}
					}
				}
			
		}
        
}



////判断状态
//void  TIM4_IRQHandler(void)   
//{
//	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)  	
//		{
//		
//			
//			if(value>70)
//			{
//				//开始计时
//			TIM_Cmd(TIM5, ENABLE);
//				
//				while(count<=100&&count>=5) 
//				{
//					 flag = 2;
//					shther = 0;
//				}
//				if(count>100)
//				{
//					count=0;
//					TIM_Cmd(TIM5, DISABLE);
//				}
//					flag = 1;
//			}
//			
//			
//			//导通并关闭计时
////			if(count<=100)
////			{
////				flag = 2;
////			}
////			shther = 0;  //只显示导通
////			count =0;
//			
//			
//			
//			TIM_ClearITPendingBit(TIM4, TIM_IT_Update  ); 	 //清除TIMx更新中断标志 
//			
//                    
//		}
//        
//}




