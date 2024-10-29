/*
 * UART.c
 *
 * Created: 7/11/2023 4:20:29 AM
 *  Author: moham
 */ 
#include "UART.h"
void UART_INT(void){
	
	
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC =(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRL=UBRR_VALUE;
	UBRRH=UBRR_VALUE>>8;
}
void UART_SENDCHAR(char data){
	
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
}
void UART_SENDSTRING(char * data){
	char i=0;
	while(data[i]!='\0'){
		UART_SENDCHAR(data[i]);
		i++;
	}
}
char UART_RX(void){
	
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}