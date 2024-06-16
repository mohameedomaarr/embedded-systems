/*
 * RCC_prv.h
 *
 *  Created on: Nov 3, 2023
 *      Author: moham
 */

#ifndef MCAL_RCC_PRV_H_
#define MCAL_RCC_PRV_H_



//#include "../src/LIB/STD_TYPES.h"





#define RCC_BASE_ADDR		0x40023800

typedef struct
{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 reserved1 ;
	u32 reserved2 ;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 reserved3 ;
	u32 reserved4 ;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 reserved5 ;
	u32 reserved6 ;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 reserved7 ;
	u32 reserved8 ;
	u32 RCC_AHB1LPENR;
	u32 RCC_AHB2LPENR;
	u32 reserved9 ;
	u32 reserved10 ;
	u32 RCC_APB1LPENR;
	u32 RCC_APB2LPENR;
}RCC_MemMap_t;


#define RCC  ((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))






#endif /* MCAL_RCC_PRV_H_ */
