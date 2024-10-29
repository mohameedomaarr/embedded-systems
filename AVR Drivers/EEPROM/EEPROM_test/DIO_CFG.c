/*
* DIO_CFG.c
*
* Created: 7/7/2020 5:40:58 PM
*  Author: youus
*/

#include "DIO_CFG.h"




const DIO_PinCfg pinconfig[]=
{
	//PortA
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PortB
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Input,STD_Low},
	{Output,STD_High},
	
	//PortC
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},

	//PortD
	{Input,STD_Low},
	{Output,STD_High},
	{Input,STD_Low },
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},

};



void DIO_init(void)
{
	DIO_Ports Portx;
	DIO_Channels channelpos;
	Uint8 count=0;
	for(count=DIO_ChannelA0;count<Pincount;count++)
	{
		Portx=count/8;
		channelpos=count%8;
		switch(Portx)
		{
			case DIO_PortA:
			if(pinconfig[count].PinDir==Output)
			{
				Set_Bit(DDRA,channelpos);
			}
			else
			{
				Clear_Bit(DDRA,channelpos);
			}
			break;
			
			case DIO_PortB:
			if(pinconfig[count].PinDir==Output)
			{
				Set_Bit(DDRB,channelpos);
			}
			else
			{
				Clear_Bit(DDRB,channelpos);
			}
			break;
			
			case DIO_PortC:
			if(pinconfig[count].PinDir==Output)
			{
				Set_Bit(DDRC,channelpos);
			}
			else
			{
				Clear_Bit(DDRC,channelpos);
			}
			break;
			
			case DIO_PortD:
			if(pinconfig[count].PinDir==Output)
			{
				Set_Bit(DDRD,channelpos);
			}
			else
			{
				Clear_Bit(DDRD,channelpos);
			}
			break;
			
			
			
			
		}
	}
}