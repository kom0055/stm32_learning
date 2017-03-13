#include  "led.h"



void LED_Init(){	 //LED初始化函数，LED是使用端口C
   GPIO_InitTypeDef GPIO_InitStructure;

   SystemInit();	   //系统时钟初始化


   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//挂接端口C时钟



   GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	//管脚配置
   GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;

   GPIO_Init(GPIOC,&GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//挂接端口C时钟

   GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	//管脚配置
   GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;

   GPIO_Init(GPIOA,&GPIO_InitStructure);
}





