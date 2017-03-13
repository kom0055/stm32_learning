#include  "led.h"

void delay(u32 i){
	while(i--);
}

void LED_Init(){	 //LED初始化函数，LED是使用端口C
   GPIO_InitTypeDef GPIO_InitStructure;

   SystemInit();	   //系统时钟初始化


   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//挂接端口C时钟



   GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	//管脚配置
   GPIO_InitStructure.GPIO_Pin=LED;
   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;

   GPIO_Init(GPIOC,&GPIO_InitStructure);

}

void led_display(){	  //LED驱动函数
	GPIO_SetBits(GPIOC,LED);	//输出高电平 LED熄灭
	delay(6000000);
	GPIO_ResetBits(GPIOC,LED); //输出低电平
	delay(6000000)	   ;
}
