/*
 * EEPROM_test2.c
 *
 * Created: 7/29/2023 6:24:27 PM
 * Author : moham
 */ 

#include "TWI.h"


int main(void)
{
	TWI_Init(0x05);
	DIO_init();
	LCD_init();
	
	Uint8 data;
	Uint8 check;
	DDRC |= (1<<2);
	PORTC &=~ (1<<2);
	_delay_ms(1000);
	
	
	while (1)
	{
		
		EEPROM_Write(2,0x01);
		check = EEPROM_Read(0x01);
		
	}
}


/*(if (check==2)
{
	PORTC |= (1<<2);
	_delay_ms(1000);
}*/
