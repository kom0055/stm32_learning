#ifndef _beep_H
#define _beep_H
#include "stm32f10x.h"
#define BUZ GPIO_Pin_5		//PB5

void BEEP_Init(void);	
void sound2(void);

#endif
