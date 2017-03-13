#include "public.h"
#include "led.h"
#include "systick.h"
#include "key.h"

void key_press(){
	if(k_up==1){
		delay_ms(10);//延时十毫秒，消抖
		if(k_up==1){
			 GPIO_Write(GPIOC,(u16)(0xfe)) ;
		}
		while(k_up);
	}

		if(k_down==0){
		delay_ms(10);//延时十毫秒，消抖
		if(k_down==0){
			 GPIO_Write(GPIOC,(u16)(0xfd))	;
		}
		while(!k_down);
	}

		if(k_left==0){
		delay_ms(10);//延时十毫秒，消抖
		if(k_left==0){
			 GPIO_Write(GPIOC,(u16)(0xfb))	;
		}
		while(!k_left);
	}
	
		if(k_right==0){
		delay_ms(10);//延时十毫秒，消抖
		if(k_right==0){
			 GPIO_Write(GPIOC,(u16)(0xf7))	;
		}
		while(!k_right);
	}
}
int main(){

	key_init();
	LED_Init();
	GPIO_Write(GPIOC,(u16)(0XFF));
	while(1){
	key_press();		   
	}
}
