/*
 * SPI_layered.c
 *
 * Created: 7/16/2023 5:02:15 AM
 * Author : moham
 */ 

/*
 * SPI_MASTER_LAYER_ARCH.c
 *
 * Created: 8/9/2020 12:14:21 AM
 * Author : Mohmed
 */ 
#include "SPI.h"

int main(void)
{
	SPI_CONFIG config ={Master,OCS16};
	DDRC |=(1<<1);
	SPI_INT(&config);
	slave_EN();
	while (1)
	{
		if (SPI_TX_RX('2')==0x55)
		{
			PORTC ^=(1<<1);
			_delay_ms(500);
		}
	}
}

