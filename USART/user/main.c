#include "public.h"
#include "systick.h"
#include "usart232.h"



int main(){
	//LED_Init();
	//led_display();
	// GPIO_WriteBit(GPIOA,GPIO_Pin_2,(BitAction)(Bit_SET-GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2))); 
	usart232_init();
	while(1);
}
