#include "public.h"
#include "systick.h"
#include "timer.h"
#include "led.h"


int main(){

	timer_init();//��ʱ����ʼ��
	LED_Init();
	while(1);
}
