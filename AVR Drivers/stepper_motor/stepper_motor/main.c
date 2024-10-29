/*
 * stepper_motor.c
 *
 * Created: 7/9/2023 9:44:07 AM
 * Author : moham
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void stepper_control(unsigned char angle){
	switch(angle){
		case 1:
		PORTD |= (1<<0)|(1<<1);
		PORTD &=~ (1<<2)|(1<<3);
		break;
		case 2:
		PORTD |= (1<<1)|(1<<2);
		PORTD &=~ (1<<0)|(1<<3);
		break;
		case 3:
		PORTD |= (1<<2)|(1<<3);
		PORTD &=~ (1<<1)|(1<<0);
		break;
		case 4:
		PORTD |= (1<<3)|(1<<0);
		PORTD &=~ (1<<2)|(1<<1);
		break;
	}
}


int main(void)
{
    DDRD |= (1<<0)|(1<<1)|(1<<2)|(1<<3);
    while (1) 
    {
		stepper_control(1);
		_delay_ms(2000);
		stepper_control(2);
		_delay_ms(2000);
		stepper_control(3);
		_delay_ms(2000);
		stepper_control(4);
		_delay_ms(2000);
    }
}

