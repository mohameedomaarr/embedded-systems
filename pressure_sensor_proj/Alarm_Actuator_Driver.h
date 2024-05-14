#ifndef _A_A_H_
#define _A_A_H_

#include "state.h"
enum
{
    AA_Waiting,
    AA_AlarmOn,
    AA_AlarmOff
} AA_state_id;

// Intialization Function prototype
void AA_init();
// states..
STATE_define(AA_Waiting);
STATE_define(AA_AlarmOn);
STATE_define(AA_AlarmOff);

// global pointer to function
extern void (*AA_State)();

#endif