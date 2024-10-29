/*
 * RTOS_queue_struct.c
 *
 * Created: 9/6/2023 8:27:40 PM
 * Author : moham
 */ 


#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "UART.h"
void Sender(void * pv);
void Receiver(void * pv);
xQueueHandle xQueue;

typedef struct {
	char * xValue;
	char * senderNum;
	}xdata;
	
static const xdata senderData[2]=	{
	{"100","xSender1\r\n"},
	{"200","xSender2\r\n"}
	};


int main(void)
{
	UART_INT();
	xQueue= xQueueCreate(2,sizeof( xdata));
	if (xQueue != NULL)
	{

		xTaskCreate(Sender,"sender1",100,(void *)&senderData[0],2,NULL);
		xTaskCreate(Sender,"sender2",100,(void *)&senderData[1],2,NULL);
		xTaskCreate(Receiver,"receiver",100,NULL,1,NULL);
		vTaskStartScheduler();
	}
	
	
	/* Replace with your application code */
	while (1)
	{
	}
}

void Sender(void * pv){
	while(1){
		
		BaseType_t xStatus= xQueueSendToBack(xQueue,(unsigned char *)pv,50/portTICK_PERIOD_MS);
		taskYIELD();
	}
}

void Receiver(void * pv){
	xdata  data;
	while(1){
		
		BaseType_t xStatus= xQueueReceive(xQueue,(xdata *)&data,50/portTICK_PERIOD_MS);
		UART_SENDSTRING(data.xValue);
		UART_SENDSTRING(data.senderNum);
		
		//UART_SENDCHAR("\n");
		
	}
}