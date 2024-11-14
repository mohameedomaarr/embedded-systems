/*
 * SPI_prv.h
 *
 *  Created on: Jan 12, 2024
 *      Author: moham
 */

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_

#include "../../LIB/STD_TYPES.h"

#define SPI1_BASEADDR 0x40013000

#define CPHA 0
#define CPOL 1
#define MSTR 2

typedef struct {

	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;


}MSPI_MemMap_t;


#define SPI1 ((volatile MSPI_MemMap_t * )(SPI1_BASEADDR))


#endif /* MCAL_SPI_SPI_PRV_H_ */
