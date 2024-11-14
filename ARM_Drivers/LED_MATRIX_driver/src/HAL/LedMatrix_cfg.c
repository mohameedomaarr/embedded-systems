/*
 * LedMatrix_cfg.c
 *
 *  Created on: Dec 2, 2023
 *      Author: moham
 */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_int.h"
#include "LedMatrix_cfg.h"

/*SET GPIO PIN CONFIG*/
	MGPIO_Config_t rows[NO_ROWS]={
			{.Port=GPIO_PORTA,.Pin=PIN0,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},
			{.Port=GPIO_PORTA,.Pin=PIN1,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},
			{.Port=GPIO_PORTA,.Pin=PIN2,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},
			{.Port=GPIO_PORTA,.Pin=PIN3,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},
			{.Port=GPIO_PORTA,.Pin=PIN4,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},
			{.Port=GPIO_PORTA,.Pin=PIN5,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},
			{.Port=GPIO_PORTA,.Pin=PIN6,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},
			{.Port=GPIO_PORTA,.Pin=PIN7,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},

	};

	MGPIO_Config_t cols[NO_COLS]={
			{.Port=GPIO_PORTB,.Pin=PIN0,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},
			{.Port=GPIO_PORTB,.Pin=PIN1,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},
			{.Port=GPIO_PORTB,.Pin=PIN2,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},
			{.Port=GPIO_PORTB,.Pin=PIN3,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},
			{.Port=GPIO_PORTB,.Pin=PIN4,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},
			{.Port=GPIO_PORTB,.Pin=PIN5,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},
			{.Port=GPIO_PORTB,.Pin=PIN6,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},
			{.Port=GPIO_PORTB,.Pin=PIN7,.Mode=GPIO_MODE_OUTPUT,.OutputSpeed=GPIO_LOW,.OutputType=GPIO_PUSHPULL,.InputPull=GPIO_NO_PULL},

		};
