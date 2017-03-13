#ifndef _ds18b20_H
#define _ds18b20_H
#include "stm32f10x.h"
#include "systick.h"
#define dq GPIO_Pin_11   //PG11
#define GPIO_ds18b20 GPIOG
#define ds18b20_dq_H GPIO_SetBits(GPIO_ds18b20,dq) 
#define ds18b20_dq_L GPIO_ResetBits(GPIO_ds18b20,dq)  
void ds18b20_init(void);
void DQININT(void);	  // ‰»Î≈‰÷√
void DQOUTINT(void);	  // ‰≥ˆ≈‰÷√
void ds18b20init(void);
void ds18b20wr(u8 dat);
u8 DS18b20rd(void);
double readtemp(void);



#endif
