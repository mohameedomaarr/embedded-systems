/*
 * FLASH_prv.h
 *
 *  Created on: Jan 23, 2024
 *      Author: moham
 */

#ifndef MCAL_FLASH_FLASH_PRV_H_
#define MCAL_FLASH_FLASH_PRV_H_

#include "../../LIB/STD_TYPES.h"

#define FMI_KEY1	0x45670123
#define FMI_KEY2	0xCDEF89AB

#define FLASH_BASE_ADDR 	0x40023C00

typedef struct {

	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 OPTCR;

}MFMI_MemMap_t;


#define FMI ((volatile MFMI_MemMap_t*)(FLASH_BASE_ADDR))

#endif /* MCAL_FLASH_FLASH_PRV_H_ */
