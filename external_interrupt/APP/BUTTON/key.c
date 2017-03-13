#include "key.h"
void key_init(){
	GPIO_InitTypeDef GPIO_InitStructure;

   SystemInit();	   //系统时钟初始化


   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);//挂接端口C时钟



   GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	//管脚配置
   GPIO_InitStructure.GPIO_Pin=K_UP;
   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;

   GPIO_Init(GPIOA,&GPIO_InitStructure);

   GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	//管脚配置
   GPIO_InitStructure.GPIO_Pin=K_DOWN|K_LEFT|K_RIGHT;
   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;

   GPIO_Init(GPIOE,&GPIO_InitStructure);


   GPIO_ResetBits(GPIOA,K_UP);
}
