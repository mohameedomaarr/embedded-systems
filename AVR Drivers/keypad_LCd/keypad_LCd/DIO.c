/*
* DIO.h
*
* Created: 6/21/2023 10:26:41 PM
*  Author: mohamed
*/


#ifndef DIO_H_
#define DIO_H_
#include "DIO.h"
#include "std_types.h"
#include "DIO_types.h"
#include "DIO_HW.h"
#include "bit_math.h"


void DIO_write(DIO_ChannelTypes channelID,STD_LevelTypes level){
	DIO_PortTypes Portx = channelID/8 ;
	DIO_ChannelTypes ChannelPos = channelID%8;
	switch(Portx){
		case DIO_PortA :
		if(level == STD_high){
			set_bit(PORTA_reg,ChannelPos);
		}
		else{
			reset_bit(PORTA_reg,ChannelPos);
		}
		break;
		
		
		
		case DIO_PortB :
		if(level == STD_high){
			set_bit(PORTB_reg,ChannelPos);
		}
		else{
			reset_bit(PORTB_reg,ChannelPos);
		}
		break;
		
		case DIO_PortC :
		if(level == STD_high){
			set_bit(PORTC_reg,ChannelPos);
		}
		else{
			reset_bit(PORTC_reg,ChannelPos);
		}
		break;
		
		case DIO_PortD :
		if(level == STD_high){
			set_bit(PORTD_reg,ChannelPos);
		}
		else{
			reset_bit(PORTD_reg,ChannelPos);
		}
		break;
		
		default:
		//#error "wrong choice"
		break;
	}
	
	
};



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

void DIO_WritePort(DIO_PortTypes portx, uint8 data){
	switch(portx){
		case DIO_PortA:
		PORTA_reg= data;
		break;
		
		case DIO_PortB:
		PORTB_reg= data;
		break;
		
		case DIO_PortC:
		PORTC_reg= data;
		break;
		
		case DIO_PortD:
		PORTD_reg= data;
		break;
	}
}

#endif /* DIO_H_ */