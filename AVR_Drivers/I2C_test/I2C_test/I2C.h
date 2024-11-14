/*
 * I2C.h
 *
 * Created: 7/18/2023 5:45:02 PM
 *  Author: moham
 */ 


#ifndef I2C_H_
#define I2C_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define true 1
#define PS 1
#define TWI_MAX_SCL 400000
#define TWBR_VAL (((F_CPU/TWI_MAX_SCL)-16)*0.5*(1/(4^PS)))


void TW_init(unsigned char My_Add);
unsigned char TWI_start();
void TWI_stop();
void TWI_MY_ADRESS(unsigned char add);
unsigned char TWI_status();
unsigned char TWI_DATA(unsigned char data);


#endif 