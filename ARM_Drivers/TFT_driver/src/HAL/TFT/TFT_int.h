/*
 * TFT_int.h
 *
 *  Created on: Jan 12, 2024
 *      Author: moham
 */

#ifndef HAL_TFT_TFT_INT_H_
#define HAL_TFT_TFT_INT_H_

#include "../../LIB/STD_TYPES.h"
void write_cmd(u16 cmd);
void write_data(u16 data);
void TFT_vInit(void);
void TFT_vShowImage(u16 A_img[],u32 A_ImgSize);
void TFT_vSetXPos(u16 xStart,u16 xEnd);
void TFT_vSetYPos(u16 yStart,u16 yEnd);
void TFT_vFillRectangle(u16 color);
void TFT_vFillBackGround(u16 color);


#endif /* HAL_TFT_TFT_INT_H_ */
