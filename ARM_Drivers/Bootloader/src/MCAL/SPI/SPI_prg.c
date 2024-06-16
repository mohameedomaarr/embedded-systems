/*
 * SPI_prg.c
 *
 *  Created on: Jan 12, 2024
 *      Author: moham
 */

#include "SPI_cfg.h"
#include "SPI_int.h"
#include "SPI_prv.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


void MSPI_vInit(void){
	/*SPI MODE : CPHA and CPOL*/
	SET_BIT(SPI1->CR1,CPHA);
	SET_BIT(SPI1->CR1,CPOL);
	/*SELECT MASTER SLAVE MODE*/
	SET_BIT(SPI1->CR1,MSTR);

	/*3- SELECT BAUD RATE PRESCALER*/
	SPI1->CR1 = (SPI1->CR1 &~(0b111<<3))|(SPI1_BAUDRATE<<3);
	/*4- MSB/LSB first*/
	CLR_BIT(SPI1->CR1,7);
	/*5-ENABLE SPI1*/
	SET_BIT(SPI1->CR1,6);
	/*6-select software slave management*/
	SET_BIT(SPI1->CR1,9);
	SET_BIT(SPI1->CR1,8);

	/*Data Format*/
	CLR_BIT(SPI1->CR1,11); //DFF 8bit

	/*setup pins*/
	MGPIO_Config_t MOSI={
			.Port=GPIO_PORTA,
			.Pin=PIN7,
			.Mode=GPIO_MODE_ALTFUNC,
			.OutputSpeed=GPIO_SPEED_HIGH,
			.OutputType=GPIO_PUSHPULL,
			.InputPull=GPIO_NO_PULL,
			.AltFunc=GPIO_AF_5

	};

	MGPIO_Config_t MISO={
			.Port=GPIO_PORTA,
			.Pin=PIN6,
			.Mode=GPIO_MODE_ALTFUNC,
			.OutputSpeed=GPIO_SPEED_HIGH,
			.OutputType=GPIO_PUSHPULL,
			.InputPull=GPIO_NO_PULL,
			.AltFunc=GPIO_AF_5
	};
	MGPIO_Config_t SCK={
			.Port=GPIO_PORTA,
			.Pin=PIN5,
			.Mode=GPIO_MODE_ALTFUNC,
			.OutputSpeed=GPIO_SPEED_HIGH,
			.OutputType=GPIO_PUSHPULL,
			.InputPull=GPIO_NO_PULL,
			.AltFunc=GPIO_AF_5
	};

	MGPIO_vInit(&MOSI);
	MGPIO_vInit(&MISO);
	MGPIO_vInit(&SCK);

}
u16	MSPI_u16Tranceive(u16 A_u16Data){

	SPI1->DR = A_u16Data;
	while(GET_BIT(SPI1->SR,7)==1){

	}

	return SPI1->DR;


}


