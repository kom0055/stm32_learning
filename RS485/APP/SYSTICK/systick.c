#include "systick.h"
void delay_us(u32 i){
	u32 temp;
	SysTick->LOAD=9*i;		//������װ��ֵ��72MHZʱ
	SysTick->CTRL=0X01;		 //ʹ�ܣ�������ʱ�޶����������ⲿʱ��Դ
	SysTick->VAL=0;			 //���������
	do{
		temp=SysTick->CTRL;				  //��ȡ��ǰ������ֵ
	}
	while((temp&0x01)&&(!(temp&(1<<16))));	  //�ȴ�ʱ�䵽��
	SysTick->CTRL=0;				//�رռ�����
	SysTick->VAL=0;					 //��ռ�����
}

void delay_ms(u32 i){
	u32 temp;
	SysTick->LOAD=9000*i;
	SysTick->CTRL=0X01;
	SysTick->VAL=0;
	do{
		temp=SysTick->CTRL;
	}
	while((temp&0x01)&&(!(temp&(1<<16))));
	SysTick->CTRL=0;
	SysTick->VAL=0;
}
