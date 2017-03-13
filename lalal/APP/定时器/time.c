#include "time.h"
void time_init()  //��ʱ����ʼ��
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);

	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
			 
	TIM_TimeBaseInitStructure.TIM_Period = 2000; 
	TIM_TimeBaseInitStructure.TIM_Prescaler = 35999; 
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInit(TIM3, & TIM_TimeBaseInitStructure);
	TIM_Cmd(TIM3, ENABLE);

	TIM_ITConfig(TIM3, TIM_IT_Update ,  ENABLE ); 


	/* ����NVIC���� */	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);		 
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn; 	//��TIM3_IRQn��ȫ���ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռ���ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		  //��Ӧ���ȼ�Ϊ1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 		  //ʹ��
	NVIC_Init(&NVIC_InitStructure); 	
}

