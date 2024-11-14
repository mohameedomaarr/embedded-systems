/*
 * TWI.h
 *
 * Created: 8/12/2020 11:26:59 PM
 *  Author: youus
 */ 


#ifndef TWI_H_
#define TWI_H_

#include "LCD.h"

#define  Ps  1
#define TWI_MaxSCL    400000UL 
#define TWBR_val     (((F_CPU/TWI_MaxSCL)-16)*0.5*(1/(4^Ps)))

void TWI_Init(Uint8 myaddress);
Uint8 TWI_start (void);
void TWI_stop (void);
void TWI_Address(Uint8 address);
Uint8 TWI_Data(Uint8 data);
Uint8 TWI_Status(void);
Uint8 TWI_Read(void);
void EEPROM_Write(Uint8 data,Uint8 data_address);
Uint8 EEPROM_Read(Uint8 data_address);

#endif /* TWI_H_ */