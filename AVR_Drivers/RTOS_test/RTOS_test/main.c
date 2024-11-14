/*
 * RTOS_test.c
 *
 * Created: 7/30/2023 4:39:09 PM
 * Author : moham
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
void LED( void * pv);

int main(void)
{
	TaskHandle_t xHandle = NULL;
	DDRC |= (1<<2);
    xTaskCreate(LED,"LED",50,NULL,1,&xHandle);
	vTaskStartScheduler();
    while (1) 
    {
    }
}

void LED( void * pv){
	  while (1)
	  {
		  PORTC ^= (1<<2);
		  vTaskDelay(500/portTICK_PERIOD_MS);
	  }
}