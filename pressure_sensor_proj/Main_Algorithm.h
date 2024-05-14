#ifndef _M_A_H_
#define _M_A_H_

#include "state.h"
enum
{
    MA_High_Pressure_Detection
} MA_state_id;

// states..
STATE_define(MA_High_Pressure_Detection);

// global pointer to function
extern void (*MA_State)();

#endif