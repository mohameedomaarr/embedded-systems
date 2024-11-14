/*
* DIO.c
*
* Created: 7/7/2020 4:21:05 PM
*  Author: youus
*/

#include "DIO.h"

void DIO_Write (DIO_Channels channel,STD_Levels level)
{
	DIO_Ports Portx = channel/8;
	DIO_Channels channelpos= channel%8;
	
	switch(Portx)
	{
		case DIO_PortA:
		if(level==STD_High)
		{
			Set_Bit(PORTA,channelpos);
		}
		else
		{
			Clear_Bit(PORTA,channelpos);
		}
		break;
		
		case DIO_PortB:
		if(level==STD_High)
		{
			Set_Bit(PORTB,channelpos);
		}
		else
		{
			Clear_Bit(PORTB,channelpos);
		}
		break;
		
		case DIO_PortC:
		if(level==STD_High)
		{
			Set_Bit(PORTC,channelpos);
		}
		else
		{
			Clear_Bit(PORTC,channelpos);
		}
		break;
		
		case DIO_PortD:
		if(level==STD_High)
		{
			Set_Bit(PORTD,channelpos);
		}
		else
		{
			Clear_Bit(PORTD,channelpos);
		}
		
		break;
		
	
	}
	
	
}




Uint8 DIO_Read (DIO_Channels channel)
{
	DIO_PIN Pinx = channel/8;
	DIO_Channels channelpos= channel%8;
	
	switch(Pinx)
	{
		case DIO_PINA:
		
			return Get_Bit(PINA,channelpos);
		break;
		
		case DIO_PINB:
		
		 return Get_Bit(PINB,channelpos);
		break;
		
		case DIO_PINC:
		
		 return  Get_Bit(PINC,channelpos);
		break;
		
		case DIO_PIND:
		
		return  Get_Bit(PIND,channelpos);
		break;
		
	}
	
	return -1;
}


void DIO_writePort(DIO_Ports Portx,Uint8 data)
{
	switch(Portx)
	{
		case DIO_PortA:
		PORTA =data;
		break;
		
		case DIO_PortB:
		PORTB =data;
		break;

		case DIO_PortC:
		PORTC =data;
		break;

		case DIO_PortD:
		PORTD =data;
		break;

	}
	
}