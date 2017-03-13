#include "usart232.h"
void usart232_init(){	//串口初始化函数
	GPIO_InitTypeDef GPIO_InitStructure;  
	USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;	  //发送管脚   tx
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//复用推挽输出
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;   //接收管脚	rx
	//GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//浮空输入
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate=9600;
    USART_InitStructure.USART_WordLength=USART_WordLength_8b;
    USART_InitStructure.USART_StopBits=USART_StopBits_1;
    USART_InitStructure.USART_Parity=USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;
    USART_Init(USART1,&USART_InitStructure);
    
    USART_Cmd(USART1,ENABLE);
    USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//中断接受使能
    USART_ClearFlag(USART1,USART_FLAG_TC);//清空发送完成标志位

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);	 //中断优先级配置，分组
    NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;	  // 打开串口1的全局中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0; //抢占优先级为0
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;	//相应优先级为0
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//使能
    NVIC_Init(&NVIC_InitStructure);


}
