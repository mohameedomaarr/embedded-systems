/*
 * DIO.h
 *
 * Created: 7/7/2020 4:11:39 PM
 *  Author: youus
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "Bit_Math.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "STD_Types.h"
#include "DIO_CFG.h"

void DIO_Write (DIO_Channels,STD_Levels);
void DIO_writePort(DIO_Ports Portx,Uint8 data);
Uint8 DIO_Read (DIO_Channels );

#endif /* DIO_H_ */