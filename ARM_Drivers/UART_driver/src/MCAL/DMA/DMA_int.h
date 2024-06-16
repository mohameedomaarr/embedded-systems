/*
 * DMA_int.h
 *
 *  Created on: Jan 18, 2024
 *      Author: moham
 */

#ifndef MCAL_DMA_DMA_INT_H_
#define MCAL_DMA_DMA_INT_H_

void MDMA_vinit(void);
void MDMA_vSetStream(u8 A_u8StreamID,u32 * A_pu32SrcAddr,u32 * A_pu32DestnationAddr,u32 A_u32DataSize,u32 A_u32BlockSize);
void MDMA_vStartStream(u8 A_u8StreamID);
void MDMA_vSetStreamCallBack(u8 A_u8StreamID, void(*fptr)(void));


#endif /* MCAL_DMA_DMA_INT_H_ */





