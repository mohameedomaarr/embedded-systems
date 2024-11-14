/*
 * LedMatrix_int.h
 *
 *  Created on: Dec 2, 2023
 *      Author: moham
 */

#ifndef HAL_LEDMATRIX_INT_H_
#define HAL_LEDMATRIX_INT_H_

void LEDMTX_vInit(void);
void LEDMTX_vDisplayFrame(u8 frame[],u32 frame_delay);
void LEDMTX_vDISABLEALLColumns(void);
void LEDMTX_vSetRowValues(u8 A_u8row_values);
void LEDMTX_vSetCurrentColumn(u8 A_u8ColNo);



//void LEDMTX_vDisplayMatrix(u8 matrix[][NO_COLS],u32 matrix_delay);

#endif /* HAL_LEDMATRIX_INT_H_ */
