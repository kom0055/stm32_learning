/*******************************************************************************
*                 
*                 		       普中科技
--------------------------------------------------------------------------------
* 实 验 名		 : 485通信实验
* 实验说明       : 通过USB转485接头与板子上的AB相连进行通信 通信结果与232类似
* 连接方式       : 
* 注    意		 : 	所用函数在头文件.c文件内
*******************************************************************************/


#include "public.h"
#include "led.h"
#include "systick.h"
#include "stm32f10x_it.h"

/****************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
int main()
{	
LED_Init();
GPIO_SetBits(GPIOC,GPIO_Pin_0);
		 delay_ms(1000);
	 //usart_init();
	//rs485_init();	//485初始化
	//GPIO_ResetBits(GPIOG,GPIO_Pin_3);//首先要打开485接收数据的控制端
	while(1){


	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0){
		 	GPIO_SetBits(GPIOC,GPIO_Pin_0);
	}
	else  GPIO_ResetBits(GPIOC,GPIO_Pin_0);
	}	 delay_ms(100);
}

	




