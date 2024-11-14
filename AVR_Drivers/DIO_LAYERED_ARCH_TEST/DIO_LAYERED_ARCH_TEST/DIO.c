/*
 * DIO.c
 *
 * Created: 6/28/2023 6:45:43 AM
 *  Author: moham
 */ 

#include "DIO.h"
void DIO_write(DIO_ChannelTypes channelId,STD_leveltypes level){
	DIO_portTypes PORTX =channelId/8;
	DIO_ChannelTypes Channelpos=channelId%8;
	switch(PORTX){
		case DIO_portA:
		if (level == STD_high)
		{
			set_bit(PORTA_reg,Channelpos);
		}
		else{
			reset_bit(PORTA_reg,Channelpos);
		}
		break;
		case DIO_portB:
		if (level == STD_high)
		{
			set_bit(PORTB_reg,Channelpos);
		}
		else{
			reset_bit(PORTB_reg,Channelpos);
		}
		break;
		case DIO_portC:
		if (level == STD_high)
		{
			set_bit(PORTC_reg,Channelpos);
		}
		else{
			reset_bit(PORTC_reg,Channelpos);
		}
		break;
		case DIO_portD :
		if (level == STD_high)
		{
			set_bit(PORTD_reg,Channelpos);
		}
		else{
			reset_bit(PORTD_reg,Channelpos);
		}
		break;
	}
}


uint8 DIO_READ(DIO_ChannelTypes channelId){
	DIO_PINTypes PINX =channelId/8;
	DIO_ChannelTypes Channelpos=channelId%8;
	switch(PINX){
		case DIO_PINA :
		return get_bit(PINA_reg,Channelpos);
		break;
		
		case DIO_PINB :
		return get_bit(PINB_reg,Channelpos);
		break;
		
		case DIO_PINC :
		return get_bit(PINC_reg,Channelpos);
		break;
		
		case DIO_PIND :
		return get_bit(PIND_reg,Channelpos);
		break;
		

	}
	
}

void DIO_WritePort(DIO_portTypes Portx,uint8 data){
	switch(Portx){
		case DIO_portA:
		PORTA_reg = data;
		break;
		case DIO_portB:
		PORTB_reg = data;
		break;
		case DIO_portC:
		PORTC_reg = data;
		break;
		case DIO_portD:
		PORTD_reg = data;
		break;
	}
}