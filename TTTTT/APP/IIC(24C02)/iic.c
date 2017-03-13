#include "iic.h"
void I2C_INIT()	 //IIC初始化函数
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Pin=I2C_SCL|I2C_SDA;		 
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	I2C_SCL_H;
	I2C_SDA_H;	
}
void I2C_SDA_OUT()	 //SDA输出
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin=I2C_SDA;		 
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);	
}
void I2C_SDA_IN()	 //SDA输入
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin=I2C_SDA;		 
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOB,&GPIO_InitStructure);	
}
void I2C_Start()	//起始信号
{
	I2C_SDA_OUT();	 //SDA输出
	
	I2C_SDA_H;
	I2C_SCL_H;
	delay_us(5);
	I2C_SDA_L;
	delay_us(6);
	I2C_SCL_L;	
}
void I2C_Stop()	  //停止信号
{
	I2C_SDA_OUT();	 //SDA输出
	I2C_SCL_L;
	I2C_SDA_L;
	I2C_SCL_H;
	delay_us(6);
	I2C_SDA_H;
	delay_us(6);		
}
void I2C_Ack()	 //主机应答
{
	I2C_SCL_L;
	I2C_SDA_OUT();	 //SDA输出
	I2C_SDA_L;
	delay_us(2);
	I2C_SCL_H;
	delay_us(5);
	I2C_SCL_L;		
}
void I2C_NAck()	 //主机非应答
{
	I2C_SCL_L;
	I2C_SDA_OUT();	 //SDA输出
	I2C_SDA_H;
	delay_us(2);
	I2C_SCL_H;
	delay_us(5);
	I2C_SCL_L;		
}
u8 I2C_Wait_Ack()  //等待从机应答	 1:应答失败  0：应答成功
{
	u8 tempTime=0;
	I2C_SDA_IN();	 //SDA输入
	I2C_SDA_H;
	delay_us(1);
	I2C_SCL_H;
	delay_us(1);
	
	while(GPIO_ReadInputDataBit(GPIO_I2C,I2C_SDA))
	{
		tempTime++;
		if(tempTime>250)
		{
			I2C_Stop();	  //停止信号
			return 1;	
		}		
	}
	I2C_SCL_L;
	return 0;		
}
void I2C_Send_Byte(u8 txd)
{
	u8 i=0;
	I2C_SDA_OUT();	 //SDA输出
	I2C_SCL_L;
	
	for(i=0;i<8;i++)
	{
		if((txd&0x80)>0)
		{
			I2C_SDA_H;	
		}
		else
		{
			I2C_SDA_L;
		}
		txd<<=1;
		I2C_SCL_H;
		delay_us(2);
		I2C_SCL_L;
		delay_us(2);
	}		
}
u8 I2C_Read_Byte(u8 ack)
{
	u8 i=0,receive=0;
	I2C_SDA_IN();	 //SDA输入
	
	for(i=0;i<8;i++)
	{
		I2C_SCL_L;
		delay_us(2);
		I2C_SCL_H;
		receive<<=1;
		if(GPIO_ReadInputDataBit(GPIO_I2C,I2C_SDA))
		{
			receive++;	
		}
		delay_us(1);
			
	}
	if(ack==0)
	{
		I2C_NAck();	 //主机非应答	
	}
	else
	{
		I2C_Ack();	
	}
	return receive;			
}
