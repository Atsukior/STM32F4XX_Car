#include "led_ctrl.h"
#include "stm32f4xx.h"

//led 初始化函数
void led_init(void)
{
	
	//1、时钟使能 PF9 PF10 PE13 PE14
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	//2、配置GPIO引脚
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; //控制引脚的高低电平是输出
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;//既要输出高点平，又要输出低电平，所以是推挽输出
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;//对应的是PF第9个和第十个pin口
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//一般是50mhz
	GPIO_Init( GPIOF, &GPIO_InitStruct);//初始化串口

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOE, &GPIO_InitStruct);

	//3、默认状态=>灭
	GPIO_SetBits(GPIOF,GPIO_Pin_9 | GPIO_Pin_10); //置位，把pf组的9和10拉高
	GPIO_SetBits(GPIOE,GPIO_Pin_13|GPIO_Pin_14);//置为
}

/*
*led_ctr ：led控制函，决定具体的某个led的状态
*led_num ：决定具体的led
*state ：决定led的状态
*/
void led_ctr(int led_num,int state)
{
	switch (led_num)
	{
		case D1:
			if(state == ON) GPIO_ResetBits(GPIOF,GPIO_Pin_9 );//reset置0
			else 
			GPIO_SetBits(GPIOF,GPIO_Pin_9);
			break;
		case D2:
			if(state == ON ) GPIO_ResetBits(GPIOF,GPIO_Pin_10 );
			else
			GPIO_SetBits(GPIOF,GPIO_Pin_10);
			break;
		case D3:
			if(state == ON) GPIO_ResetBits(GPIOE,GPIO_Pin_13 );
			else
			GPIO_SetBits(GPIOE,GPIO_Pin_13);
			break;
		case D4:
			if(state == ON) GPIO_ResetBits(GPIOE,GPIO_Pin_14 );
			else
			GPIO_SetBits(GPIOE,GPIO_Pin_14);
			break;
	}
}

