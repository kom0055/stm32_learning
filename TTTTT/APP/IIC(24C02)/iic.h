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


void I2C_INIT(void);	 //IIC��ʼ������
void I2C_SDA_OUT(void);	 //SDA���
void I2C_SDA_IN(void);	 //SDA����
void I2C_Start(void);	//��ʼ�ź�
void I2C_Stop(void);	  //ֹͣ�ź�
void I2C_Ack(void);	 //����Ӧ��
void I2C_NAck(void);	 //������Ӧ��
u8 I2C_Wait_Ack(void);  //�ȴ��ӻ�Ӧ��	 1:Ӧ��ʧ��  0��Ӧ��ɹ�
void I2C_Send_Byte(u8 txd);
u8 I2C_Read_Byte(u8 ack);

#endif
