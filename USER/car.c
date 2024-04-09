#include "car.h"
#include "stm32f4xx.h"

void motor_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	//时钟使能
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	//使能GPIO
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOB, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOD, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOA, &GPIO_InitStruct);

	//默认状态：不转
	GPIO_SetBits(GPIOB,GPIO_Pin_7);
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
	GPIO_SetBits(GPIOD,GPIO_Pin_6);
	GPIO_SetBits(GPIOD,GPIO_Pin_7);
	
}

void car_up(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_7);
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);

	GPIO_ResetBits(GPIOD,GPIO_Pin_6);
	GPIO_SetBits(GPIOD,GPIO_Pin_7);
}

void car_back(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);
	GPIO_SetBits(GPIOA,GPIO_Pin_4);

	GPIO_SetBits(GPIOD,GPIO_Pin_6);
	GPIO_ResetBits(GPIOD,GPIO_Pin_7);
}

void car_left(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_7);
	GPIO_SetBits(GPIOA,GPIO_Pin_4);

	GPIO_ResetBits(GPIOD,GPIO_Pin_6);
	GPIO_SetBits(GPIOD,GPIO_Pin_7);
}


void car_right(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_7);
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);

	GPIO_SetBits(GPIOD,GPIO_Pin_6);
	GPIO_ResetBits(GPIOD,GPIO_Pin_7);
}

void car_stop(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_7);
	GPIO_SetBits(GPIOA,GPIO_Pin_4);

	GPIO_SetBits(GPIOD,GPIO_Pin_6);
	GPIO_SetBits(GPIOD,GPIO_Pin_7);
}


