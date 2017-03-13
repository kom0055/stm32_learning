#ifndef _iic_H
#define _iic_H
#include "stm32f10x.h"
#include "systick.h"

#define I2C_SCL GPIO_Pin_10  //PB10
#define I2C_SDA GPIO_Pin_11  //PB11

#define GPIO_I2C GPIOB 

#define I2C_SCL_H GPIO_SetBits(GPIO_I2C,I2C_SCL)
#define I2C_SCL_L GPIO_ResetBits(GPIO_I2C,I2C_SCL)

#define I2C_SDA_H GPIO_SetBits(GPIO_I2C,I2C_SDA)
#define I2C_SDA_L GPIO_ResetBits(GPIO_I2C,I2C_SDA)


void I2C_INIT(void);	 //IIC初始化函数
void I2C_SDA_OUT(void);	 //SDA输出
void I2C_SDA_IN(void);	 //SDA输入
void I2C_Start(void);	//起始信号
void I2C_Stop(void);	  //停止信号
void I2C_Ack(void);	 //主机应答
void I2C_NAck(void);	 //主机非应答
u8 I2C_Wait_Ack(void);  //等待从机应答	 1:应答失败  0：应答成功
void I2C_Send_Byte(u8 txd);
u8 I2C_Read_Byte(u8 ack);

#endif
