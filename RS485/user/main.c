#include "public.h"
#include "systick.h"
#include "rs485.h"



int main(){

	rs485_init();	 //���ڳ�ʼ������
	GPIO_ResetBits(GPIOG,GPIO_Pin_3);

	while(1);
}
