#include "sys.h"
#include "delay.h"
#include "led.h"
void led_init()
{
		GPIO_InitTypeDef GPIO_InitStruct;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD,ENABLE);
		delay_init();
		GPIO_InitStruct.GPIO_Pin=GPIO_Pin_8;
		GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
		GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(GPIOA,&GPIO_InitStruct);
		GPIO_SetBits(GPIOA,GPIO_Pin_8);
		GPIO_InitStruct.GPIO_Pin=GPIO_Pin_2;
		GPIO_Init(GPIOD,&GPIO_InitStruct);
		GPIO_SetBits(GPIOD,GPIO_Pin_2);
}
