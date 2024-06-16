/*
 * SYSTICK_int.h
 *
 *  Created on: Nov 26, 2023
 *      Author: moham
 */

#ifndef MCAL_SYSTICK_SYSTICK_INT_H_
#define MCAL_SYSTICK_SYSTICK_INT_H_

void MSTK_vInit(void);
void MSTK_vStartTimer(u32 A_u32LoadValue);
void MSTK_vStopTimer(void);
void MSTK_vSetBusyWait(u32 A_u32Ticks);
void MSTK_vSetInterval_Single(u32 A_u32Ticks,void(*CallBackFunction)(void));
void MSTK_vSetInterval_Periodic(u32 A_u32Ticks,void(*CallBackFunction)(void));

u32 MSTK_u32GetElapsedTime(void);
u32 MSTK_u32GetRemainingTime(void);

#endif /* MCAL_SYSTICK_SYSTICK_INT_H_ */
