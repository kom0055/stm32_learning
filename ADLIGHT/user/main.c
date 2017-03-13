/*******************************************************************************
*                 
*                 		       ���пƼ�
--------------------------------------------------------------------------------
* ʵ �� ��		 : LCD-ADCʵ��
* ʵ��˵��       : ͨ�����������ؽ�ȥ������λ������������ʾPA1�ܽŵ�λ��AD����ѹֵ��
					ADCʹ�õ���ADC1��ͨ����1����Χ��0-3.3V
					���ֻ�ܴﵽ3.29V��LEDָʾ����˸Ч�������¸�λ������������,�����Ӻ���ע��
					���Բο�֮ǰ�ĺ���ע��
* ���ӷ�ʽ       : 
* ע    ��		 : 	���ú�����ͷ�ļ�.c�ļ���
*******************************************************************************/


#include "public.h"
#include "adc.h"
#include "systick.h"
#include "gui.h"
#include "led.h"
#include "printf.h"


/****************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
int main()
{	
	u8 i,dat[6],j;
	u16 value;
	float ad;
	TFT_Init();	 //TFT��ʼ��
	adc_init();	 //ADC��ʼ��
	LED_Init();	  //LED�˿ڳ�ʼ��
	printf_init();//printf��ʼ��	
	TFT_ClearScreen(BLACK);
	GUI_Show12ASCII(10,10,"This is a ADC1-Channel1-PA1 Check!",YELLOW,BLACK);
	GUI_Show12ASCII(10,100,"The AD Value is:",YELLOW,BLACK);
	while(1)
	{
		value=0;
		for(i=0;i<10;i++)
		{ 	
			ADC_SoftwareStartConvCmd(ADC1, ENABLE);
			while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));//ת��������־λ
			value=value+ADC_GetConversionValue(ADC1);//�������һ��ADCx�������ת�����	
		}
		
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0){
		 	GPIO_SetBits(GPIOC,GPIO_Pin_0);
	}
	else  GPIO_ResetBits(GPIOC,GPIO_Pin_0);
		
		delay_ms(100);
		value=value/10;
		ad=value*3.3/4096;
		value=(u16)(ad*100);
		dat[0]=value/100+0x30;
		dat[1]='.';
		dat[2]=value%100/10+0x30;
		dat[3]=value%100%10+0x30;
		dat[4]='V';
		dat[5]='\0';
		GUI_Show12ASCII(160,100,dat,RED,BLACK);		
	}			
}



