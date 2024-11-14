/*
 * input_capture.c
 *
 * Created: 7/9/2023 2:05:40 PM
 * Author : moham
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	TIMSK |= (1<<TICIE1);
	DDRC |= (1<<3);
	DDRD &=~ (1<<6);
	PIND &=~ (1<<6);
	TCCR1B |= (1<<ICES1);
	TCCR1B |= (1<<CS10)|(1<<CS11);
	sei();
    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR(TIMER1_CAPT_vect){
	PORTC ^= (1<<3);
	
}