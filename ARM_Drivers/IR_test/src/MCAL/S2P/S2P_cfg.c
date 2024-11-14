


/*
 * S2P_cfg.c
 *
 *  Created on: Sep 8, 2022
 *      Author: mazen
 */

#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/GPIO/GPIO_int.h"
#include "S2P_cfg.h"  // optional

MGPIO_Config_t S2p_shift_pin = {
		.Port=GPIO_PORTA,       .Pin=PIN0,
		.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,
		.OutputType=GPIO_PUSHPULL
};

MGPIO_Config_t S2p_latch_pin = {
		.Port=GPIO_PORTA,       .Pin=PIN1,
		.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,
		.OutputType=GPIO_PUSHPULL
};

MGPIO_Config_t S2p_data_pin = {
		.Port=GPIO_PORTA,       .Pin=PIN2,
		.Mode=GPIO_MODE_OUTPUT, .OutputSpeed=GPIO_SPEED_LOW ,
		.OutputType=GPIO_PUSHPULL
};
