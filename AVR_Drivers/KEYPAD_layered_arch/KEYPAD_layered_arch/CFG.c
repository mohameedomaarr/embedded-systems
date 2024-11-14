/*
 * CFG.c
 *
 * Created: 6/22/2023 2:33:57 AM
 *  Author: moham
 */ 

#include "CFG.h"
#include "DIO.h"
#include "std_types.h"
#include "DIO_types.h"
#include "DIO_HW.h"
#include "bit_math.h"

//DIO_PINCFG Pincfgg={Output,STD_high};


const DIO_PINCFG PinCfg[]={
	//port A
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	
	//PORTB
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},	
	
	//PORTC
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},	
	
	//portD
	
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Output,STD_high},
	{Input,STD_high},
	{Input,STD_high},
	{Input,STD_high},
	{Input,STD_high},
};





void DIO_Init(void){
	DIO_ChannelTypes DIO_channel;
	DIO_PortTypes PortX;
	uint8 count=0;
	for(count=DIO_ChannelA0;count<pin_count;count++)
	{
		PortX=count/8;
		DIO_channel=count%8;
		switch(PortX){
			case DIO_PortA :
			if (PinCfg[count].PinDir == Output)
			{
				set_bit(DDRA_reg,DIO_channel);
			}
			else{
				reset_bit(DDRA_reg,DIO_channel);
			}
			break;
			case DIO_PortB :
			if (PinCfg[count].PinDir == Output)
			{
				set_bit(DDRB_reg,DIO_channel);
			}
			else{
				reset_bit(DDRB_reg,DIO_channel);
			}
			break;
			case DIO_PortC :
			if (PinCfg[count].PinDir == Output)
			{
				set_bit(DDRC_reg,DIO_channel);
			}
			else{
				reset_bit(DDRC_reg,DIO_channel);
			}
			break;
			case DIO_PortD :
			if (PinCfg[count].PinDir == Output)
			{
				set_bit(DDRD_reg,DIO_channel);
			}
			else{
				reset_bit(DDRD_reg,DIO_channel);
			}
			break;
			
		}
	}
}


