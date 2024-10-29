/*
 * UART.c
 *
 * Created: 7/11/2023 4:20:13 AM
 * Author : moham
 */ 
#include "UART.h"


int main(void)
{
	UART_INT();
	DDRC |=(1<<7);
	
	
	UART_SENDSTRING("welcome in amit \r\n");
	while (1)
	{
		if(UART_RX() == '1'){
			PORTC |=(1<<7);
		}
		if(UART_RX() == '2')
		{
			
			PORTC &=~ (1<<7);
		}
		
	}
	
	/*while(1){
	UART_SENDCHAR('M');
	_delay_ms(1000);	
	}*/
}


