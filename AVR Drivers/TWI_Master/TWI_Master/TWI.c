/*
 * TWI.c
 *
 * Created: 8/13/2020 10:06:06 AM
 *  Author: Mohmed
 */ 
#include "TWI.h"



void TW_init(uint8 My_Add){
	TWBR_reg=TWBR_VAL;
	TWI_MY_ADRESS(My_Add);
	TWCR_reg |= (1<<DIO_TWEN) |(1<<DIO_TWINT);
	
}

unsigned char TWI_start(){
	
	TWCR_reg |= (1<<DIO_TWEN) | (1<<DIO_TWINT) | (1<<DIO_TWSTA) ;
	while (!(TWCR_reg&(1<<DIO_TWINT)));
	return (TWI_status());
}

void TWI_stop(){
	TWCR |=(1<<DIO_TWEN) | (1<<DIO_TWINT) | (1<<DIO_TWSTO);
	
}

void TWI_MY_ADRESS(unsigned char add){
	TWAR_reg= add;
}


unsigned char TWI_status(){
	return (TWSR_reg & (0xF8));
}

unsigned char TWI_DATA(unsigned char data){
	TWDR_reg=data;
	TWCR_reg = (1<<DIO_TWINT) | (1<<DIO_TWEN);
	
	while (!(TWCR_reg&(1<<DIO_TWINT)));
	return (TWI_status());
}

