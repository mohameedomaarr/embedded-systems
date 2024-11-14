/*
 * EXTI_prv.h
 *
 *  Created on: Nov 20, 2023
 *      Author: moham
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"




#define EXTI_BASE_ADD (0x40013C00)

typedef struct {
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_MemMap_t;



#define EXTI ((volatile EXTI_MemMap_t *)(EXTI_BASE_ADD))



#endif /* MCAL_EXTI_EXTI_PRV_H_ */
