#include "delay.h"
#include "sys.h"
#include "led.h"
#include "usart.h"
#include "key.h"
void ck()
{
	u8 len=0;
	u8 t;
	if(USART_RX_STA&0x8000)
	{
		len=USART_RX_STA&0x3fff;
		for(t=0;t<len;t++)
		{
			USART1->DR=USART_RX_BUF[t];
			while((USART1->SR&0x40)==0);
		}
		USART_RX_STA=0;
	}
}

void send(int key) {
	USART1->DR= key;
	while((USART1->SR&0x40)==0);
	
}
int main(void)
{
	//u8 t;
	u8 k=0;
	//u8 len;
	//u16 times=0;
	delay_init();
	led_init();
	key_init();
	LED0=0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	uart_init(9600);
	while(1)
	{
		//ck();
		k=KEY_Scan(0);
	
		switch(k)
		{
			case 1:
				LED0=!LED0;
				send(1);
				break;
			case 2:
				LED1=!LED1;
				send(2);
				break;
			case 3:
				LED0=!LED0;
				LED1=!LED1;
				send(3);
				break;
			default:
				delay_ms(10);
		}
	}
}

