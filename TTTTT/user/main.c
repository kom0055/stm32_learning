/*******************************************************************************
*                 
*                 		       ���пƼ�
--------------------------------------------------------------------------------
* ʵ �� ��		 : 485ͨ��ʵ��
* ʵ��˵��       : ͨ��USBת485��ͷ������ϵ�AB��������ͨ�� ͨ�Ž����232����
* ���ӷ�ʽ       : 
* ע    ��		 : 	���ú�����ͷ�ļ�.c�ļ���
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
	//rs485_init();	//485��ʼ��
	//GPIO_ResetBits(GPIOG,GPIO_Pin_3);//����Ҫ��485�������ݵĿ��ƶ�
	while(1){


	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0){
		 	GPIO_SetBits(GPIOC,GPIO_Pin_0);
	}
	else  GPIO_ResetBits(GPIOC,GPIO_Pin_0);
	}	 delay_ms(100);
}

	




