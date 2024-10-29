/*
 * RTOS_test2.c
 *
 * Created: 7/31/2023 4:43:58 AM
 * Author : moham
 */ 


#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "UART.h"
void uart1( void * pv);
void uart2( void * pv);

int main(void)
{
	UART_INT();
	DDRC |= (1<<2)|(1<<3)|(1<<4);
	DDRD &=~ (1<<2) ;
	volatile char * pv ="test1\n\r";
	volatile char * ps ="test2\n\r";
	xTaskCreate(uart1,"uart1",500,(void *)pv,3,NULL);
	xTaskCreate(uart2,"uart1",500,(void *)ps,1,NULL);
	//xTaskCreate(LED2,"LED2",50,NULL,1,NULL);
	//xTaskCreate(LED3,"LED3",50,NULL,1,NULL);
	vTaskStartScheduler();
	while (1)
	{
	}
}

void uart1( void * pv){
	
	
	while (1)
	{
		UART_SENDSTRING(pv);
		vTaskDelay(150/portTICK_PERIOD_MS);
	}
}

void uart2( void * pv){
	
	
	while (1)
	{
		UART_SENDSTRING(pv);
		vTaskDelay(150/portTICK_PERIOD_MS);
	}
}