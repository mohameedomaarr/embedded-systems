/*
 * DC_motor.c
 *
 * Created: 7/8/2023 10:00:16 AM
 * Author : moham
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>


int main(void)
{
	DDRC |= (1<<3)|(1<<4)|(1<<0)|(1<<1);
	DDRD |= (1<<4)|(1<<5);
	TCCR1A |= (1<<COM1A1)|(1<<COM1B1);
	TCCR1A |= (1<<WGM10);
	TCCR1B |= (1<<WGM12);
	TCCR1B |= (1<<CS10)|(1<<CS11);
	PORTC |= (1<<3);
	OCR1AL = 150;
	OCR1BL =150;
//rotation direction clockwise
	//PORTC &=~(1<<4);
	//PORTC |=(1<<3);
//rotation counter clockwise
	PORTC |=(1<<4);
	PORTC &=~(1<<3); 
    /* Replace with your application code */
	//rotation direction
	PORTC |=(1<<0);
	PORTC &=~(1<<1);
    while (1) 
    {
    }
}

