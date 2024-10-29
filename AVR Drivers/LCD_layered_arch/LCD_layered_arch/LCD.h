/*
 * LCD.h
 *
 * Created: 6/23/2023 5:02:51 AM
 *  Author: moham
 */ 



#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000UL
#include "DIO.h"
#include <util/delay.h>


#define LCD_Data_Port        DIO_PortA
#define LCD_Control_Port     DIO_PortB



#define LCD_RS  DIO_ChannelB1    //PB1
#define LCD_RW  DIO_ChannelB2
#define LCD_E   DIO_ChannelB3 

void LCD_Command(uint8 cmd); 
void LCD_init(void);
void LCD_Send_Char(uint8 data);
void LCD_string(uint8 * string);
void LCD_GoTo (uint8 line,uint8 pos,uint8 * data);
void LCD_Custom_Char (unsigned char loc, unsigned char *msg);

#endif /* LCD_H_ */