/*
* TWI.c
*
* Created: 8/12/2020 11:26:40 PM
*  Author: youus
*/

#include "TWI.h"


void TWI_Init(Uint8 myaddress)
{
	TWBR=TWBR_val;
	TWI_Address(myaddress);
	TWCR |= (1<<DIO_TWEN) |(1<<DIO_TWINT);
	
}

Uint8 TWI_start (void)
{
	TWCR |= (1<<DIO_TWEN) | (1<<DIO_TWINT) | (1<<DIO_TWSTA) ;
	while(!(Get_Bit(TWCR,DIO_TWINT)));
	return TWI_Status();
	
}

void TWI_stop (void)
{
	TWCR |=(1<<DIO_TWEN) | (1<<DIO_TWINT) | (1<<DIO_TWSTO);
	
}

void TWI_Address(Uint8 address)
{
	TWAR=address;
}

Uint8 TWI_Data(Uint8 data)
{
	TWDR=data;
	TWCR = (1<<DIO_TWINT) | (1<<DIO_TWEN);
	while(!(Get_Bit(TWCR,DIO_TWINT)));
	return TWI_Status();
	
}

Uint8 TWI_Status(void)
{
	return (TWSR & 0xF8);
}

Uint8 TWI_Read(void)
{
	return TWDR;
}

Uint8 TWIReadNACK(void)
{
	TWCR = (1<<DIO_TWINT) | (1<<DIO_TWEN);
	while(!(Get_Bit(TWCR,DIO_TWINT)));
	return TWI_Status();
}

Uint8 TWIReadACK(void)
{
	TWCR = (1<<DIO_TWINT) | (1<<DIO_TWEN) | (1<<DIO_TWEA);
	while(!(Get_Bit(TWCR,DIO_TWINT)));
	return TWI_Status();
}


void EEPROM_Write(Uint8 data,Uint16 u16addr)
{
	
	
	if (TWI_start()==0x08)
	
	{	
	
		if (TWI_Data((0b10100000)|(Uint8)((u16addr & 0x0700)>>7))==0x18)
		{
			
			if (TWI_Data((Uint8)(u16addr))==0x28)
			{
				
				if (TWI_Data(data)==0x28)
				{    
					
					TWI_stop();
					
				}
			}
		}
	}
 }

Uint8 EEPROM_Read(Uint8 u16addr)
{
	Uint8 check = 0 ;
	
	//Uint8 deviceaddr=0X0A;
	if (TWI_start()==0x08)
	
	{
		LCD_Char('k');
		
		if (TWI_Data((0b10100000)|(Uint8)((u16addr & 0x0700)>>7))==0x18)
		{
			LCD_Char('f');
			

			if (TWI_Data((Uint8)(u16addr))==0x28)
			{
				LCD_Char('s');
				
				if (TWI_start()==0x10)
				{
					LCD_Char('y');
					
					if (TWI_Data(((0b10100000)|((Uint8)((u16addr & 0x0700)>>7))|1))==0x40)
					{
						LCD_Char('v');
						
						check=TWI_Read();
						
							TWI_stop();
							LCD_Char('w');
						

					}
				}
			}
		}
	}
	
	LCD_Char('D');
	return check;
}