#ifndef _digital_H
#define _digital_H
#include "stm32f10x.h"
#define digital_tube (GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7)

void digital_init(void);
void static_digital_display(void);



#endif
