/*
 * DIO_CFG.h
 *
 * Created: 6/28/2023 7:19:31 AM
 *  Author: moham
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