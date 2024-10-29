/*
 * DIO_layered_arch.c
 *
 * Created: 6/21/2023 9:52:56 PM
 * Author : moham
 */ 
#define F_CPU 16000000UL

#include "CFG.h"
#include "DIO.h"
#include "std_types.h"
#include "DIO_types.h"
#include "DIO_HW.h"
#include "bit_math.h"
#include <util/delay.h>

int main(void)
{
   DIO_Init();
    /* Replace with your application code */
    while (1) 
    {
		DIO_write(DIO_ChannelC1,STD_high);
		_delay_ms(500);
		DIO_write(DIO_ChannelC1,STD_low);
		_delay_ms(500);
    }
}

