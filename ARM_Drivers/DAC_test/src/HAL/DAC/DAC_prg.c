/*
 * DAC_prg.c
 *
 *  Created on: Jan 10, 2024
 *      Author: moham
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"

#include "DAC_int.h"
#include "DAC_cfg.h"
#include "DAC_prv.h"

extern MGPIO_Config_t dac_pins[DAC_RESOLUTION];

void DAC_vInit(void){

	for(u8 i=0; i<DAC_RESOLUTION ; i++){
		MGPIO_vInit(&dac_pins[i]);
	}

}
void DAC_vAnalogWrite(u8 A_u8Signal){
	for(u8 i=0; i<DAC_RESOLUTION ; i++){
			MGPIO_vSetPinValue(dac_pins[i].Port,dac_pins[i].Pin,GET_BIT(A_u8Signal,i));
		}
}

