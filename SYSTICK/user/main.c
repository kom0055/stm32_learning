#include "public.h"
#include "led.h"
#include "systick.h"
int main(){
	u8 i;
	LED_Init();
	while(1){
		   for(i=0;i<8;i++){
		   		GPIO_Write(GPIOC,~(u16)(0X01<<i));
				delay_ms(1000);//���ԼΪ1864������Ҫ��ʱ������Ҫд���Ρ�
		   }
	}
}
