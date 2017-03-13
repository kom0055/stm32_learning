#include "public.h"
#include "systick.h"
#include "pwm.h"



int main(){
	u8 fx=1;//方向
	u32 ti=0;
	pwm_init();//PWM初始化
	while(1){
		delay_ms(10);
		if(fx==1){
			ti++;
			if(ti>300){
				fx=0;
			}
		}else if(fx==0){
			ti--;
			if(ti==0){
				fx=1;
			}
		}	
		TIM_SetCompare2(TIM3,ti);		
	}
}
