/*******************************************************************************
*                 
*                 		       普中科技
--------------------------------------------------------------------------------
* 实 验 名		 : LCD-ADC实验
* 实验说明       : 通过将程序下载进去后点击复位，彩屏上面显示PA1管脚电位器AD检测电压值，
					ADC使用的是ADC1，通道是1，范围是0-3.3V
					最大只能达到3.29V，LED指示灯闪烁效果，按下复位开关重新运行,其他子函数注释
					可以参考之前的函数注释
* 连接方式       : 
* 注    意		 : 	所用函数在头文件.c文件内
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
	TFT_Init();	 //TFT初始化
	adc_init();	 //ADC初始化
	LED_Init();	  //LED端口初始化
	printf_init();//printf初始化	
	TFT_ClearScreen(BLACK);
	GUI_Show12ASCII(10,10,"This is a ADC1-Channel1-PA1 Check!",YELLOW,BLACK);
	GUI_Show12ASCII(10,100,"The AD Value is:",YELLOW,BLACK);
	while(1)
	{
		value=0;
		for(i=0;i<10;i++)
		{ 	
			ADC_SoftwareStartConvCmd(ADC1, ENABLE);
			while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));//转换结束标志位
			value=value+ADC_GetConversionValue(ADC1);//返回最近一次ADCx规则组的转换结果	
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



