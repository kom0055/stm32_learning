#include "rs485.h"
void rs485_init(){		//rs485��ʼ������
	GPIO_InitTypeDef GPIO_InitStructure;  
	USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOG,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;	  //���͹ܽ�   tx
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//�����������
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;   //���չܽ�	rx
	//GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//��������
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;	  //CS-485 ʹ�ܶ˿�

	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//�����������
	GPIO_Init(GPIOG,&GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate=9600;
    USART_InitStructure.USART_WordLength=USART_WordLength_8b;
    USART_InitStructure.USART_StopBits=USART_StopBits_1;
    USART_InitStructure.USART_Parity=USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;
    USART_Init(USART2,&USART_InitStructure);
    
    USART_Cmd(USART2,ENABLE);
    USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);//�жϽ���ʹ��
    USART_ClearFlag(USART2,USART_FLAG_TC);//��շ�����ɱ�־λ

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);	 //�ж����ȼ����ã�����
    NVIC_InitStructure.NVIC_IRQChannel=USART2_IRQn;	  // �򿪴���2��ȫ���ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0; //��ռ���ȼ�Ϊ0
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;	//��Ӧ���ȼ�Ϊ0
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//ʹ��
    NVIC_Init(&NVIC_InitStructure);
	
}