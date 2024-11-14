/*
 * DIO_CFG.c
 *
 * Created: 6/28/2023 7:16:31 AM
 *  Author: moham
 */ 
#include "DIO_CFG.h"
#include "STD_types.h"
#include "bit_math.h"
#include "DIO_HW.h"
#include "DIO_types.h"
const DIO_PINCFG pincfg[]={
	//portA
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	//portb
	{Input,STD_low},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Input,STD_low},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	//portc
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	//portd

	{Input,STD_high},
	{Input,STD_high},
	{Input,STD_high},
	{Input,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high}

};

void DIO_INT(){
	DIO_portTypes PORTX ;
	DIO_ChannelTypes Channelpos;
	uint8 count=0;
	for(count=DIO_channelA0;count<pincount;count++)
	{
		PORTX=count/8;
		Channelpos=count%8;
		switch(PORTX){
			case DIO_portA :
			if (pincfg[count].PINDIR == Output)
			{
				set_bit(DDRA_reg,Channelpos);
			}
			else{
				reset_bit(DDRA_reg,Channelpos);
			}
			break;
			case DIO_portB :
			if (pincfg[count].PINDIR == Output)
			{
				set_bit(DDRB_reg,Channelpos);
			}
			else{
				reset_bit(DDRB_reg,Channelpos);
			}
			break;
			case DIO_portC :
			if (pincfg[count].PINDIR == Output)
			{
				set_bit( DDRC_reg,Channelpos);
			}
			else{
				reset_bit( DDRC_reg,Channelpos);
			}
			break;
			case DIO_portD :
			if (pincfg[count].PINDIR == Output)
			{
				set_bit(DDRD_reg,Channelpos);
			}
			else{
				reset_bit(DDRD_reg,Channelpos);
			}
			break;
		}
	}
}