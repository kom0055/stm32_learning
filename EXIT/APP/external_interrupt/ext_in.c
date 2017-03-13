#include "ext_in.h"
void exti_init(){ //�ⲿ�ж�2��ʼ��
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;//NVIC �ж����ȼ��ṹ��		   NVIC_InitStructure

   SystemInit();	   //ϵͳʱ�ӳ�ʼ��


   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);//�ҽӶ˿�Cʱ��
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//�򿪹ܽŸ��ù���


   GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	//�ܽ�����
   GPIO_InitStructure.GPIO_Pin=k_left;
   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU; // �ӵأ��ж�Ϊ��������ģʽ ���͵�ƽ 

   GPIO_Init(GPIOE,&GPIO_InitStructure);

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);//ѡ��ܽ������ⲿ�ж�  ��ӳ��

   EXTI_InitStructure.EXTI_Line=EXTI_Line2;
   EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
   EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
   EXTI_InitStructure.EXTI_LineCmd=ENABLE;
   EXTI_Init(&EXTI_InitStructure);

   NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);	 //�ж����ȼ����ã�����
   NVIC_InitStructure.NVIC_IRQChannel=EXTI2_IRQn;	  // ��EXTI2��ȫ���ж�
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0; //��ռ���ȼ�Ϊ0
   NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;	//��Ӧ���ȼ�Ϊ0
   NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//ʹ��
   NVIC_Init(&NVIC_InitStructure);
   	
}




   	



