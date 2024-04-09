#include "beep.h"
#include "stm32f4xx.h"

//beep ��ʼ������
void beep_init(void)
{
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

	//2������GPIO����
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; //�������ŵĸߵ͵�ƽ�����
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;//��Ҫ����ߵ�ƽ����Ҫ����͵�ƽ���������������
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;//��Ӧ����PF��8��
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//һ����50mhz
	GPIO_Init( GPIOF, &GPIO_InitStruct);//��ʼ������

	//3��Ĭ��״̬=>	����
	GPIO_ResetBits(GPIOF,GPIO_Pin_8); //��λ����pf���8����
}

// beep ״̬
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

