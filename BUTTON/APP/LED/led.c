#include  "led.h"

void delay(u32 i){
	while(i--);
}

void LED_Init(){	 //LED��ʼ��������LED��ʹ�ö˿�C
   GPIO_InitTypeDef GPIO_InitStructure;

   SystemInit();	   //ϵͳʱ�ӳ�ʼ��


   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//�ҽӶ˿�Cʱ��



   GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	//�ܽ�����
   GPIO_InitStructure.GPIO_Pin=LED;
   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;

   GPIO_Init(GPIOC,&GPIO_InitStructure);

}

void led_display(){	  //LED��������
	GPIO_SetBits(GPIOC,LED);	//����ߵ�ƽ LEDϨ��
	delay(6000000);
	GPIO_ResetBits(GPIOC,LED); //����͵�ƽ
	delay(6000000)	   ;
}
