/*
 * RTOS_queue.c
 *
 * Created: 9/6/2023 12:49:32 PM
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


int main(void)
{
	UART_INT();
	xQueue= xQueueCreate(5,sizeof(unsigned char));
		if (xQueue != NULL)
		{
			
			
			/*unsigned char sendData1=0x01;
			unsigned char sendData2=0x02;
			unsigned char * pSendData1=&sendData1;
			unsigned char * pSendData2=&sendData2;*/
			
			unsigned char arr[]= {0x01,0x02};
			
			//xTaskCreate(Sender,"sender1",100,(void *)pSendData1,1,NULL);
			//xTaskCreate(Sender,"sender2",100,(void *)pSendData2,1,NULL);
			
			xTaskCreate(Sender,"sender1",100,(void *)arr,1,NULL);
			xTaskCreate(Sender,"sender2",100,(void *)(arr+1),1,NULL);
			
			xTaskCreate(Receiver,"receiver",100,NULL,2,NULL);
			vTaskStartScheduler();
		}
	
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

void Sender(void * pv){
	 while(1){
	
	  BaseType_t xStatus= xQueueSendToBack(xQueue,(unsigned char *)pv,5/portTICK_PERIOD_MS);
	  taskYIELD(); 
	// vTaskDelay(5/portTICK_PERIOD_MS);
	 }
}

void Receiver(void * pv){
	unsigned char  data;
	while(1){
		
		BaseType_t xStatus= xQueueReceive(xQueue,&data,5/portTICK_PERIOD_MS);
		UART_SENDCHAR((data));
		//UART_SENDCHAR("\n");
		
	}
}