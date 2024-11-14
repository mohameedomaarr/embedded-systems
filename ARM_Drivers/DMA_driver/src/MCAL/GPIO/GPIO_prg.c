/*
 * GPIO_prg.c
 *
 *  Created on: Nov 6, 2023
 *      Author: moham
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "GPIO_cfg.h"
#include "GPIO_prv.h"
#include "GPIO_int.h"

//FORBIDDEN PINS PORTA(13,14,15) PORTB(2,3,4)





void MGPIO_vSetPinMode(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8Mode  ){
	switch (A_u8PortId){
	case GPIO_PORTA:
		GPIOA->MODER &= (~(0b11<<(A_u8PinNo*2)));
		GPIOA->MODER |= (A_u8Mode<<(A_u8PinNo*2));
	break;
	case GPIO_PORTB:
			GPIOB->MODER &= (~(0b11<<(A_u8PinNo*2)));
			GPIOB->MODER |= (A_u8Mode<<(A_u8PinNo*2));
	break;
	case GPIO_PORTC:
			GPIOC->MODER &= (~(0b11<<(A_u8PinNo*2)));
			GPIOC->MODER |= (A_u8Mode<<(A_u8PinNo*2));
	break;

	}


}

void MGPIO_vSetPinOutputType(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8OutType){
	if(A_u8OutType == GPIO_OPENDRAIN){
		switch(A_u8PortId){
			case GPIO_PORTA:
				SET_BIT(GPIOA->OTYPER,A_u8PinNo);
			break;
			case GPIO_PORTB:
				SET_BIT(GPIOB->OTYPER,A_u8PinNo);
			break;
			case GPIO_PORTC:
				SET_BIT(GPIOC->OTYPER,A_u8PinNo);
			break;

			}
	}
	else if(A_u8OutType == GPIO_PUSHPULL){
		switch(A_u8PortId){
			case GPIO_PORTA:
				CLR_BIT(GPIOA->OTYPER,A_u8PinNo);
		break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->OTYPER,A_u8PinNo);
		break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->OTYPER,A_u8PinNo);
		break;
	  }
	}

}

void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8OutSpeed  ){
	switch (A_u8PortId){
		case GPIO_PORTA:
			GPIOA->OSPEEDR &= (~(0b11<<(A_u8PinNo*2)));
			GPIOA->OSPEEDR |= (A_u8OutSpeed<<(A_u8PinNo*2));
		break;
		case GPIO_PORTB:
				GPIOB->OSPEEDR &= (~(0b11<<(A_u8PinNo*2)));
				GPIOB->OSPEEDR |= (A_u8OutSpeed<<(A_u8PinNo*2));
		break;
		case GPIO_PORTC:
				GPIOC->OSPEEDR &= (~(0b11<<(A_u8PinNo*2)));
				GPIOC->OSPEEDR |= (A_u8OutSpeed<<(A_u8PinNo*2));
		break;

		}
}


void MGPIO_vSetPinInputPull(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8PullType  ){
	switch (A_u8PortId){
		case GPIO_PORTA:
			GPIOA->PUPDR &= (~(0b11<<(A_u8PinNo*2)));
			GPIOA->PUPDR |= (A_u8PullType<<(A_u8PinNo*2));
		break;
		case GPIO_PORTB:
				GPIOB->PUPDR &= (~(0b11<<(A_u8PinNo*2)));
				GPIOB->PUPDR |= (A_u8PullType<<(A_u8PinNo*2));
		break;
		case GPIO_PORTC:
				GPIOC->PUPDR &= (~(0b11<<(A_u8PinNo*2)));
				GPIOC->PUPDR |= (A_u8PullType<<(A_u8PinNo*2));
		break;

		}
}

u8 MGPIO_vGetPinInputValue(u8 A_u8PortId, u8 A_u8PinNo){

u8 L_u8PinValue = 0;

	switch(A_u8PortId){
	case GPIO_PORTA:
			L_u8PinValue = GET_BIT(GPIOA->IDR,A_u8PinNo);
	break;
	case GPIO_PORTB:
			L_u8PinValue = GET_BIT(GPIOB->IDR,A_u8PinNo);
	break;
	case GPIO_PORTC:
		L_u8PinValue = GET_BIT(GPIOB->IDR,A_u8PinNo);
	break;
}
	return L_u8PinValue;
}


void MGPIO_vSetPinValue(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8PinVal){
if (A_u8PinVal == GPIO_HIGH){
	switch(A_u8PortId){
		case GPIO_PORTA:
				SET_BIT(GPIOA->ODR,A_u8PinNo);
		break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->ODR,A_u8PinNo);
		break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->ODR,A_u8PinNo);
		break;
	}
}
else if(A_u8PinVal == GPIO_LOW){
	switch(A_u8PortId){
			case GPIO_PORTA:
				CLR_BIT(GPIOA->ODR,A_u8PinNo);
			break;
			case GPIO_PORTB:
				CLR_BIT(GPIOB->ODR,A_u8PinNo);
			break;
			case GPIO_PORTC:
				CLR_BIT(GPIOC->ODR,A_u8PinNo);
			break;
		}
}
}
/*
void MGPIO_vSetPinValueFast(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8PinVal  ){

}
*/
void MGPIO_vSetAlternativeFunction(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8AltFunc  ){

	if(A_u8PinNo < 8){

		switch(A_u8PortId){
		case  GPIO_PORTA:
			GPIOA->AFRL &=~ (0b1111 <<(A_u8PinNo*4));
			GPIOA->AFRL |= (A_u8AltFunc <<(A_u8PinNo*4));
			break;

		case  GPIO_PORTB:
			GPIOB->AFRL &=~ (0b1111 <<(A_u8PinNo*4));
			GPIOB->AFRL |= (A_u8AltFunc <<(A_u8PinNo*4));
			break;

		case  GPIO_PORTC:
			GPIOC->AFRL &=~ (0b1111 <<(A_u8PinNo*4));
			GPIOC->AFRL |= (A_u8AltFunc <<(A_u8PinNo*4));
			break;
		}

	}
	else if (A_u8PinNo >= 8 && A_u8PinNo < 16){

		switch(A_u8PortId){
		case  GPIO_PORTA:
			GPIOA->AFRH &=~ (0b1111 <<((A_u8PinNo-8)*4));
			GPIOA->AFRH |= (A_u8AltFunc <<((A_u8PinNo-8)*4));
			break;

		case  GPIO_PORTB:
			GPIOB->AFRH &=~ (0b1111 <<((A_u8PinNo-8)*4));
			GPIOB->AFRH |= (A_u8AltFunc <<((A_u8PinNo-8)*4));
			break;

		case  GPIO_PORTC:
			GPIOC->AFRH &=~ (0b1111 <<((A_u8PinNo-8)*4));
			GPIOC->AFRH |= (A_u8AltFunc <<((A_u8PinNo-8)*4));
			break;
		}

	}
}

/*set port value task*/

void MGPIO_vSetPortValue(u8 A_u8PortId,u16 A_u8PortVal){

		switch(A_u8PortId){
			case GPIO_PORTA:
				 GPIOA->ODR &= (0x00);
				 GPIOA->ODR |= (A_u8PortVal);
			break;
			case GPIO_PORTB:
				GPIOB->ODR &= (0x00);
				GPIOB->ODR |= (A_u8PortVal);
			break;
			case GPIO_PORTC:
				GPIOC->ODR &= (0x00);
				GPIOC->ODR |= (A_u8PortVal);
			break;
		}

}



void MGPIO_vInit(MGPIO_Config_t * A_xPinConfig){
	MGPIO_vSetPinMode(A_xPinConfig->Port,A_xPinConfig->Pin,A_xPinConfig->Mode);
	MGPIO_vSetPinOutputType(A_xPinConfig->Port,A_xPinConfig->Pin,A_xPinConfig->OutputType);
	MGPIO_vSetPinOutputSpeed(A_xPinConfig->Port,A_xPinConfig->Pin,A_xPinConfig->OutputSpeed);
	MGPIO_vSetPinInputPull(A_xPinConfig->Port,A_xPinConfig->Pin,A_xPinConfig->InputPull);
	MGPIO_vSetAlternativeFunction(A_xPinConfig->Port,A_xPinConfig->Pin,A_xPinConfig->AltFunc);
}





void MGPIO_vTogglePinValue(u8 A_u8PortId, u8 A_u8PinNo){

	switch(A_u8PortId){
		case GPIO_PORTA:
			TOG_BIT(GPIOA->ODR,A_u8PinNo);
		break;
		case GPIO_PORTB:
			TOG_BIT(GPIOB->ODR,A_u8PinNo);
		break;
		case GPIO_PORTC:
			TOG_BIT(GPIOC->ODR,A_u8PinNo);
		break;
	}

}










