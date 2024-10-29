/*
 * RTOS_test2.c
 *
 * Created: 7/31/2023 4:43:58 AM
 * Author : moham
 */ 


#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"

void LED1( void * pv);
void LED2( void * pv);
void LED3( void * pv);
void push( void * pv);
void Get_Bit(char reg,char pin, char * data);

volatile char speed=1;
volatile char data=0;


int main(void)
{
	DDRC |= (1<<2)|(1<<3)|(1<<4);
	
	DDRD &=~ (1<<2) ;
	xTaskCreate(push,"push",50,NULL,3,NULL);
	xTaskCreate(LED1,"LED1",50,NULL,1,NULL);
	//xTaskCreate(LED2,"LED2",50,NULL,1,NULL);
	//xTaskCreate(LED3,"LED3",50,NULL,1,NULL);
	vTaskStartScheduler();
	while (1)
	{
		
	}
}

void LED1( void * pv){
	
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	while (1)
	{
		PORTC  ^= (1<<2);
		vTaskDelayUntil ( &xLastWakeTime, 100*speed);
	}
}
/*
void LED2( void * pv){
	while (1)
	{
		PORTC ^= (1<<3);
		vTaskDelay(1000/portTICK_PERIOD_MS);
	}
}

void LED3( void * pv){
	while (1)
	{
		PORTC ^= (1<<4);
		vTaskDelay(1500/portTICK_PERIOD_MS);
	}
}
*/
void push( void * pv){
	char flag=0;
	
	while (1)
	{
		Get_Bit(PIND,2,&data);
		
		if ((PIND & (1<<2)) &&  (flag == 0))
		{
			PORTC |= (1<<4);
			speed +=1;
			speed = (speed > 10)?1:speed; 
		}
		flag=data;
		vTaskDelay(50);
	}
}


void Get_Bit(char reg,char pin, char * data){
	*data = (reg & (1<<pin));
}