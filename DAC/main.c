#include "stm32f10x.h"                  // Device header
#include "delay.h"



void pin_init(void);
void dac_init(void);

int main()
{

	delay_init();
	pin_init();
	dac_init();
	
  
	
	while(1)
	{
		
		
		 DAC->DHR12R1 =0;
		 delay_ms(20);
		 DAC->DHR12R1 =1000;
		delay_ms(20);
		 DAC->DHR12R1 =2047;
		delay_ms(20);
		 DAC->DHR12R1 =3047;
		delay_ms(20);
		 DAC->DHR12R1 =4095;
		delay_ms(20);
		
	}



}

void pin_init()  //pa4 dac channel 1
{
	
	RCC->APB2ENR  |=1<<2;//A portu enable.
	GPIOA->CRL =0;
	GPIOA->CRL = 0x22202222;//PA4 ANALOG INPUT
	
	

}

void dac_init()
{

	RCC->APB1ENR |=1<<29;//DAC enable.	
	DAC->CR       &=~(1<<1);//Buffer ENABLE..
	DAC->CR       |=1<<0;//Enable.
	

}

