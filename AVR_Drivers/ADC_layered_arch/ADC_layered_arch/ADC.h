/*
 * ADC.h
 *
 * Created: 7/4/2023 1:58:01 AM
 *  Author: moham
 */ 


#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
void ADC_Init(void);
unsigned short ADC_read(unsigned char);     




#endif /* ADC_H_ */