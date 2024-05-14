#ifndef _A_M_H_
#define _A_M_H_

#include "state.h"
enum
{
    AM_AlarmOn,
    AM_AlarmOff
} AM_state_id;

// Intialization Function prototype
void AM_init();
// states..

STATE_define(AM_AlarmOn);
STATE_define(AM_AlarmOff);

// global pointer to function
extern void (*AM_State)();

#endif