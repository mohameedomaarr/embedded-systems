/*
 * GPIO_int.h
 *
 *  Created on: Nov 6, 2023
 *      Author: moham
 */

#ifndef MCAL_GPIO_GPIO_INT_H_
#define MCAL_GPIO_GPIO_INT_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#define PIN0 	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15
#define PIN16	16


#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2

#define GPIO_OPENDRAIN	0
#define GPIO_PUSHPULL	1


#define GPIO_MODE_INPUT		0b00
#define GPIO_MODE_OUTPUT	0b01
#define GPIO_MODE_ALTFUNC	0b10
#define GPIO_MODE_ANALOG	0b11

#define GPIO_SPEED_LOW 			0b00
#define GPIO_SPEED_MEDIUM   	0b01
#define GPIO_SPEED_HIGH		    0b10
#define GPIO_SPEED_VERYHIGH 	0b11

#define GPIO_NO_PULL			0b00
#define GPIO_IO_PULL_UP			0b01
#define GPIO_IO_PULL_DOWN		0b10

#define GPIO_HIGH 	1
#define GPIO_LOW	0

typedef struct{
	u8 Port;
	u8 Pin;
	u8 Mode;
	u8 OutputType;
	u8 OutputSpeed;
	u8 InputPull;
	u8 AltFunc;

}MGPIO_Config_t;


void MGPIO_vSetPinMode(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8Mode  );

void MGPIO_vSetPinOutputType(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8OutType);

void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8OutSpeed  );


void MGPIO_vSetPinInputPull(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8PullType  );

u8 MGPIO_vGetPinInputValue(u8 A_u8PortId, u8 A_u8PinNo);


void MGPIO_vSetPinValue(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8PinVal  );

void MGPIO_vSetPinValueFast(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8PinVal  );

void MGPIO_vSetAlternativeFunction(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8AltFunc  );

void MGPIO_vSetPortValue(u8 A_u8PortId,u16 A_u8PortVal);

void MGPIO_vInit(MGPIO_Config_t * A_xPinConfig);

void MGPIO_vTogglePinValue(u8 A_u8PortId, u8 A_u8PinNo);

#endif /* MCAL_GPIO_GPIO_INT_H_ */
