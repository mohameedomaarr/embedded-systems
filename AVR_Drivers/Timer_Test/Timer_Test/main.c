/*
 * Timer_Test.c
 *
 * Created: 7/6/2023 6:50:26 AM
 * Author : mohamed
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned short OVF_count = 0 ;



int main(void)
{
	DDRC |= (1<<7);
	//PORTC &=~ (1<<7);
	//TIMSK |= (1<<TOIE0);
	TIMSK |= (1<<OCIE0);
	//TCNT0 = 0x6F;
	TCCR0 |= (1<<CS00)|(1<<CS01);
	sei();
	//PORTC|=(1<<7);
	
	OCR0 = 143;
	/* Replace with your application code */
	while (1)
	{
	}
}



/*ISR(TIMER0_OVF_vect){
	OVF_count++;

	if(OVF_count==977){
	PORTC ^= (1<<7);
	OVF_count = 0;
	TCNT0 = 0x6F;
		}
}*/

ISR(TIMER0_COMP_vect){
	OVF_count++;
	if(OVF_count==976){
		PORTC ^= (1<<7);
		OVF_count = 0;
	}
}