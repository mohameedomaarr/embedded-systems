/*
 * RTOS.int.h
 *
 *  Created on: Dec 5, 2023
 *      Author: moham
 */

#include "../LIB/STD_TYPES.h"

#ifndef RTOS_RTOS_INT_H_
#define RTOS_RTOS_INT_H_

u8 RTOS_u8CreateTask(  void(*Copy_Handler)(void) , u8 Copy_u8Periodicity, u8 Copy_u8Priority ,u8 Copy_FirstDelay);
u8 RTOS_u8DeleteTask(u8 Copy_u8Priority);
u8 RTOS_u8SuspendTask(u8 Copy_u8Priority);
u8 RTOS_u8ResumeTask(u8 Copy_u8Priority);
void Scheduler(void);





#endif /* RTOS_RTOS_INT_H_ */
