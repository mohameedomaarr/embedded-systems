/*
 * I2C.c
 *
 * Created: 7/19/2023 1:07:30 PM
 *  Author: moham
 */ 
#include "TWI.h"


void TW_init(unsigned char My_Add){
	TWBR=TWBR_VAL;
	TWI_MY_ADRESS(My_Add);
	TWCR = (1<<TWEN)|(1<<TWINT);
}

unsigned char TWI_start(){
	TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWSTA);
	while (!(TWCR&(1<<TWINT)));
	return (TWI_status());
}

void TWI_stop(){
	TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWSTO);
}

void TWI_MY_ADRESS(unsigned char add){
	TWAR= add;
}


unsigned char TWI_status(){
	return (TWSR & (0xF8));
}

unsigned char TWI_DATA(unsigned char data){
	TWDR=data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR&(1<<TWINT)));
	return (TWI_status());
}

unsigned char TWI_READACK(){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (!(TWCR&(1<<TWINT)));
	return (TWI_status());
}

unsigned char TWI_recived(){
	return TWDR;
}