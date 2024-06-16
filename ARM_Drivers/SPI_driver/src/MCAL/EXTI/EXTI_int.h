/*
 * EXTI_int.h
 *
 *  Created on: Nov 20, 2023
 *      Author: moham
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#define ENABLE  1
#define DISABLE 0

#define EXTI_RISING   1
#define EXTI_FALLING  2
#define EXTI_ONCHANGE 3

#define PORTA_SYS_CFG  0
#define PORTB_SYS_CFG  1
#define PORTC_SYS_CFG  2


typedef enum{
	EXTI_LINE_0,
	EXTI_LINE_1,
	EXTI_LINE_2,
	EXTI_LINE_3,
	EXTI_LINE_4,
	EXTI_LINE_5,
	EXTI_LINE_6,
	EXTI_LINE_7,
	EXTI_LINE_8,
	EXTI_LINE_9,
	EXTI_LINE_10,
	EXTI_LINE_11,
	EXTI_LINE_12,
	EXTI_LINE_13,
	EXTI_LINE_14,
	EXTI_LINE_15
};



typedef struct
{
	u8 LineNo;
	u8 Trigger;
}EXTI_Config_t;


void MEXTI_vInit_2(EXTI_Config_t* A_xConfig);

void MEXTI_vInit(void);

void MEXTI_vEnableLine(u8 A_u8Trigger, u8 A_u8LineNo);
void MEXTI_vDisableLine( u8 A_u8LineNo);

void MEXTI_vSoftwareTrigger(u8 A_u8LineNo);

void MEXTI_vSetTrigger(u8 A_u8Trigger, u8 A_u8LineNo);

void MEXTI_vSetCallback( u8 A_u8LineNo  ,void (*A_xfptr)(void));

void SYSCFG_vSetExtiPort(u8 A_u8LineNo, u8 A_u8PortNo) ;


#endif /* MCAL_EXTI_EXTI_INT_H_ */
