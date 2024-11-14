/*
 * LCD.h
 *
 * Created: 7/10/2020 4:27:42 PM
 *  Author: youus
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000
#include <util/delay.h>
#include "DIO.h"

#define LCD_Data_Port       DIO_PortA
#define LCD_Control_Port    DIO_PortB


#define LCD_RS  DIO_ChannelB1  
#define LCD_RW  DIO_ChannelB2
#define LCD_E   DIO_ChannelB3


void LCD_Commend(Uint8 cmd);
void LCD_init(void);
void LCD_Char(Uint8 data);
void LCD_String(Uint8 * string);
void LCD_StringPos(Uint8 line,Uint8 pos,Uint8 * data);
void LCD_Clear(void);

#endif /* LCD_H_ */