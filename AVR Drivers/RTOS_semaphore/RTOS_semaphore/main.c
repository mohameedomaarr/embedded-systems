/*
 * RTOS_semaphore.c
 *
 * Created: 9/10/2023 2:32:50 PM
 * Author : moham
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "FreeRTOS.h"
#include "UART.h"
#include "task.h"
#include "semphr.h"
void printTask1(void * string);
void printTask2(void * string);
void printTask3(void * string);
SemaphoreHandle_t xSemaphore;

int main(void)
{
	UART_INT();
	xSemaphore = xSemaphoreCreateMutex();
	xTaskCreate(printTask1,"print1",200,(void *)"print1\r\n",1,NULL);
	xTaskCreate(printTask2,"print2",200,(void *)"print2\r\n",2,NULL);
	xTaskCreate(printTask3,"print3",200,(void *)"print3\r\n",3,NULL);
	vTaskStartScheduler();
	xSemaphoreGive(xSemaphore);
    /* Replace with your application code */
    while (1) 
    {
    }
}


void printTask1(void * string){
	while(1){
		xSemaphoreTake(xSemaphore,500/ portTICK_PERIOD_MS);
		UART_SENDSTRING((char *)string) ;
		xSemaphoreGive(xSemaphore);
		vTaskDelay(500/ portTICK_PERIOD_MS);
	}
}

void printTask2(void * string){
	
	while(1){
		xSemaphoreTake(xSemaphore,500/ portTICK_PERIOD_MS);
		UART_SENDSTRING((char *)string) ;
		//_delay_ms(200);
		xSemaphoreGive(xSemaphore);
		vTaskDelay(500/ portTICK_PERIOD_MS);
	}
}

void printTask3(void * string){
	
	while(1){
		xSemaphoreTake(xSemaphore,5000/ portTICK_PERIOD_MS);
		UART_SENDSTRING((char *)string) ;
		xSemaphoreGive(xSemaphore);
		//vTaskDelay(500/ portTICK_PERIOD_MS);
	}
	
}
