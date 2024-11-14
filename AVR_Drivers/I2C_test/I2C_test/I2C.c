/*
 * I2C.c
 *
 * Created: 7/18/2023 5:44:47 PM
 *  Author: moham
 */ 

#include "I2C.h"


void TW_init(unsigned char My_Add){
	TWBR=TWBR_VAL;
	TWI_MY_ADRESS(My_Add);
	TWCR = (1<<TWEN)|(1<<TWINT);
}

unsigned char TWI_start(){
	TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWSTA);
	while (!(TWCR&(1<<TWINT)));
	return true;
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
	return true;
}