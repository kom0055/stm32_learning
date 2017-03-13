#include "digital.h"
static u8 Digital_Tube[16]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};
/*
0 1100 0000
1 1111 1001 
2 1010 0100 
3 1011 0000
4 1001 1001
5 1001 0010
6 1000 0010
7 1111 1000
8 1000 0000
9 1001 0000
A 1000 1000
B 1000 0011
C 1100 0110
D 1010 0001
E 1000 0110
F 1000 1110	  
 */
void digital_init(){
	GPIO_InitTypeDef GPIO_InitStructure;

   SystemInit();	   //系统时钟初始化


   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//挂接端口C时钟



   GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	//管脚配置
   GPIO_InitStructure.GPIO_Pin=digital_tube;
   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;

   GPIO_Init(GPIOC,&GPIO_InitStructure);


   	
}

void static_digital_display(){
u8 i;
for(i=0;i<16;i++){
	GPIO_Write(GPIOC,(u16)Digital_Tube[i%16])	;
	delay_ms(1000);
}
}


