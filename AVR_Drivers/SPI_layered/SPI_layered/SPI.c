/*
 * SPI.c
 *
 * Created: 8/7/2020 6:11:46 PM
 *  Author: Mohmed
 */ 

#include "SPI.h"

void SPI_INT(SPI_CONFIG * Config){
	switch(Config->state){
		case Master:
		set_bit(SPI_DIR,SS);
		set_bit(SPI_DIR,MOSI);
		set_bit(SPI_DIR,CLK);
		reset_bit(SPI_DIR,MISO);	
		slave_DIS();
		SPI->SPCR_reg.Master=1;
		break;
		case Slave:
		reset_bit(SPI_DIR,SS);
		reset_bit(SPI_DIR,MOSI);
		reset_bit(SPI_DIR,CLK);
		set_bit(SPI_DIR,MISO);
		break;
	}
		
	switch(Config->prescale){
		case OSC4:
		
		break;
		case OCS16:
		SPI->SPCR_reg.ps0 =1;
		break;
	}	
	
	//SPCR |= (1<<SPE)|(1<<SPR0)|(1<<MSTR);
	//set_bit(SPCR,SPE);
	
	SPI->SPCR_reg.EN=1;	
}

char SPI_TX_RX(char data){
	//SPDR = data;
	SPI->SPDR_reg = data;
	//while(!(SPSR &(1<<SPIF)));
	while((SPI->SPSR_reg.PIF)==0);
	return SPI->SPDR_reg;
	}