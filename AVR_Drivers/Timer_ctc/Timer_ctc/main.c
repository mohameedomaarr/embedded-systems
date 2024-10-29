/*
 * Timer_ctc.c
 *
 * Created: 7/7/2023 2:59:34 AM
 * Author : moham
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned short OVF_count = 0 ;



int main(void)
{
	DDRC |= (1<<7)|(1<<2);
	PORTC &=~ (1<<7);
	
	TCCR0 |= (1<<CS00)|(1<<CS01)|(1<<WGM01);
	//TCNT0 = 0x6F;
	TIMSK |= (1<<TOIE0)|(1<<OCIE0);
	sei();
	OCR0 = 143;
	/* Replace with your application code */
	while (1)
	{
	}
}


ISR(TIMER0_COMP_vect){
	
	if (OVF_count==976)
	{
		PORTC ^= (1<<7);
		OVF_count=0;
	}
	//_delay_ms(1000);
}

ISR(TIMER0_OVF_vect){
	OVF_count++;
	
	//PORTC ^=(1<<2);
}


