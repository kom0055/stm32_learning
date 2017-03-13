#include "iic.h"
void I2C_INIT()	 //IIC��ʼ������
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
void I2C_SDA_OUT()	 //SDA���
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin=I2C_SDA;		 
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);	
}
void I2C_SDA_IN()	 //SDA����
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin=I2C_SDA;		 
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOB,&GPIO_InitStructure);	
}
void I2C_Start()	//��ʼ�ź�
{
	I2C_SDA_OUT();	 //SDA���
	
	I2C_SDA_H;
	I2C_SCL_H;
	delay_us(5);
	I2C_SDA_L;
	delay_us(6);
	I2C_SCL_L;	
}
void I2C_Stop()	  //ֹͣ�ź�
{
	I2C_SDA_OUT();	 //SDA���
	I2C_SCL_L;
	I2C_SDA_L;
	I2C_SCL_H;
	delay_us(6);
	I2C_SDA_H;
	delay_us(6);		
}
void I2C_Ack()	 //����Ӧ��
{
	I2C_SCL_L;
	I2C_SDA_OUT();	 //SDA���
	I2C_SDA_L;
	delay_us(2);
	I2C_SCL_H;
	delay_us(5);
	I2C_SCL_L;		
}
void I2C_NAck()	 //������Ӧ��
{
	I2C_SCL_L;
	I2C_SDA_OUT();	 //SDA���
	I2C_SDA_H;
	delay_us(2);
	I2C_SCL_H;
	delay_us(5);
	I2C_SCL_L;		
}
u8 I2C_Wait_Ack()  //�ȴ��ӻ�Ӧ��	 1:Ӧ��ʧ��  0��Ӧ��ɹ�
{
	u8 tempTime=0;
	I2C_SDA_IN();	 //SDA����
	I2C_SDA_H;
	delay_us(1);
	I2C_SCL_H;
	delay_us(1);
	
	while(GPIO_ReadInputDataBit(GPIO_I2C,I2C_SDA))
	{
		tempTime++;
		if(tempTime>250)
		{
			I2C_Stop();	  //ֹͣ�ź�
			return 1;	
		}		
	}
	I2C_SCL_L;
	return 0;		
}
void I2C_Send_Byte(u8 txd)
{
	u8 i=0;
	I2C_SDA_OUT();	 //SDA���
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
	I2C_SDA_IN();	 //SDA����
	
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
		I2C_NAck();	 //������Ӧ��	
	}
	else
	{
		I2C_Ack();	
	}
	return receive;			
}
