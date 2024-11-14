/*
 * DIO_HW.h
 *
 * Created: 7/7/2020 6:34:37 AM
 *  Author: Mohmed
 */ 


#ifndef DIO_HW_H_
#define DIO_HW_H_
#include "STD_types.h"
#define  PORTA_reg (*((volatile uint8 *)0x3B))
#define  DDRA_reg (*((volatile uint8 *)0x3A))
#define  PINA_reg (*((volatile uint8 *)0x39))

#define  PORTB_reg (*((volatile uint8 *)0x38))
#define  DDRB_reg (*((volatile uint8 *)0x37))
#define  PINB_reg (*((volatile uint8 *)0x36))

#define  PORTC_reg (*((volatile uint8 *)0x35))
#define  DDRC_reg (*((volatile uint8 *)0x34))
#define  PINC_reg (*((volatile uint8 *)0x33))

#define  PORTD_reg (*((volatile uint8 *)0x32))
#define  DDRD_reg (*((volatile uint8 *)0x31))
#define  PIND_reg (*((volatile uint8 *)0x30))

#define UCSRA_reg (*((volatile uint8 *)0x2B))
#define UCSRB_reg (*((volatile uint8 *)0x2A))
#define UCSRC_reg (*((volatile uint8 *)0x40))
#define UBRRL_reg (*((volatile uint8 *)0x29))
#define UBRRH_reg (*((volatile uint8 *)0x40))
#define UDR_reg (*((volatile uint8 *)0x2C))

#define TWAR_reg (*((volatile uint8 *)0x22))
#define TWBR_reg (*((volatile uint8 *)0x20))
#define TWCR_reg (*((volatile uint8 *)0x56))
#define TWDR_reg (*((volatile uint8 *)0x23))
#define TWSR_reg (*((volatile uint8 *)0x21))


#endif /* DIO_HW_H_ */