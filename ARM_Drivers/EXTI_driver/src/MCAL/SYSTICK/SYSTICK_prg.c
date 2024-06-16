/*
 * SYSTICK_prg.c
 *
 *  Created on: Nov 26, 2023
 *      Author: moham
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "SYSTICK_cfg.h"
#include "SYSTICK_int.h"
#include "SYSTICK_prv.h"

static u8 G_u8SingleFlag;

static void (*STK_Callback)(void);

void MSTK_vInit(void){
	/*clock source*/
#if STK_CLK_SOURCE == STK_AHB
	SET_BIT(STK->CTRL,CLKSOURCE);
#elif STK_CLK_SOURCE == STK_AHB_DIV_8
	CLR_BIT(STK->CTRL,CLKSOURCE);
#endif
	/*INERRUPT ENABLE OR DISABLE*/

#if STK_INTERRUPT_EN==ENABLE
	SET_BIT(STK->CTRL,TICKINT);
#endif
}
void MSTK_vStartTimer(u32 A_u32LoadValue){
	STK->LOAD=A_u32LoadValue;
	SET_BIT(STK->CTRL,STK_ENABLE);
}
void MSTK_vStopTimer(void){
	CLR_BIT(STK->CTRL,STK_ENABLE);
}
void MSTK_vSetBusyWait(u32 A_u32Ticks){
	/*1-RESET TIMER VALUE AND FLAG */
	STK->VAL=0;
	/*2- LOAD TIMER WITH VALUE*/
	STK->LOAD=A_u32Ticks;
	/*3- START TIMER */
	SET_BIT(STK->CTRL,STK_ENABLE);
	/*4- WAIT FOR TIMER FLAG*/
	while(GET_BIT(STK->CTRL,COUNTFLAG)!=1);
	/*5- STOP TIMER */
	CLR_BIT(STK->CTRL,STK_ENABLE);

}
void MSTK_vSetInterval_Single(u32 A_u32Ticks,void(*CallBackFunction)(void)){
	/*0- SET CALLBACK FUNC*/
	STK_Callback=CallBackFunction;
	G_u8SingleFlag=1;
	/*1-RESET TIMER VALUE AND FLAG */
	STK->VAL=0;
	/*2- LOAD TIMER WITH VALUE*/
	STK->LOAD=A_u32Ticks;
	/*3- START TIMER */
	SET_BIT(STK->CTRL,STK_ENABLE);
}
void MSTK_vSetInterval_Periodic(u32 A_u32Ticks,void(*CallBackFunction)(void)){
	/*0- SET CALLBACK FUNC*/
	STK_Callback=CallBackFunction;
	G_u8SingleFlag=0;
	/*1-RESET TIMER VALUE AND FLAG */
	STK->VAL=0;
	/*2- LOAD TIMER WITH VALUE*/
	STK->LOAD=A_u32Ticks;
	/*3- START TIMER */
	SET_BIT(STK->CTRL,STK_ENABLE);
}
u32 MSTK_u32GetElapsedTime(void){
	return((STK->LOAD)-(STK->VAL));
}
u32 MSTK_u32GetRemainingTime(void){
	return(STK->VAL);
}


void Systick_Handler(void){
	if (STK_Callback != 0){
		STK_Callback();
	}

	if(G_u8SingleFlag){
		G_u8SingleFlag=0;
		/* STOP TIMER */
		CLR_BIT(STK->CTRL,STK_ENABLE);
	}

}



