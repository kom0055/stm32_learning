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
#include "rs485.h"
#include "usart.h"

/****************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
int main()
{	
	 usart_init();
	//rs485_init();	//485��ʼ��
	//GPIO_ResetBits(GPIOG,GPIO_Pin_3);//����Ҫ��485�������ݵĿ��ƶ�
	while(1);
}


