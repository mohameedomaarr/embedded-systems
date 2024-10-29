/*
* DIO_Types.h
*
* Created: 7/7/2020 3:35:59 PM
*  Author: youus
*/


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

typedef enum
{
	DIO_ChannelA0=0,
	DIO_ChannelA1,
	DIO_ChannelA2,
	DIO_ChannelA3,
	DIO_ChannelA4,
	DIO_ChannelA5,
	DIO_ChannelA6,
	DIO_ChannelA7,
	DIO_ChannelB0,
	DIO_ChannelB1,
	DIO_ChannelB2,
	DIO_ChannelB3,
	DIO_ChannelB4,
	DIO_ChannelB5,
	DIO_ChannelB6,
	DIO_ChannelB7,
	DIO_ChannelC0,
	DIO_ChannelC1,
	DIO_ChannelC2,
	DIO_ChannelC3,
	DIO_ChannelC4,
	DIO_ChannelC5,
	DIO_ChannelC6,
	DIO_ChannelC7,
	DIO_ChannelD0,
	DIO_ChannelD1,
	DIO_ChannelD2,
	DIO_ChannelD3,
	DIO_ChannelD4,
	DIO_ChannelD5,
	DIO_ChannelD6,
	DIO_ChannelD7
}DIO_Channels ;


typedef enum
{
	DIO_PortA=0,
	DIO_PortB,
	DIO_PortC,
	DIO_PortD
}DIO_Ports;


typedef enum
{
	DIO_PINA=0,
	DIO_PINB,
	DIO_PINC,
	DIO_PIND
}DIO_PIN;

typedef enum
{
	Input=0,
	Output
	
}DIO_DIR;

typedef enum
{
	DIO_MPCM=0,
	DIO_U2X,
	DIO_PE,
	DIO_DOR,
	DIO_FE,
	DIO_UDRE,
	DIO_TXC,
	DIO_RXC
	
}DIO_UCSRA;

typedef enum
{
	DIO_TXB8=0,
	DIO_RXB8,
	DIO_UCSZ2,
	DIO_TXEN,
	DIO_RXEN,
	DIO_UDRIE,
	DIO_TXCIE,
	DIO_RXCIE
	
}DIO_UCSRB;

typedef enum
{
	DIO_UCPOL=0,
	DIO_UCSZ0,
	DIO_UCSZ1,
	DIO_USBS,
	DIO_UPM0,
	DIO_UPM1,
	DIO_UMSEL,
	DIO_URSEL
	
}DIO_UCSRC;


typedef enum
{
	DIO_WGM10=0,
	DIO_WGM11,
	DIO_FOC1B,
	DIO_FOC1A,
	DIO_COM1B0,
	DIO_COM1B1,
	DIO_COM1A0,
	DIO_COM1A1	
	
}DIO_TCCR1A;


typedef enum
{
	DIO_CS10=0,
	DIO_CS11,
	DIO_CS12,
	DIO_WGM12,
	DIO_WGM13,
	DIO_Reserved,
	DIO_ICES1,
	DIO_ICNC1
	
}DIO_TCCR1B;


typedef enum
{
	DIO_SPI2X=0,
	DIO_RES1,
	DIO_RES2,
	DIO_RES3,
	DIO_RES4,
	DIO_RES5,
	DIO_WCOL,
	DIO_SPIF
	
}DIO_SPSR;


typedef enum
{
	DIO_SPR0=0,
	DIO_SPR1,
	DIO_CPHA,
	DIO_CPOL,
	DIO_MSTR,
	DIO_DORD,
	DIO_SPE,
	DIO_SPIE
	
}DIO_SPCR;


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