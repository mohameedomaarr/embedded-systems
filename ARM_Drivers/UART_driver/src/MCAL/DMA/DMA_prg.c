/*
 * DMA_prg.c
 *
 *  Created on: Jan 18, 2024
 *      Author: moham
 */
#include "DMA_cfg.h"
#include "DMA_int.h"
#include "DMA_prv.h"



void MDMA_vinit(void){

	DMA2->S[0].CR=0;


}
void MDMA_vSetStream(u8 A_u8StreamID,u32 * A_pu32SrcAddr,u32 * A_pu32DestnationAddr,u32 A_u32DataSize,u32 A_u32BlockSize){

}
void MDMA_vStartStream(u8 A_u8StreamID){

}
void MDMA_vSetStreamCallBack(u8 A_u8StreamID, void(*fptr)(void)){

}





