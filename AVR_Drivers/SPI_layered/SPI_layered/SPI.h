/*
 * SPI.h
 *
 * Created: 8/7/2020 6:11:27 PM
 *  Author: Mohmed
 */ 


#ifndef SPI_H_
#define SPI_H_

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



typedef struct{
	unsigned char ps0:1;
	unsigned char BIT1:1;
	unsigned char BIT2:1;
	unsigned char BIT3:1;
	unsigned char Master:1;
	unsigned char BIT5:1;
	unsigned char EN:1;
	unsigned char IE:1;
	}SPCR_bits;
	
	typedef struct{
		unsigned char BIT0:1;
		unsigned char BIT1:1;
		unsigned char BIT2:1;
		unsigned char BIT3:1;
		unsigned char BIT4:1;
		unsigned char BIT5:1;
		unsigned char BIT6:1;
		unsigned char PIF:1;
	}SPSR_bits;

typedef struct{
	SPCR_bits SPCR_reg;
	SPSR_bits SPSR_reg;
	unsigned char SPDR_reg;
	}SPI_reg;
	
typedef enum{
	Master,
	Slave
	}SPI_status;
	
typedef enum{
	OSC4=4,
	OCS16=16
}SPI_prescale;	
	
	
typedef struct{
	SPI_status state;
	SPI_prescale prescale;
	
	}SPI_CONFIG;	

#define SPI ((volatile SPI_reg*const)(0x2D))
#define slave_EN() (reset_bit(SPI_PORT,SS))
#define slave_DIS() (set_bit(SPI_PORT,SS))

char SPI_TX_RX(char data);
void SPI_INT(SPI_CONFIG * Config);


#endif /* SPI_H_ */