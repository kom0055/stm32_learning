#ifndef _led_H
#define _led_H
#include "stm32f10x.h"
#define LED GPIO_Pin_All

void LED_Init(void);	 //LED��ʼ������
void led_display(void);

#endif
