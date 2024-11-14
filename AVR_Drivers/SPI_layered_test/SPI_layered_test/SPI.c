/*
 * SPI.c
 *
 * Created: 7/16/2023 10:13:13 AM
 *  Author: moham
 */ 
#include "SPI.h"

void SPI_Init(SPI_CONFIG * Config){

	switch(Config->state){
		case Master:
		SPI->SPI_SPCR.MASTER=1;//SPCR |= (1<<MSTR);
		set_bit(SPI_DDR,SS);
		set_bit(SPI_DDR,MOSI);
		set_bit(SPI_DDR,SCK);
		reset_bit(SPI_DDR,MISO);
		break;
		case Slave:
		SPI->SPI_SPCR.MASTER=0;//SPCR &=~ (1<<MSTR);
		reset_bit(SPI_DDR,SS);
		reset_bit(SPI_DDR,MOSI);
		reset_bit(SPI_DDR,SCK);
		set_bit(SPI_DDR,MISO);
		break;
	}
	
	switch(Config->prescale){
		case OSC4:
		
		break;
		case OCS16:
		SPI->SPI_SPCR.PS0 =1;
		break;
	}
	
	Slave_Disable();
	SPI->SPI_SPCR.EN=1;//SPCR |= (1<<SPE)|(1<<SPR0);
	SPI->SPI_SPCR.PS0=1;
}

char Tx_Rx(char data){
	
	SPI->SPI_SPDR=data;//SPDR = data;
	while(!(SPI->SPI_SPSR.PIF_REG));
	return SPI->SPI_SPDR;
}