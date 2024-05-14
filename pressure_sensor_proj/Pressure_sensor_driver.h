#ifndef _P_S_DRIVER_H_
#define _P_S_DRIVER_H_

#include "state.h"
enum
{
    PS_Waiting,
    PS_Reading
} PS_state_id;

// Intialization Function prototype
void PS_init();
// states..
STATE_define(PS_Waiting);
STATE_define(PS_Reading);
// global pointer to function
extern void (*PS_State)();

#endif