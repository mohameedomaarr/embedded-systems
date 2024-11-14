/*
 * LCD.c
 *
 * Created: 7/10/2020 4:27:26 PM
 *  Author: youus
 */ 

#include "LCD.h"

void LCD_Commend(Uint8 cmd)
{
	Uint8 Send_cmd;
	Send_cmd = ((LCD_Data_Port & (0x0F))| (cmd & 0xF0));
	DIO_writePort(LCD_Data_Port,Send_cmd);
	_delay_ms(2);
	DIO_Write(LCD_RS,STD_Low);
	DIO_Write(LCD_E,STD_Low);
	_delay_ms(2);
	DIO_Write(LCD_E,STD_High);
	
	Send_cmd = ((LCD_Data_Port & (0x0F)) | (cmd<<4));
	DIO_writePort(LCD_Data_Port,Send_cmd);
	DIO_Write(LCD_RS,STD_Low);
	DIO_Write(LCD_E,STD_Low);
	_delay_ms(2);
	DIO_Write(LCD_E,STD_High);
	_delay_ms(2);
}
void LCD_init(void)
{
	DIO_Write(LCD_RW,STD_Low); // write
	_delay_ms(20);
	LCD_Commend(0x33);
	_delay_ms(2);
	LCD_Commend(0x32);
	LCD_Commend(0x28);
	LCD_Commend(0x06);
	LCD_Commend(0x0C);
	LCD_Commend(0x01);
	_delay_ms(1);
	
}
void LCD_Char(Uint8 data)
{
	Uint8 Send_Data;
	Send_Data = ((LCD_Data_Port & (0x0F)) | (data & 0xF0));
	DIO_writePort(LCD_Data_Port,Send_Data);
	DIO_Write(LCD_RS,STD_High);
	DIO_Write(LCD_E,STD_Low);
	_delay_ms(2);
	DIO_Write(LCD_E,STD_High);
	_delay_ms(2);
	
	Send_Data = ((LCD_Data_Port & (0x0F)) | (data<<4));
	DIO_writePort(LCD_Data_Port,Send_Data);
	DIO_Write(LCD_RS,STD_High);
	DIO_Write(LCD_E,STD_Low);
	_delay_ms(2);
	DIO_Write(LCD_E,STD_High);
	_delay_ms(2);
}

void LCD_String(Uint8 * string)
{
	Uint8 i=0;
	while(string[i] != '\0')
	{
		LCD_Char(string[i]);
		i++;
	}
}

void LCD_StringPos(Uint8 line,Uint8 pos,Uint8 * data)
{
	switch(line)
	{
		case 1:
		 LCD_Commend ((0x80 | (pos & 0x0F)));
		 LCD_String(data);
		 break;
		case 2:
		 LCD_Commend ((0xC0 | (pos & 0x0F)));
		 LCD_String(data);
	}
}

void LCD_Clear(void)
{
	LCD_Commend(0x01);
}