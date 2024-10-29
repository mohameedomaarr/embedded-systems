/*
 * DIO_CFG.h
 *
 * Created: 7/7/2020 8:22:14 AM
 *  Author: Mohmed
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_
#include "DIO_types.h"
#include "STD_types.h"
typedef struct {
	DIO_DIR PINDIR;
	STD_leveltypes PINLEVEL;
	}DIO_PINCFG;
void DIO_INT(void);

#define pincount 32

#endif /* DIO_CFG_H_ */