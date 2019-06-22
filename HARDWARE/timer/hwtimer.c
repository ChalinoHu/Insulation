
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

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //ʱ��ʹ��
	
	
	
	//��ʱ��TIM3��ʼ��
	TIM_TimeBaseStructure.TIM_Period = 199; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =7199; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM3�ж�,��������ж�

	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���


	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIMx				//���ݺ�������򿪻��߹رն�ʱ��	 
}



//25ms��������ظߵ�ƽ
void TIM4_Int_Init(void)
{
 
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); //ʱ��ʹ��
	
	
	//��ʱ��TIM3��ʼ��
	TIM_TimeBaseStructure.TIM_Period = 249; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =7199; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM3�ж�,��������ж�

	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���
	TIM_Cmd(TIM4, ENABLE);  //ʹ��TIMx				//���ݺ�������򿪻��߹رն�ʱ��	 
}




//10ms�ɼ�һ����Ļ״̬
void  TIM3_IRQHandler(void)   //TIM3�ж�
{

			                   
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  	//���TIM3�����жϷ������
		{
			TIM_ClearITPendingBit(TIM3, TIM_IT_Update  ); 	 //���TIMx�����жϱ�־ 
             tp_dev.scan(0);	
				if((tp_dev.sta))     //ȷ������״̬    
				{
					
					if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)//�жϰ��µ�λ��
					{
						
						
						
						
						
						
						
						
//						if(tp_dev.x[0]>96&&tp_dev.x[0]<144 && tp_dev.y[0]>600&&tp_dev.y[0]<800)
//						{
//							//���߲���
//							test_flag = 0;
//								
//						}
//						else if(tp_dev.x[0]>288&&tp_dev.x[0]<236&&tp_dev.y[0]>600&&tp_dev.y[0]<800)
//						{
//							//���߲���
//							test_flag = 1;
//						}
					}
				}
			
		}
        
}



////�ж�״̬
//void  TIM4_IRQHandler(void)   
//{
//	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)  	
//		{
//		
//			
//			if(value>70)
//			{
//				//��ʼ��ʱ
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
//			//��ͨ���رռ�ʱ
////			if(count<=100)
////			{
////				flag = 2;
////			}
////			shther = 0;  //ֻ��ʾ��ͨ
////			count =0;
//			
//			
//			
//			TIM_ClearITPendingBit(TIM4, TIM_IT_Update  ); 	 //���TIMx�����жϱ�־ 
//			
//                    
//		}
//        
//}




