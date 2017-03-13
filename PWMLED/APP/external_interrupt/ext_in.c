#include "ext_in.h"
void exti_init(){ //外部中断2初始化
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;//NVIC 中断优先级结构体		   NVIC_InitStructure

   SystemInit();	   //系统时钟初始化


   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);//挂接端口C时钟
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//打开管脚复用功能


   GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	//管脚配置
   GPIO_InitStructure.GPIO_Pin=k_left;
   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU; // 接地，判断为上拉输入模式 ，低电平 

   GPIO_Init(GPIOE,&GPIO_InitStructure);

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);//选择管脚用作外部中断  ，映射

   EXTI_InitStructure.EXTI_Line=EXTI_Line2;
   EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
   EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
   EXTI_InitStructure.EXTI_LineCmd=ENABLE;
   EXTI_Init(&EXTI_InitStructure);

   NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);	 //中断优先级配置，分组
   NVIC_InitStructure.NVIC_IRQChannel=EXTI2_IRQn;	  // 打开EXTI2的全局中断
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0; //抢占优先级为0
   NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;	//相应优先级为0
   NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//使能
   NVIC_Init(&NVIC_InitStructure);
   	
}




   	



