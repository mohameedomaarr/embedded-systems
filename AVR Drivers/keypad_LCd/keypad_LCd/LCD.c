/*
 * LCD.c
 *
 * Created: 6/23/2023 5:03:16 AM
 *  Author: mohamed
 */ 
#include "LCD.h"

void LCD_Command(uint8 cmd){
	uint8 send_cmd;
	send_cmd =(LCD_Data_Port & (0x0F)) | (cmd &(0xF0));
	DIO_WritePort(LCD_Data_Port,send_cmd);
	DIO_write(LCD_RS,STD_low);
	DIO_write(LCD_E,STD_low);
	_delay_ms(2);
	DIO_write(LCD_E,STD_high);
	_delay_ms(10);
	send_cmd =(LCD_Data_Port & (0x0F)) | (cmd << 4);
	DIO_WritePort(LCD_Data_Port,send_cmd);
	DIO_write(LCD_RS,STD_low);
	DIO_write(LCD_E,STD_low);
	_delay_ms(2);
	DIO_write(LCD_E,STD_high);
	_delay_ms(2);
}
void LCD_init(void){
	DIO_write(LCD_RW,STD_low);
	_delay_ms(20);
	LCD_Command(0x33);
	_delay_ms(2);
	LCD_Command(0x32);
	LCD_Command(0x28);
	LCD_Command(0x06);
	LCD_Command(0x0C);
	LCD_Command(0x01);
	_delay_ms(2);
	
}
void LCD_Send_Char(uint8 data){
	uint8 send_Data;
	send_Data =(LCD_Data_Port & (0x0F)) | (data &(0xF0));
	DIO_WritePort(LCD_Data_Port,send_Data);
	DIO_write(LCD_RS,STD_high);
	DIO_write(LCD_E,STD_low);
	_delay_ms(2);
	DIO_write(LCD_E,STD_high);
	_delay_ms(10);
	send_Data =(LCD_Data_Port & (0x0F)) | (data << 4);
	DIO_WritePort(LCD_Data_Port,send_Data);
	DIO_write(LCD_RS,STD_high);
	DIO_write(LCD_E,STD_low);
	_delay_ms(2);
	DIO_write(LCD_E,STD_high);
	_delay_ms(2);
}

void LCD_string(uint8 * string){
	uint8 i=0;
	while(string[i] != '\0'){
		LCD_Send_Char(string[i]);
		i++;
	}
}

void LCD_GoTo (uint8 line,uint8 pos,uint8 * data){
	switch(line){
		case 1:
		LCD_Command((0x80|(pos & 0x0F)));  //POS 0->15
		LCD_string(data);
		break;
		case 2:
		LCD_Command((0xC0|(pos & 0x0F)));
		LCD_string(data);
		break;
	}
	
}

/*
char arr[] = "mina" ;
arr[1]='k';

char * ptr = "mina" ; //compiler by default put the value as constant in rom (ro.data)
ptr = "test";

const char arr[] = "mina" ; //mina constant
char * const ptr = "mina" ; //adress pointer constant
*/