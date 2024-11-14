/*
 * DIO.h
 *
 * Created: 6/21/2023 10:08:42 PM
 *  Author: moham
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "bit_math.h"
#include "DIO_HW.h"
#include "std_types.h"
#include "DIO_types.h"


void DIO_write(DIO_ChannelTypes channelID,STD_LevelTypes level);
uint8 DIO_READ(DIO_ChannelTypes channelId);


#endif /* DIO_H_ */