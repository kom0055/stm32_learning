#include "ds18b20.h"
void ds18b20_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);
	GPIO_InitStructure.GPIO_Pin=dq;		 
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIO_ds18b20,&GPIO_InitStructure);
}
void DQININT()	  // ‰»Î≈‰÷√
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=dq;		 
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIO_ds18b20,&GPIO_InitStructure);			
}
void DQOUTINT()	  // ‰≥ˆ≈‰÷√
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=dq;		 
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIO_ds18b20,&GPIO_InitStructure);			
}
void ds18b20init()
{
	DQOUTINT();	  // ‰≥ˆ≈‰÷√
	ds18b20_dq_L;
	delay_us(480);
	ds18b20_dq_H;
	delay_us(480);	
}
void ds18b20wr(u8 dat)
{
	u8 i=0;
	DQOUTINT();	  // ‰≥ˆ≈‰÷√
	for(i=0;i<8;i++)
	{
		ds18b20_dq_L;
		delay_us(15);
		
		if((dat&0x01)==1)
		{
			ds18b20_dq_H;	
		}
		else
		{
			ds18b20_dq_L;	
		}
		delay_us(60);
		ds18b20_dq_H;
		dat>>=1;	
	}
}
u8 DS18b20rd()
{
	u8 i=0,value=0;
	for(i=0;i<8;i++)
	{
		value>>=1;
		DQOUTINT();	  // ‰≥ˆ≈‰÷√
		ds18b20_dq_L;
		delay_us(4);
		ds18b20_dq_H;
		delay_us(10);
		DQININT();	  // ‰»Î≈‰÷√
		
		if(GPIO_ReadInputDataBit(GPIO_ds18b20,dq)==1)
		{
			value|=0x80;
		}
		delay_us(45);	
	}
	return value;
}
double readtemp()
{
	u8 a,b;
	u16 temp;
	double value;
	ds18b20init();
	ds18b20wr(0xcc);
	ds18b20wr(0x44);
	delay_ms(800);
	
	ds18b20init();
	ds18b20wr(0xcc);
	ds18b20wr(0xbe);
	a=DS18b20rd();
	b=DS18b20rd();
	temp=b;
	temp=(temp<<8)+a;
	if((temp&0xf800)==0xf800)
	{
		temp=(~temp)+1;
		value=temp*(-0.0625);
	}
	else
	{
		value=temp*(0.0625);	
	}
	return value;				
}

