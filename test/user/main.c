#include "public.h"
#include "systick.h"

#include "led.h"
#include "lsens.h"
#include "adc3.h"


int main(void)
{
      u8 adcx;
       NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
       delay_init(168);    //初始化延时函数
       uart_init(115200);  //初始化串口波特率为115200
       LED_Init();                                //初始化LED
      //LCD_Init();                                //初始化LCD
       Lsens_Init();  	         //初始化光敏传感器
       //POINT_COLOR=RED;
       //LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");      
       //LCD_ShowString(30,70,200,16,16,"LSENS TEST");
       //LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
       //LCD_ShowString(30,110,200,16,16,"2014/5/7");        
       //POINT_COLOR=BLUE;//设置字体为蓝色
       //LCD_ShowString(30,130,200,16,16,"LSENS_VAL:");                  
       while(1)
       {
              adcx=Lsens_Get_Val();
              //LCD_ShowxNum(30+10*8,130,adcx,3,16,0);//显示ADC的值
             // LED0=!LED0;
              delay_ms(250);     
			  }
			  }
