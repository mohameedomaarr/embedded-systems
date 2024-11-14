/*
 * LedMatrix_cfg.h
 *
 *  Created on: Dec 2, 2023
 *      Author: moham
 */

#ifndef HAL_LEDMATRIX_CFG_H_
#define HAL_LEDMATRIX_CFG_H_

#define NO_COLS 8
#define NO_ROWS 8

#define SCAN_TIME 2500 //DELAY 2.5MS

#define METHOD	LEDMTX_S2P

extern MGPIO_Config_t rows[NO_ROWS];
extern MGPIO_Config_t cols[NO_COLS];

#endif /* HAL_LEDMATRIX_CFG_H_ */
