/*
 * I2C_test.c
 *
 * Created: 7/18/2023 5:43:37 PM
 * Author : moham
 */ 

#include "I2C.h"



int main(void)
{
	TW_init(0x05);//0b00000101
    /* Replace with your application code */
    while (1) 
    {
		if (TWI_start()==0x08)
		{
			if (TWI_DATA(0b00000011)==0x18)
			{
				if (TWI_DATA('M')==0x28)
				{
					TWI_stop();
					_delay_ms(1000);
				}
			}
		}
    }
}

