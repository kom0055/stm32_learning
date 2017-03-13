#include "public.h"
#include "systick.h"
#include "ext_in.h"
#include "led.h"


int main(){

	LED_Init();
	exti_init();
	while(1);
}
