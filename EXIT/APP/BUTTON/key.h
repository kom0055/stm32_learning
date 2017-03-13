#ifndef _key_H
#define _key_H
#include "stm32f10x.h"
#define K_UP GPIO_Pin_0 //PA0
#define K_DOWN GPIO_Pin_3 //PA0
#define K_LEFT GPIO_Pin_2 //PA0
#define K_RIGHT GPIO_Pin_4 //PA0


#define k_up GPIO_ReadInputDataBit(GPIOA,K_UP) //»ñÈ¡°´¼ü×´Ì¬
#define k_down GPIO_ReadInputDataBit(GPIOE,K_DOWN)
#define k_left GPIO_ReadInputDataBit(GPIOE,K_LEFT)
#define k_right GPIO_ReadInputDataBit(GPIOE,K_RIGHT)

void key_init(void);

#endif
