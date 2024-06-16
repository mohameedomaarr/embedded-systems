/*
 * DMA_int.h
 *
 *  Created on: Jan 18, 2024
 *      Author: moham
 */
#include "../../LIB/STD_TYPES.h"
#ifndef MCAL_DMA_DMA_INT_H_
#define MCAL_DMA_DMA_INT_H_



void MDMA_vInit(u8 Copy_u8StremId);
void MDMA_voidSetAddress(u32 *Copy_u32SrcAddress,u32 *Copy_u32DestAddress,u32 Copy_u32Length,u8 Copy_u8StreamId);
void MDMA_vEnableStream(u8 A_u8StreamID);
void MDMA_vSetStreamCallback(void (*fptr)(void));
void MDMA_voidClearFlagChannel0(void);

#endif /* MCAL_DMA_DMA_INT_H_ */





