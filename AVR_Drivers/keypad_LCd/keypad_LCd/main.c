/*
 * keypad_LCd.c
 *
 * Created: 6/25/2023 2:36:25 AM
 * Author : moham
 */ 

#include <avr/io.h>
#include "KeyPad.h"
#include "LCD.h"


int main(void)
{
	DIO_Init();
	LCD_init();
	DDRD = 0b11110000;
	DDRC = 0b00000010;
	//LCD_Send_Char('M');
	
	char arr[]="MOHAMED ";
	LCD_string(arr);
	LCD_GoTo (2,5,arr);
	
	/* Replace with your application code */
	while (1)
	{
		check1();
		check2();
		check3();
		check4();

	}
}






