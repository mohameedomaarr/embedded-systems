/*
 * UART.h
 *
 * Created: 7/11/2023 4:20:43 AM
 *  Author: moham
 */ 


#ifndef UART_H_
#define UART_H_
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

#define budrate 9600
//#define double_speed
#ifndef double_speed
#define UBRR_VALUE ((F_CPU/(16UL*budrate))-1) //
#else
#define UBRR_VALUE ((F_CPU/(8UL*budrate))-1) //
#endif

void UART_INT(void);
void UART_SENDCHAR(char data);
void UART_SENDSTRING(char * data);
char UART_RX(void);



#endif /* UART_H_ */