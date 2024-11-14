/*
 * SPI_layered_test.c
 *
 * Created: 7/16/2023 9:58:32 AM
 * Author : moham
 */ 



#include "SPI.h"


int main(void)
{
	DDRC |= (1<<1);
	SPI_CONFIG config = {Master,OCS16};
	SPI_Init(&config);
	Slave_Enable();
	
	while (1)
	{
		if ((Tx_Rx(0x55))==(0x22))
		{
			PORTC ^= (1<<1);
			_delay_ms(1000);
		}
		
	}
}
