/*
 * LedMatrix_prg.c
 *
 *  Created on: Dec 2, 2023
 *      Author: moham
 */


#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/GPIO/GPIO_int.h"
#include "../MCAL/SYSTICK/SYSTICK_int.h"
#include "../MCAL/S2P/S2P_int.h"

#include "LedMAtrix_prv.h"
#include "LedMatrix_cfg.h"
#include "LedMatrix_int.h"

void LEDMTX_vInit(void){

#if	METHOD == LEDMTX_DIRECT

	for(int i=0;i<NO_COLS;i++){
		MGPIO_vInit(&cols[i]);
	}
	for(int i=0;i<NO_ROWS;i++){
		MGPIO_vInit(&rows[i]);
	}
#endif

#if	METHOD == LEDMTX_S2P
	S2P_vInit();
#endif

	}


void LEDMTX_vDISABLEALLColumns(void){
	for(int i=0; i<NO_COLS;i++){
		MGPIO_vSetPinValue(cols[i].Port,cols[i].Pin,GPIO_LOW);
	}
}


void LEDMTX_vSetRowValues(u8 A_u8row_values){
	for(int i=0; i<NO_ROWS;i++){
		MGPIO_vSetPinValue(rows[i].Port,rows[i].Pin,GET_BIT(A_u8row_values,i));
	}
}

void LEDMTX_vSetCurrentColumn(u8 A_u8ColNo){
	MGPIO_vSetPinValue(cols[A_u8ColNo].Port,cols[A_u8ColNo].Pin,GPIO_HIGH);
}

void LEDMTX_vDisplayFrame(u8 frame[],u32 frame_delay){
	//u32 Lu32Count=0;

#if METHOD==LEDMTX_S2P
	u16 L_u16S2PData=0;
#endif


	for(u32 j=0 ; j<=frame_delay;j++){
		for (int i=0 ; i<=NO_COLS;i++){
#if METHOD==LEDMTX_DIRECT
			/*DISABLE ALL COLUMNS */
			LEDMTX_vDISABLEALLColumns();
			/*SET ROW VALUE*/
			LEDMTX_vSetRowValues(frame[i]);
			/*SET CURRENT COL VALUE*/
			LEDMTX_vSetCurrentColumn(i);
#endif

#if METHOD==LEDMTX_S2P
			/*DISABLE ALL COLUMNS */
			L_u16S2PData=0x00FF;
			S2P_vSendData(L_u16S2PData);
			/*SET ROW VALUE*/
			L_u16S2PData=((u16)frame[i]) | ((u16)((1<<i)<<8));
			/*SET CURRENT COL VALUE*/
			S2P_vSendData(L_u16S2PData);
#endif

			/*DELAY WITH SUITABLE FPS*/
			MSTK_vSetBusyWait(SCAN_TIME);//delay 2.5 MS
		}
	}
}




