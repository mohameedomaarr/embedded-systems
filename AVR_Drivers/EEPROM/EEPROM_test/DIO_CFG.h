/*
* DIO_CFG.h
*
* Created: 7/7/2020 5:37:46 PM
*  Author: youus
*/


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO.h"

typedef struct

{
	DIO_DIR PinDir;
	STD_Levels PinLevel;
	
}DIO_PinCfg;

#define Pincount 32

void DIO_init(void);



#endif /* DIO_CFG_H_ */