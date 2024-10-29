/*
 * SPI.h
 *
 * Created: 7/16/2023 10:13:01 AM
 *  Author: moham
 */ 


#ifndef SPI_H_
#define SPI_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include "bit_math.h"
#include "util/delay.h"



#define  SPI_port PORTB
#define  SPI_DDR  DDRB

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

#define Slave_Enable() (reset_bit(SPI_port,SS))
#define Slave_Disable() (set_bit(SPI_port,SS))
typedef struct{
	unsigned char PS0:1;
	unsigned char bit1:1;
	unsigned char bit2:1;
	unsigned char bit3:1;
	unsigned char MASTER:1;
	unsigned char bit5:1;
	unsigned char EN:1;
	unsigned char IE:1;
}SPCR_reg;


typedef struct{
	unsigned char BIT0:1;
	unsigned char BIT1:1;
	unsigned char BIT2:1;
	unsigned char BIT3:1;
	unsigned char BIT4:1;
	unsigned char BIT5:1;
	unsigned char BIT6:1;
	unsigned char PIF_REG:1;
}SPSR_bits;

typedef struct  
{
	SPCR_reg SPI_SPCR;
	SPSR_bits SPI_SPSR;
	unsigned char SPI_SPDR;

}SPI_reg;

	
	typedef enum{
		Master,
		Slave
	}SPI_status;
	
	typedef enum{
		OSC4,
		OCS16
	}SPI_prescale;
	
	
	typedef struct{
		SPI_status state;
		SPI_prescale prescale;
		
	}SPI_CONFIG;



#define SPI ((volatile SPI_reg * const)(0x2D))
void SPI_Init(SPI_CONFIG * Config);
char Tx_Rx(char data);

#endif /* SPI_H_ */