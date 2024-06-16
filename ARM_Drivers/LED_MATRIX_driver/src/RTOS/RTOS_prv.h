/*
 * RTOS_prv.h
 *
 *  Created on: Dec 5, 2023
 *      Author: moham
 */

#include "../LIB/STD_TYPES.h"


#ifndef RTOS_RTOS_PRV_H_
#define RTOS_RTOS_PRV_H_

typedef enum{
	Suspended,
	Running
}RunState;


typedef struct {
	void(*TaskHandler)(void);
	u8 Periodicity;
	u8 FirstDelay;
	RunState TaskRunState;
}Task;

#endif /* RTOS_RTOS_PRV_H_ */
