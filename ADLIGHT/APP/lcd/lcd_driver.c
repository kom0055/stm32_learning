#include "lcd_driver.h"

/****************************************************************************
*函数名：TFT_GPIO_Config
*输  入：无
*输  出：无
*功  能：初始化TFT的IO口。
****************************************************************************/	  

void TFT_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/* 打开时钟使能 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE  
	                      | RCC_APB2Periph_GPIOG, ENABLE);

	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	/* FSMC_A10(G12) 和RS（G0）*/
	GPIO_Init(GPIOG, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = (GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 
	                              | GPIO_Pin_5 | GPIO_Pin_8 | GPIO_Pin_8 
								  | GPIO_Pin_9 | GPIO_Pin_10 |GPIO_Pin_11
								  | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14
								  | GPIO_Pin_15 );

	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = (GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9
	                               | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12
								   | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);

	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

/****************************************************************************
* Function Name  : TFT_FSMC_Config
* Description    : 初始化FSMC
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void TFT_FSMC_Config(void)
{
	/* 初始化函数 */
	FSMC_NORSRAMInitTypeDef        FSMC_NORSRAMInitStructure;
	FSMC_NORSRAMTimingInitTypeDef  FSMC_NORSRAMTiming;

	/* 设置读写时序，给FSMC_NORSRAMInitStructure调用 */
	/* 地址建立时间，3个HCLK周期 */
	FSMC_NORSRAMTiming.FSMC_AddressSetupTime = 0x02;

	/* 地址保持时间，1个HCLK周期 */
	FSMC_NORSRAMTiming.FSMC_AddressHoldTime = 0x00;

	/* 数据建立时间，6个HCLK周期 */
	FSMC_NORSRAMTiming.FSMC_DataSetupTime = 0x05;

	/* 数据保持时间，1个HCLK周期 */
	FSMC_NORSRAMTiming.FSMC_DataLatency = 0x00;

	/* 总线恢复时间设置 */
	FSMC_NORSRAMTiming.FSMC_BusTurnAroundDuration = 0x00;
	
	/* 时钟分频设置 */
	FSMC_NORSRAMTiming.FSMC_CLKDivision = 0x01;

	/* 设置模式，如果在地址/数据不复用时，ABCD模式都区别不大 */
	FSMC_NORSRAMTiming.FSMC_AccessMode = FSMC_AccessMode_B;

	/*设置FSMC_NORSRAMInitStructure的数据*/
	/* FSMC有四个存储块（bank），我们使用第一个（bank1） */
	/* 同时我们使用的是bank里面的第 4个RAM区 */
	FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM4;

	/* 这里我们使用SRAM模式 */
	FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_SRAM;

	/* 使用的数据宽度为16位 */
	FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;

	/* 设置写使能打开 */
	FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;

	/* 选择拓展模式使能，即设置读和写用不同的时序 */
	FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Enable;
	
	/* 设置地址和数据复用使能不打开 */
	FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
	
	/* 设置读写时序 */
	FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &FSMC_NORSRAMTiming;
	
	/* 设置写时序 */
	FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &FSMC_NORSRAMTiming;

	/* 打开FSMC的时钟 */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);
	 
	FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure); 

	/*!< Enable FSMC Bank1_SRAM Bank */
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM4, ENABLE);	
}

/****************************************************************************
* Function Name  : TFT_WriteCmd
* Description    : LCD写入命令
* Input          : cmd：写入的16位命令
* Output         : None
* Return         : None
****************************************************************************/

void TFT_WriteCmd(uint16_t cmd)
{
	TFT->TFT_CMD = cmd ;
}

/****************************************************************************
* Function Name  : TFT_WriteData
* Description    : LCD写入数据
* Input          : dat：写入的16位数据
* Output         : None
* Return         : None
****************************************************************************/

void TFT_WriteData(u16 dat)
{
	TFT->TFT_DATA = dat;
}

/****************************************************************************
* Function Name  : TFT_Init
* Description    : 初始化LCD屏
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void TFT_Init(void)
{
	uint16_t i;

	TFT_GPIO_Config();
	TFT_FSMC_Config();

	for(i=500; i>0; i--);
	TFT_WriteCmd(0x11);
	for(i=500; i>0; i--);
	TFT_WriteCmd(0xB9);
    TFT_WriteData(0xFF);
	TFT_WriteData(0x83);
	TFT_WriteData(0x57);
    for(i=500; i>0; i--);

	TFT_WriteCmd(0xB1);
    TFT_WriteData(0x00);
	TFT_WriteData(0x14);
	TFT_WriteData(0x1C);
	TFT_WriteData(0x1C);
	TFT_WriteData(0xC3);
	TFT_WriteData(0x44);
    TFT_WriteData(0x70);
   for(i=500; i>0; i--);
    TFT_WriteCmd(0xB4);
    TFT_WriteData(0x22);
	TFT_WriteData(0x40);
	TFT_WriteData(0x00);
	TFT_WriteData(0x2A);
	TFT_WriteData(0x2A);
	TFT_WriteData(0x20);
	TFT_WriteData(0x91);
  for(i=500; i>0; i--);
    TFT_WriteCmd(0x36);
    TFT_WriteData(0x4c);

    TFT_WriteCmd(0xC0);
    TFT_WriteData(0x50);
	TFT_WriteData(0x50);
	TFT_WriteData(0x01);
	TFT_WriteData(0x3C);
	TFT_WriteData(0xC8);
	TFT_WriteData(0x08);
    TFT_WriteData(0x00);
	TFT_WriteData(0x08);
	TFT_WriteData(0x04);
     for(i=500; i>0; i--);
    for(i=500; i>0; i--);
    TFT_WriteCmd(0xE0);
    TFT_WriteData(0x0B); 
    TFT_WriteData(0x11); 
    TFT_WriteData(0x1E); 
    TFT_WriteData(0x30); 
    TFT_WriteData(0x3A); 
    TFT_WriteData(0x43); 
    TFT_WriteData(0x4E); 
    TFT_WriteData(0x56); 
    TFT_WriteData(0x45); 
    TFT_WriteData(0x3F); 
    TFT_WriteData(0x39); 
    TFT_WriteData(0x32); 
    TFT_WriteData(0x2F); 
    TFT_WriteData(0x2A); 
    TFT_WriteData(0x29); 
    TFT_WriteData(0x21); 
    TFT_WriteData(0x0B); 
    TFT_WriteData(0x11); 
    TFT_WriteData(0x1E); 
    TFT_WriteData(0x30); 
    TFT_WriteData(0x3A); 
    TFT_WriteData(0x43); 
    TFT_WriteData(0x4E); 
    TFT_WriteData(0x56); 
    TFT_WriteData(0x45); 
    TFT_WriteData(0x3F); 
    TFT_WriteData(0x39); 
    TFT_WriteData(0x32); 
    TFT_WriteData(0x2F); 
    TFT_WriteData(0x2A); 
    TFT_WriteData(0x29); 
    TFT_WriteData(0x21); 
    TFT_WriteData(0x00); 
    TFT_WriteData(0x01); 

    TFT_WriteCmd(0x21);
 	TFT_WriteCmd(0x3a);
 	TFT_WriteData(0x05);

    TFT_WriteCmd(0x29);

}

/****************************************************************************
* Function Name  : TFT_SetWindow
* Description    : 设置要操作的窗口范围
* Input          : xStart：窗口起始X坐标
*                * yStart：窗口起始Y坐标
*                * xEnd：窗口结束X坐标
*                * yEnd：窗口结束Y坐标
* Output         : None
* Return         : None
****************************************************************************/

void TFT_SetWindow(uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t yEnd)
{
 	TFT_WriteCmd(0x2A);

    TFT_WriteData(xStart>>8);
    TFT_WriteData(xStart&0XFF);
    TFT_WriteData(xEnd>>8);
    TFT_WriteData(xEnd&0XFF);

    TFT_WriteCmd(0x2b);
    TFT_WriteData(yStart>>8);
    TFT_WriteData(yStart&0XFF);
    TFT_WriteData(yEnd>>8);
    TFT_WriteData(yEnd&0XFF);
    TFT_WriteCmd(0x2c); 
}

/****************************************************************************
* Function Name  : TFT_ClearScreen
* Description    : 将LCD清屏成相应的颜色
* Input          : color：清屏颜色
* Output         : None
* Return         : None
****************************************************************************/
	  
void TFT_ClearScreen(uint16_t color)
{
 	uint16_t i, j ;

	TFT_SetWindow(0, 0, TFT_XMAX, TFT_YMAX);	 //作用区域
  	for(i=0; i<TFT_XMAX+1; i++)
	{
		for (j=0; j<TFT_YMAX+1; j++)
		{
			TFT_WriteData(color);
		}
	}
}
