/*
* DIO_test.
*
* Created: 6/21/2023 5:12:44 AM
* Author : mohamed
*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include "bit_math.h"
#include <util/delay.h>
#include "DIO_HW.h"



int main(void)
{
	
	set_bit(DDRC_REG,1);
	
	while (1)
	{
		toggle_bit(PORTC_REG,1);
		_delay_ms(500);
	}
	
}

