/*
 * ADC_layered_arch.c
 *
 * Created: 7/4/2023 1:56:30 AM
 * Author : moham
 */ 

volatile unsigned char flag=0;

#include <avr/io.h>
#include "ADC.h"
#include "LCD.h"
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>



int main(void)
{

    char buffer[100];
	unsigned short temp =0;
    DIO_Init();
	LCD_init();
	ADC_Init();

	//interrupt_init
	MCUCR |= (1<<ISC00) | (1<<ISC01) ;
	GICR |= (1<<INT0);
	sei();
	DDRD &=~ (1<<2);
	PIND &=~ (1<<2);
	////interrupt_init

	
	
	
    while (1) 
    {
		while(!(flag));
		temp = ADC_read(0x01);
		temp=temp/4;
		itoa(temp,buffer,10);
		LCD_string("current temp ");
		LCD_string(buffer);
		_delay_ms(2000);
		LCD_Command(0x01);		
		flag=0;
		
		
    }
}

ISR(INT0_vect){
	flag=1;
}
