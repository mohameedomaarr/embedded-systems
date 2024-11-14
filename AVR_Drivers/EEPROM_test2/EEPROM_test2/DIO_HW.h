/*
 * DIO_HW.h
 *
 * Created: 7/7/2020 2:21:24 PM
 *  Author: youus
 */ 

#include "STD_Types.h"

#ifndef DIO_HW_H_
#define DIO_HW_H_

// PORTS,DDR
#define PORTA       (*((volatile Uint8 *)0x3B))
#define DDRA        (*((volatile Uint8 *)0x3A))
#define PINA        (*((volatile Uint8 *)0x39))

#define PORTB       (*((volatile Uint8 *)0x38))
#define DDRB        (*((volatile Uint8 *)0x37))
#define PINB        (*((volatile Uint8 *)0x36))

#define PORTC       (*((volatile Uint8 *)0x35))
#define DDRC        (*((volatile Uint8 *)0x34))
#define PINC        (*((volatile Uint8 *)0x33))

#define PORTD       (*((volatile Uint8 *)0x32))
#define DDRD        (*((volatile Uint8 *)0x31))
#define PIND        (*((volatile Uint8 *)0x30))

//UART
#define UBRRH      (*((volatile Uint8 *)0x40))
#define UCSRC      (*((volatile Uint8 *)0x40))
#define UCSRA      (*((volatile Uint8 *)0x2B))
#define UCSRB      (*((volatile Uint8 *)0x2A))
#define UBRRL      (*((volatile Uint8 *)0x29))
#define UDR        (*((volatile Uint8 *)0x2C))


//16_bit timer
#define TCCR1A      (*((volatile Uint8 *)0x4F))
#define TCCR1B      (*((volatile Uint8 *)0x4E))
#define TCNT1H      (*((volatile Uint8 *)0x4D))
#define TCNT1L      (*((volatile Uint8 *)0x4C))
#define OCR1AH      (*((volatile Uint8 *)0x4B))
#define OCR1AL      (*((volatile Uint8 *)0x4A))
#define OCR1BH      (*((volatile Uint8 *)0x49))
#define OCR1BL      (*((volatile Uint8 *)0x48))
#define ICR1H       (*((volatile Uint8 *)0x47))
#define ICR1L       (*((volatile Uint8 *)0x46))
#define TIMSK       (*((volatile Uint8 *)0x59))
#define TIFR        (*((volatile Uint8 *)0x58))


//SPI
#define SPDR        (*((volatile Uint8 *)0x2F))
#define SPSR        (*((volatile Uint8 *)0x2E))
#define SPCR        (*((volatile Uint8 *)0x2D))


//TWI
#define TWBR        (*((volatile Uint8 *)0x20))
#define TWSR        (*((volatile Uint8 *)0x21))
#define TWAR        (*((volatile Uint8 *)0x22))
#define TWDR        (*((volatile Uint8 *)0x23))
#define TWCR        (*((volatile Uint8 *)0x56))




#endif /* DIO_HW_H_ */