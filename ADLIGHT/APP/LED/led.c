#include  "led.h"



void LED_Init(){	 //LED��ʼ��������LED��ʹ�ö˿�C
   GPIO_InitTypeDef GPIO_InitStructure;

   SystemInit();	   //ϵͳʱ�ӳ�ʼ��


   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//�ҽӶ˿�Cʱ��



   GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	//�ܽ�����
   GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;

   GPIO_Init(GPIOC,&GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//�ҽӶ˿�Cʱ��

   GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	//�ܽ�����
   GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;

   GPIO_Init(GPIOA,&GPIO_InitStructure);
}





