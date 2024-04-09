#include "control.h"
#include "stm32f4xx.h"
#include "car.h"

void control_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	//时钟使能
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);

	//使能GPIO
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOC, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN; 
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOG, &GPIO_InitStruct);

	//默认状态
	GPIO_ResetBits(GPIOC,GPIO_Pin_6);
	GPIO_ResetBits(GPIOG,GPIO_Pin_15);


}

void control_run(void)
{
    if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6) == 0 && GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15) == 0)
    {
        car_up();
		for(int i=0;i<10;++i){for(int j=0;j<100;++j);}
		car_stop();
		for(int i=0;i<10;++i){for(int j=0;j<20;++j);}
    }
    else if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6) == 1 && GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15) == 0)
    {
        car_left();
		for(int i=0;i<5;++i){for(int j=0;j<100;++j);}
		car_stop();
		for(int i=0;i<1;++i){for(int j=0;j<10;++j);}
    }
    else if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6) == 0 && GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15) == 1)
    {
        car_right();
		for(int i=0;i<5;++i){for(int j=0;j<100;++j);}
		car_stop();
		for(int i=0;i<1;++i){for(int j=0;j<10;++j);}
    }
    else
    {
        car_stop();
    }
}

void control_avoid(void)
{
	if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6) == 1 && GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15) == 1)
    {
       car_up();

    }
	else if (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6) == 1 && GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15) == 0) 
	{

	   	car_back();
	   	for(int i=0;i<5000;++i){for(int j=0;j<6000;++j);}
	   	car_left();		
	   	for(int i=0;i<3000;++i){for(int j=0;j<6000;++j);}
	}
	else if (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6) == 0 && GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15) == 1) 
	{

		car_back();
		for(int i=0;i<5000;++i){for(int j=0;j<6000;++j);}
		car_right();
		for(int i=0;i<3000;++i){for(int j=0;j<6000;++j);}
	}
	else
	{
		car_stop();
		for(int i=0;i<5;++i){for(int j=0;j<100;++j);}
	}
}

