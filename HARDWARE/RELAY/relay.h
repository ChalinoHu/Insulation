#ifndef __RELAY_H
#define __RELAY_H
/*
PA------1 2 3 4 5 6 7     11 12 13 14 15 
PF------0 1 2 3 4 5 6 7
PB------3 5 6 7 8 9 12 13 14 15
PC------ 1 2  
*/
//¼ÌµçÆ÷ 1¡ª¡ª16½Ó12V
//       17¡ª¡ª32 ½ÓGND



#define J1_ON GPIO_SetBits(GPIOG,GPIO_Pin_3)
#define J2_ON GPIO_SetBits(GPIOG,GPIO_Pin_5)
#define J3_ON GPIO_SetBits(GPIOA,GPIO_Pin_12)
#define J4_ON GPIO_SetBits(GPIOG,GPIO_Pin_14)
#define J5_ON GPIO_SetBits(GPIOB,GPIO_Pin_5)
#define J6_ON GPIO_SetBits(GPIOB,GPIO_Pin_7)
#define J7_ON GPIO_SetBits(GPIOB,GPIO_Pin_8)
#define J8_ON GPIO_SetBits(GPIOB,GPIO_Pin_6)
#define J9_ON GPIO_SetBits(GPIOG,GPIO_Pin_1)
#define J10_ON GPIO_SetBits(GPIOA,GPIO_Pin_7)
#define J11_ON GPIO_SetBits(GPIOA,GPIO_Pin_5)
#define J12_ON GPIO_SetBits(GPIOA,GPIO_Pin_3)
#define J13_ON GPIO_SetBits(GPIOA,GPIO_Pin_1)
#define J14_ON GPIO_SetBits(GPIOF,GPIO_Pin_6)
#define J15_ON GPIO_SetBits(GPIOF,GPIO_Pin_4)
#define J16_ON GPIO_SetBits(GPIOF,GPIO_Pin_2)



#define J17_ON GPIO_SetBits(GPIOG,GPIO_Pin_2)
#define J18_ON GPIO_SetBits(GPIOG,GPIO_Pin_6)
#define J19_ON GPIO_SetBits(GPIOG,GPIO_Pin_8)
#define J20_ON GPIO_SetBits(GPIOA,GPIO_Pin_11)

#define J21_ON GPIO_SetBits(GPIOG,GPIO_Pin_9)
#define J22_ON GPIO_SetBits(GPIOG,GPIO_Pin_11)
#define J23_ON GPIO_SetBits(GPIOG,GPIO_Pin_13)
#define J24_ON GPIO_SetBits(GPIOG,GPIO_Pin_15)
#define J25_ON GPIO_SetBits(GPIOA,GPIO_Pin_6)
#define J26_ON GPIO_SetBits(GPIOA,GPIO_Pin_4)
#define J27_ON GPIO_SetBits(GPIOA,GPIO_Pin_2)
#define J28_ON GPIO_SetBits(GPIOF,GPIO_Pin_7)
#define J29_ON GPIO_SetBits(GPIOF,GPIO_Pin_5)
#define J30_ON GPIO_SetBits(GPIOF,GPIO_Pin_3)

#define J31_ON GPIO_SetBits(GPIOF,GPIO_Pin_1)
#define J32_ON GPIO_SetBits(GPIOF,GPIO_Pin_0)


#define J1_OFF GPIO_ResetBits(GPIOG,GPIO_Pin_3)
#define J2_OFF GPIO_ResetBits(GPIOG,GPIO_Pin_5)
#define J3_OFF GPIO_ResetBits(GPIOA,GPIO_Pin_12)
#define J4_OFF GPIO_ResetBits(GPIOG,GPIO_Pin_14)
#define J5_OFF GPIO_ResetBits(GPIOB,GPIO_Pin_5)
#define J6_OFF GPIO_ResetBits(GPIOB,GPIO_Pin_7)
#define J7_OFF GPIO_ResetBits(GPIOB,GPIO_Pin_8)
#define J8_OFF GPIO_ResetBits(GPIOB,GPIO_Pin_6)
#define J9_OFF GPIO_ResetBits(GPIOG,GPIO_Pin_1)
#define J10_OFF GPIO_ResetBits(GPIOA,GPIO_Pin_7)
#define J11_OFF GPIO_ResetBits(GPIOA,GPIO_Pin_5)
#define J12_OFF GPIO_ResetBits(GPIOA,GPIO_Pin_3)
#define J13_OFF GPIO_ResetBits(GPIOA,GPIO_Pin_1)
#define J14_OFF GPIO_ResetBits(GPIOF,GPIO_Pin_6)
#define J15_OFF GPIO_ResetBits(GPIOF,GPIO_Pin_4)
#define J16_OFF GPIO_ResetBits(GPIOF,GPIO_Pin_2)



#define J17_OFF GPIO_ResetBits(GPIOG,GPIO_Pin_2)
#define J18_OFF GPIO_ResetBits(GPIOG,GPIO_Pin_6)
#define J19_OFF GPIO_ResetBits(GPIOG,GPIO_Pin_8)
#define J20_OFF GPIO_ResetBits(GPIOA,GPIO_Pin_11)

#define J21_OFF GPIO_ResetBits(GPIOG,GPIO_Pin_9)
#define J22_OFF GPIO_ResetBits(GPIOG,GPIO_Pin_11)
#define J23_OFF GPIO_ResetBits(GPIOG,GPIO_Pin_13)
#define J24_OFF GPIO_ResetBits(GPIOG,GPIO_Pin_15)
#define J25_OFF GPIO_ResetBits(GPIOA,GPIO_Pin_6)
#define J26_OFF GPIO_ResetBits(GPIOA,GPIO_Pin_4)
#define J27_OFF GPIO_ResetBits(GPIOA,GPIO_Pin_2)
#define J28_OFF GPIO_ResetBits(GPIOF,GPIO_Pin_7)
#define J29_OFF GPIO_ResetBits(GPIOF,GPIO_Pin_5)
#define J30_OFF GPIO_ResetBits(GPIOF,GPIO_Pin_3)

#define J31_OFF GPIO_ResetBits(GPIOF,GPIO_Pin_1)
#define J32_OFF GPIO_ResetBits(GPIOF,GPIO_Pin_0)


void relay_init(void);

void xihe(unsigned char num);

void duankai(unsigned char uum);



#endif 
