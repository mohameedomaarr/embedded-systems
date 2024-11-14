/*
 * TWI.h
 *
 * Created: 8/13/2020 10:06:17 AM
 *  Author: Mohmed
 */ 


#ifndef TWI_H_
#define TWI_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "DIO.h"

#define true 1
#define PS 1
#define TWI_MAX_SCL 400000
#define TWBR_VAL (((F_CPU/TWI_MAX_SCL)-16)*0.5*(1/(4^PS)))


void TW_init(unsigned char My_Add);
uint8 TWI_start();
void TWI_stop();
void TWI_MY_ADRESS(unsigned char add);
uint8 TWI_status();
uint8 TWI_DATA(unsigned char data);



#endif /* TWI_H_ */