/*
 * DIO.h
 *
 * Created: 6/28/2023 6:44:30 AM
 *  Author: moham
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "STD_types.h"
#include "bit_math.h"
#include "DIO_HW.h"
#include "DIO_types.h"
void DIO_write(DIO_ChannelTypes channelId,STD_leveltypes level);
uint8 DIO_READ(DIO_ChannelTypes);
void DIO_WritePort(DIO_portTypes,uint8);



#endif /* DIO_H_ */