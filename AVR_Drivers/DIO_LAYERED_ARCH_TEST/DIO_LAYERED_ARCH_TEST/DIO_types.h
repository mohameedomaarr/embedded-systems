/*
 * DIO_types.h
 *
 * Created: 6/28/2023 6:28:26 AM
 *  Author: moham
 */ 


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_
typedef enum{
	DIO_channelA0=0,
	DIO_channelA1,
	DIO_channelA2,
	DIO_channelA3,
	DIO_channelA4,
	DIO_channelA5,
	DIO_channelA6,
	DIO_channelA7,
	DIO_channelB0,
	DIO_channelB1,
	DIO_channelB2,
	DIO_channelB3,
	DIO_channelB4,
	DIO_channelB5,
	DIO_channelB6,
	DIO_channelB7,
	DIO_channelC0,
	DIO_channelC1,
	DIO_channelC2,
	DIO_channelC3,
	DIO_channelC4,
	DIO_channelC5,
	DIO_channelC6,
	DIO_channelC7,
	DIO_channelD0,
	DIO_channelD1,
	DIO_channelD2,
	DIO_channelD3,
	DIO_channelD4,
	DIO_channelD5,
	DIO_channelD6,
	DIO_channelD7
}DIO_ChannelTypes;


typedef enum{
	DIO_portA=0,
	DIO_portB,
	DIO_portC,
	DIO_portD
}DIO_portTypes;

typedef enum{
	Input=0,
	Output
}DIO_DIR;

typedef enum{
	DIO_PINA=0,
	DIO_PINB,
	DIO_PINC,
	DIO_PIND
}DIO_PINTypes;

	


#endif /* DIO_TYPES_H_ */