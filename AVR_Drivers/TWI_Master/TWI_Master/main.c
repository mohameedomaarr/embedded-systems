/*
 * TWI_Master.c
 *
 * Created: 7/19/2023 2:36:39 PM
 * Author : moham
 */ 


#include "TWI.h"


int main(void)
{
	DIO_INT();
	TW_init(0x05);
	while (1)
	{
		if(TWI_start() == 0x08){
			if (TWI_DATA(0b00000010) == 0x18){
				if (TWI_DATA('M') == 0x28){
					TWI_stop();
					_delay_ms(1000);
				}
				
			}
			
		}
		
	}
}

