/*
 * GccApplication1.c
 *
 * Created: 6/20/2023 12:42:39 AM
 * Author : mohamed
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DDRC |= (1<<7);
	DDRD &=~(1<<2);
    /* Replace with your application code */
    while (1) 
    {
		if (((PIND>>2)&1) == 1)
		{
			_delay_ms(30);
			PORTC |= (1<<7);
			_delay_ms(100);
		}
		
		
		
    }
}

