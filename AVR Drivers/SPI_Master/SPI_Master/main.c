/*
 * SPI_Master.c
 *
 * Created: 7/14/2023 6:05:07 AM
 * Author : moham
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "bit_math.h"
#include "util/delay.h"

#define SPI_DIR DDRB
#define SPI_PORT PORTB

#define SS 4
#define MOSI 5
#define MISO 6
#define CLK 7
#define slave_EN() (reset_bit(SPI_PORT,SS))
#define slave_DIS() (set_bit(SPI_PORT,SS))

void SPI_INT(char control);
char SPI_TX_RX(char data);


int main(void)
{
	DDRC |=(1<<1);
	SPI_INT('M');
	slave_EN();
	while (1)
	{
	
		if (SPI_TX_RX('2')==0x55)
		{
			PORTC ^=(1<<1);
			_delay_ms(500);
		}
	}
}

void SPI_INT(char control){
	switch(control){
		case 'M':
		set_bit(SPI_DIR,SS);
		set_bit(SPI_DIR,MOSI);
		set_bit(SPI_DIR,CLK);
		reset_bit(SPI_DIR,MISO);
		break;
		case'S':
		reset_bit(SPI_DIR,SS);
		reset_bit(SPI_DIR,MOSI);
		reset_bit(SPI_DIR,CLK);
		set_bit(SPI_DIR,MISO);
		break;
	}
	slave_DIS();
	SPCR |= (1<<SPE)|(1<<SPR0)|(1<<MSTR);
	
	//set_bit(SPCR,SPE);
	
}
char SPI_TX_RX(char data){
	SPDR = data;
	while(!(SPSR &(1<<SPIF)));
	return SPDR;
}