/*
 * DIO_HW.h
 *
 * Created: 6/21/2023 9:58:16 PM
 *  Author: moham
 */ 


#ifndef DIO_HW_H_
#define DIO_HW_H_

#include "std_types.h"

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


#endif /* DIO_HW_H_ */