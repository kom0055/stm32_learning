#include "public.h"
#include "systick.h"
#include "timer.h"
#include "led.h"


int main(){

	timer_init();//定时器初始化
	LED_Init();
	while(1);
}
