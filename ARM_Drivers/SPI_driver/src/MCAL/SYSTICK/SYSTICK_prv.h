/*
 * SYSTICK_prv.h
 *
 *  Created on: Nov 26, 2023
 *      Author: moham
 */

#ifndef MCAL_SYSTICK_SYSTICK_PRV_H_
#define MCAL_SYSTICK_SYSTICK_PRV_H_

#define SYSTICK_BASE_ADDR  0xE000E010

#define STK_ENABLE  0
#define COUNTFLAG 	16

#define STK_AHB 		1
#define STK_AHB_DIV_8 	2


#define CLKSOURCE 	2
#define TICKINT 	1

#define ENABLE  1
#define DISABLE 0

typedef struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;

}SYSTICK_MemMap_t;

#define STK ((volatile SYSTICK_MemMap_t *)(SYSTICK_BASE_ADDR))

#endif /* MCAL_SYSTICK_SYSTICK_PRV_H_ */
