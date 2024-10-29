/*
 * I2C_slave.c
 *
 * Created: 7/19/2023 1:06:38 PM
 * Author : moham
 */ 


#include "TWI.h"


int main(void)
{
	DDRC |=(1<<2);
	TW_init(0x03);//0000 0011
	while (1)
	{
		if (TWI_READACK()==0X60){
			if (TWI_READACK()==0X80){
				
				if (TWI_recived() == 'M'){
					PORTC ^=(1<<2);
					
					
				}
			}
			
		}
		
	}
}

