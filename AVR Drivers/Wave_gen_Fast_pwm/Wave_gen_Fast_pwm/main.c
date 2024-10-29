/*
 * Wave_gen_Fast_pwm.c
 *
 * Created: 7/7/2023 8:35:20 AM
 * Author : moham
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>



int main(void)
{
	//DDRC |= (1<<7);
	//PORTC &=~ (1<<7);
	DDRB |= (1<<3);
	TCCR0 |= (1<<CS00)|(1<<COM00)|(1<<COM01)|(1<<WGM00)|(1<<WGM01);
	TIMSK = (1<<OCIE0);
	OCR0=63;
	//sei();
	while (1)
	{
	}
}



/*

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
*/
