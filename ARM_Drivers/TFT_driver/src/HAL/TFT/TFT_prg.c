/*
 * TFT_prg.c
 *
 *  Created on: Jan 12, 2024
 *      Author: moham
 */

#include "TFT_cfg.h"
#include "TFT_int.h"
#include "TFT_prv.h"

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/SPI/SPI_int.h"
#include "../../MCAL/SYSTICK/SYSTICK_int.h"

MGPIO_Config_t TFT_A0_pin={
		.Port=GPIO_PORTA,
		.Pin=PIN1,
		.Mode=GPIO_MODE_OUTPUT,
		.OutputSpeed=GPIO_SPEED_HIGH,
		.OutputType=GPIO_PUSHPULL,
		.InputPull=GPIO_NO_PULL,

};

MGPIO_Config_t TFT_RST_pin={
		.Port=GPIO_PORTA,
		.Pin=PIN0,
		.Mode=GPIO_MODE_OUTPUT,
		.OutputSpeed=GPIO_SPEED_HIGH,
		.OutputType=GPIO_PUSHPULL,
		.InputPull=GPIO_NO_PULL,

};

static u16 current_xpos_start;
static u16 current_xpos_end;
static u16 current_ypos_start;
static u16 current_ypos_end;

void write_cmd(u16 cmd){

	MGPIO_vSetPinValue(TFT_A0_pin.Port,TFT_A0_pin.Pin,GPIO_LOW);
	MSPI_u16Tranceive(cmd);
}

void write_data(u16 data){

	MGPIO_vSetPinValue(TFT_A0_pin.Port,TFT_A0_pin.Pin,GPIO_HIGH);
	MSPI_u16Tranceive(data);
}

void Reset_sequence(void){
	MGPIO_vSetPinValue(TFT_RST_pin.Port,TFT_RST_pin.Pin,GPIO_HIGH);
	MSTK_vSetBusyWait(100/*100 Micro Sec*/);
	MGPIO_vSetPinValue(TFT_RST_pin.Port,TFT_RST_pin.Pin,GPIO_LOW);
	MSTK_vSetBusyWait(1/*100 Micro Sec*/);
	MGPIO_vSetPinValue(TFT_RST_pin.Port,TFT_RST_pin.Pin,GPIO_HIGH);
	MSTK_vSetBusyWait(100/*100 Micro Sec*/);
	MGPIO_vSetPinValue(TFT_RST_pin.Port,TFT_RST_pin.Pin,GPIO_LOW);
	MSTK_vSetBusyWait(100/*100 Micro Sec*/);
	MGPIO_vSetPinValue(TFT_RST_pin.Port,TFT_RST_pin.Pin,GPIO_HIGH);
	MSTK_vSetBusyWait(120/*120 Milli Sec*/);

}

void TFT_vInit(void){

	/*1- set pin directions */
	MGPIO_vInit(&TFT_A0_pin);
	MGPIO_vInit(&TFT_RST_pin);
	/*2-MSPI INIT*/
	MSPI_vInit();
	/*3-STK INIT*/
	MSTK_vInit();
	/*4-reset sequence*/
	Reset_sequence();
	/*send SLEEP OUT CMD (0x11)*/
	write_cmd(0x11);
	/*wait 15 ms*/
	MSTK_vSetBusyWait(15000);
	/*send color mode cmd (RGB565)*/
	write_cmd(0x3A);
	write_data(0x05);
	/*display on*/
	write_cmd(0x29);

}


void TFT_vShowImage(u16 A_u16Img[],u32 A_ImgSize){
	/*1-set x pos */
	write_cmd(0x2A);
	/*x start : 0 , x end :127*/
	write_data(0);
	write_data(0);
	write_data(0); //high byte
	write_data(127);//low byte
	/*2-set y pos */
	write_cmd(0x2B);
	/*y start : 0 , y end :159*/
	write_data(0);
	write_data(0);
	write_data(0); //high byte
	write_data(159);//low byte
	/*3-send image data*/
	write_cmd(0x2C);
	for(unsigned int i=0 ; i<A_ImgSize ; i++){
		write_data(A_u16Img[i]>>8);// most significant byte
		write_data(A_u16Img[i] & 0x00FF);// least significant byte
	}

}
void TFT_vSetXPos(u16 xStart,u16 xEnd){
	current_xpos_start=xStart;
	current_xpos_end=xEnd;


	/*1-set x pos */
		write_cmd(0x2A);
		/*x start : 0 , x end :127*/
		write_data(0);
		write_data(xStart);
		write_data(0); //high byte
		write_data(xEnd);//low byte
}
void TFT_vSetYPos(u16 yStart,u16 yEnd){
	  current_ypos_start=yStart;
	  current_ypos_end=yEnd;

	/*2-set y pos */
		write_cmd(0x2B);
		/*y start : 0 , y end :159*/
		write_data(0);
		write_data(yStart);
		write_data(0); //high byte
		write_data(yEnd);//low byte
}
void TFT_vFillRectangle(u16 color){

	u32 No_pixels=(current_xpos_end-current_xpos_start)*(current_ypos_end-current_ypos_start);

	/*3-send image data*/
		write_cmd(0x2C);
		for(unsigned int i=0 ; i<(No_pixels) ; i++){
			write_data(color>>8);// most significant byte
			write_data(color & 0x00FF);// least significant byte
		}

}
void TFT_vFillBackGround(u16 color){
	/*1-set x pos */
		write_cmd(0x2A);
		/*x start : 0 , x end :127*/
		write_data(0);
		write_data(0);
		write_data(0); //high byte
		write_data(127);//low byte
		/*2-set y pos */
		write_cmd(0x2B);
		/*y start : 0 , y end :159*/
		write_data(0);
		write_data(0);
		write_data(0); //high byte
		write_data(159);//low byte

		TFT_vFillRectangle(color);
}



