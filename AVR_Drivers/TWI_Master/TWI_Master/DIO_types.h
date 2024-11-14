/*
 * DIO_types.h
 *
 * Created: 7/7/2020 6:55:14 AM
 *  Author: Mohmed
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



typedef enum
{
	DIO_TWBR0=0,
	DIO_TWBR1,
	DIO_TWBR2,
	DIO_TWBR3,
	DIO_TWBR4,
	DIO_TWBR5,
	DIO_TWBR6,
	DIO_TWBR7
	
}DIO_TWBR;


typedef enum
{
	DIO_TWIE=0,
	DIO_NULL,
	DIO_TWEN,
	DIO_TWWC,
	DIO_TWSTO,
	DIO_TWSTA,
	DIO_TWEA,
	DIO_TWINT
	
}DIO_TWCR;


typedef enum
{
	DIO_TWPS0=0,
	DIO_TWPS1,
	DIO_Res,
	DIO_TWS3,
	DIO_TWS4,
	DIO_TWS5,
	DIO_TWS6,
	DIO_TWS7
	
}DIO_TWSR;


typedef enum
{
	DIO_TWD0=0,
	DIO_TWD1,
	DIO_TWD2,
	DIO_TWD3,
	DIO_TWD4,
	DIO_TWD5,
	DIO_TWD6,
	DIO_TWD7
	
}DIO_TWDR;


typedef enum
{
	DIO_TWGCE=0,
	DIO_TWA0,
	DIO_TWA1,
	DIO_TWA2,
	DIO_TWA3,
	DIO_TWA4,
	DIO_TWA5,
	DIO_TWA6
	
}DIO_TWAR;


#endif /* DIO_TYPES_H_ */