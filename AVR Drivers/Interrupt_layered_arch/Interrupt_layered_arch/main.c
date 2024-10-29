/*
 * Interrupt_layered_arch.c
 *
 * Created: 7/6/2023 3:45:23 AM
 * Author : moham
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
	MCUCR |= (1<<ISC00) | (1<<ISC01) ;
	GICR |= (1<<INT0);
	sei();
	DDRC |= (1<<1);
	DDRD &=~ (1<<2);

	PORTC &=~ (1<<1);
	while (1)
	{
		
	}
}

ISR(INT0_vect){
	PORTC ^= (1<<1);
}

