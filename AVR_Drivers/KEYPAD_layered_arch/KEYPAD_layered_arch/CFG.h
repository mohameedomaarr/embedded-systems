/*
 * CFG.h
 *
 * Created: 6/22/2023 12:45:02 AM
 *  Author: moham
 */ 


#ifndef CFG_H_
#define CFG_H_
#include "std_types.h"
#include "DIO_types.h"
typedef struct{
	DIO_Dir PinDir;
	STD_LevelTypes PinLevel;
	}DIO_PINCFG;
	
	
void DIO_Init(void);

#define pin_count 32

#endif /* CFG_H_ */