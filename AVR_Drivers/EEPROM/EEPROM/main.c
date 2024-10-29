/*
* EEPROM.c
*
* Created: 8/12/2020 4:56:05 PM
* Author : youus
*/

#include "TWI.h"


int main(void)
{
	TWI_Init(0x05);
	DIO_init();
	LCD_init();
	Uint8 data;
	Uint8 check;
	
	EEPROM_Write('2',0x00);
	check = EEPROM_Read(0x00);
	while (1)
	{
		
		if (check=='2')
		{
			DDRC |= (1<<2);
			_delay_ms(1000);
			
			//data=TWI_Read();
			//TWI_stop();
			//LCD_Char('2');
		}
		
		
		
	}
}

