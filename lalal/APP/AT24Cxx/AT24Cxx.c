#include "AT24Cxx.h"

u8 AT24Cxx_ReadOneByte(u8 addr)
{
	u8 temp=0;
	I2C_Start();	//起始信号	
	if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);
	}
	else
	{
		I2C_Send_Byte(0xa0+((addr/256)<<1));//器件地址+数据地址	
	}
	I2C_Wait_Ack();
	I2C_Send_Byte(addr%256);
	I2C_Wait_Ack();
	
	I2C_Start();	//起始信号
	I2C_Send_Byte(0xa1);
	I2C_Wait_Ack();
	temp=I2C_Read_Byte(0);
	I2C_Stop();
	return temp;		
}
u16 AT24Cxx_ReadTwoByte(u16 addr)
{
	u16 temp=0;
	I2C_Start();	//起始信号	
	if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);
	}
	else
	{
		I2C_Send_Byte(0xa0+((addr/256)<<1));//器件地址+数据地址	
	}
	I2C_Wait_Ack();
	I2C_Send_Byte(addr%256);
	I2C_Wait_Ack();
	
	I2C_Start();	//起始信号
	I2C_Send_Byte(0xa1);
	I2C_Wait_Ack();
	temp=I2C_Read_Byte(1);
	temp<<=8;
	temp|=I2C_Read_Byte(0);
	I2C_Stop();
	return temp;		
}
void AT24Cxx_WriteOneByte(u8 addr,u8 dt)
{
	I2C_Start();	//起始信号	

	if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);
	}
	else
	{
		I2C_Send_Byte(0xa0+((addr/256)<<1));//器件地址+数据地址	
	}
	I2C_Wait_Ack();
	I2C_Send_Byte(addr%256);
	I2C_Wait_Ack();

	I2C_Send_Byte(dt);
	I2C_Wait_Ack();
	I2C_Stop();

	delay_ms(10);
}
void AT24Cxx_WriteTwoByte(u16 addr,u16 dt)
{
	I2C_Start();	//起始信号	

	if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);
	}
	else
	{
		I2C_Send_Byte(0xa0+((addr/256)<<1));//器件地址+数据地址	
	}
	I2C_Wait_Ack();
	I2C_Send_Byte(addr%256);
	I2C_Wait_Ack();
				  
	I2C_Send_Byte(dt>>8);
	I2C_Wait_Ack();
	I2C_Send_Byte(dt&0xff);
	I2C_Wait_Ack();
	I2C_Stop();

	delay_ms(10);
}

