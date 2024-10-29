/*
 * wave_gen.c
 *
 * Created: 7/7/2023 5:43:38 AM
 * Author : moham
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char arr[2] = {10,200} ;

volatile unsigned char flag=0;

int main(void)
{
	//DDRC |= (1<<7);
	//PORTC &=~ (1<<7);
	DDRB |= (1<<3);
	OCR0=arr[flag];
	TCCR0 |= (1<<CS00)|(1<<COM00);
	TIMSK = (1<<OCIE0);
	sei();
	while (1)
	{
	}
}





ISR(TIMER0_COMP_vect ){
	
	if (flag == 1)
	{
		OCR0 = arr[flag];
		flag=0;
	}
	else
	{
		OCR0 = arr[flag];
		flag=1;
	}
}
