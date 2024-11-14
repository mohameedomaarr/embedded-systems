/*
 * EEPROM_test.c
 *
 * Created: 7/28/2023 9:27:55 PM
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
		
		EEPROM_Write(2,0x02);
		check = EEPROM_Read(0x02);
		
		if (check==2)
		{
			PORTC |= (1<<2);
			_delay_ms(1000);
		}
	}
}

