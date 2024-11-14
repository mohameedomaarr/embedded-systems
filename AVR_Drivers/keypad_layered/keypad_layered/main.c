/*
 * keypad_layered.c
 *
 * Created: 7/3/2023 5:54:40 AM
 * Author : moham
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	DDRA |= (1<<4)|(1<<5)|(1<<6)|(1<<7);
	DDRB |= (1<<1)|(1<<2);
	unsigned char count =0;
	unsigned char data =0;
    /* Replace with your application code */
    while (1) 
    {
		for(count=0;count<10;count++){
			for(data=0 ; data<10;data++){
				PORTA = (PORTA & 0x0F)|(data<<4);
				PORTB |= (1<<1);
				_delay_ms(200);
				PORTB &=~ (1<<1);
				_delay_ms(500);
				PORTA = (PORTA & 0x0F)|(count<<4);
				PORTB |= (1<<2);
				_delay_ms(300);
				PORTB &=~ (1<<2);
			}
			
		}
    }
}

