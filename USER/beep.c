#include "beep.h"
#include "stm32f4xx.h"

//beep 初始化函数
void beep_init(void)
{
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

	//2、配置GPIO引脚
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; //控制引脚的高低电平是输出
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;//既要输出高点平，又要输出低电平，所以是推挽输出
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;//对应的是PF第8个
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//一般是50mhz
	GPIO_Init( GPIOF, &GPIO_InitStruct);//初始化串口

	//3、默认状态=>	不叫
	GPIO_ResetBits(GPIOF,GPIO_Pin_8); //置位，把pf组的8拉高
}

// beep 状态
void beep_state(int state)
{
	switch (state)
		{
		case ON:
			GPIO_SetBits(GPIOF,GPIO_Pin_8);
			break;
		case OFF:
			GPIO_ResetBits(GPIOF,GPIO_Pin_8);
			break;
		}


}

