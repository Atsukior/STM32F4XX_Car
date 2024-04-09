#include "led_ctrl.h"
#include "stm32f4xx.h"

//led ��ʼ������
void led_init(void)
{
	
	//1��ʱ��ʹ�� PF9 PF10 PE13 PE14
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	//2������GPIO����
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; //�������ŵĸߵ͵�ƽ�����
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;//��Ҫ����ߵ�ƽ����Ҫ����͵�ƽ���������������
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;//��Ӧ����PF��9���͵�ʮ��pin��
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//һ����50mhz
	GPIO_Init( GPIOF, &GPIO_InitStruct);//��ʼ������

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOE, &GPIO_InitStruct);

	//3��Ĭ��״̬=>��
	GPIO_SetBits(GPIOF,GPIO_Pin_9 | GPIO_Pin_10); //��λ����pf���9��10����
	GPIO_SetBits(GPIOE,GPIO_Pin_13|GPIO_Pin_14);//��Ϊ
}

/*
*led_ctr ��led���ƺ������������ĳ��led��״̬
*led_num �����������led
*state ������led��״̬
*/
void led_ctr(int led_num,int state)
{
	switch (led_num)
	{
		case D1:
			if(state == ON) GPIO_ResetBits(GPIOF,GPIO_Pin_9 );//reset��0
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

