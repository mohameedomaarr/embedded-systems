/*
 * SPI_slave_test.c
 *
 * Created: 7/16/2023 8:36:52 AM
 * Author : moham
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "bit_math.h"
#include "util/delay.h"



void SPI_Init(char status);
char Tx_Rx(char data);

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

#define Slave_Enable() (reset_bit(PORTB,SS))
#define Slave_Disable() (set_bit(PORTB,SS))

int main(void)
{
	DDRC |= (1<<1);
	SPI_Init('S');
	
	
	while (1)
	{
		if ((Tx_Rx(0x22))==(0x55))
		{
			PORTC ^= (1<<1);
			
		}
		
	}
}

void SPI_Init(char status){
	
	switch(status){
		case 'M':
		SPCR |= (1<<MSTR);
		set_bit(DDRB,SS);
		set_bit(DDRB,MOSI);
		set_bit(DDRB,SCK);
		reset_bit(DDRB,MISO);
		break;
		case 'S':
		SPCR &=~ (1<<MSTR);
		reset_bit(DDRB,SS);
		reset_bit(DDRB,MOSI);
		reset_bit(DDRB,SCK);
		set_bit(DDRB,MISO);
		break;
	}

	SPCR |= (1<<SPE);
}

char Tx_Rx(char data){
	SPDR = data;
	while(!(SPSR &(1<<SPIF)));
	return SPDR;
}