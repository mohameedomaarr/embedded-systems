/*
 * FLASH_int.h
 *
 *  Created on: Jan 23, 2024
 *      Author: moham
 */

#include "../../LIB/STD_TYPES.h"

#ifndef MCAL_FLASH_FLASH_INT_H_
#define MCAL_FLASH_FLASH_INT_H_


void FMI_vEraseAppArea(void);
void FMI_vEraseSector(u8 A_u8SectorID);
void FMI_vFlashWrite(u32 A_u32Addr,u16 * A_pu16Data,u16 A_u16Length);


#endif /* MCAL_FLASH_FLASH_INT_H_ */
