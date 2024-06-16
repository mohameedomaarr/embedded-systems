/*
 * FLASH_prg.c
 *
 *  Created on: Jan 23, 2024
 *      Author: moham
 */

#include "FLASH_cfg.h"
#include "FLASH_int.h"
#include "FLASH_prv.h"


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


void FMI_vEraseAppArea(void){

}
void FMI_vEraseSector(u8 A_u8SectorID){
	/*1-wait if flash is busy*/
	while(GET_BIT(FMI->SR,16)==1){}
	/*2-unlock flash register using KEYR*/
	if(GET_BIT(FMI->SR,16)==1){
		FMI->KEYR=FMI_KEY1;
		FMI->KEYR=FMI_KEY2;
	}

	/*select sector number to erase*/
	FMI->CR &=~ ((u32)(0b1111 << 3));
	FMI->CR |= (A_u8SectorID << 3);

	/*4-select erase operation*/
	SET_BIT(FMI->CR , 1);

	/*start erase operation*/
	SET_BIT(FMI->CR , 16);

	/*wait for busy flag*/
	while(GET_BIT(FMI->SR,16)==1){}

	/*clear EOP flag*/
	SET_BIT(FMI->SR , 0);

	/*De-select erase operation (reverse of step 4) */

	CLR_BIT(FMI->CR , 1);
}
void FMI_vFlashWrite(u32 A_u32Addr,u16 * A_pu16Data,u16 A_u16Length){


	/*1-wait if flash is busy*/
	while(GET_BIT(FMI->SR,16)==1){}
	/*2-unlock flash register using KEYR*/
	if(GET_BIT(FMI->SR,16)==1){
		FMI->KEYR=FMI_KEY1;
		FMI->KEYR=FMI_KEY2;
	}

	/*3- select element size (PSIZE)*/
	FMI->CR &=~ ((u32)(0b11<<8));
	FMI->CR |=  (0b01<<8);

	/*4-Activate programming mode (PG bit)*/
	SET_BIT(FMI->CR , 0);

	/*5-write data array on flash addr 	0x8008000+2 -> 0x8008002	u16 data[3]={0x30,0x31,0x31};*/

	for(u16 i=0;i<A_u16Length;i++){

		*((volatile u16*)A_u32Addr)=A_pu16Data[i];
		A_u32Addr +=2;
		/*wait for busy flag*/
		while(GET_BIT(FMI->SR,16)==1){}

		/*clear EOP flag*/
		SET_BIT(FMI->SR , 0);

	}

	/*DEACTIVATE PROGRAMMING MODE*/
	CLR_BIT(FMI->CR , 0);


}




