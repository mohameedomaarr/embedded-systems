/*
 * ADC.c
 *
 * Created: 7/4/2023 2:02:09 AM
 *  Author: moham
 */ 


#include "ADC.h"
void ADC_Init(){
	ADMUX |= (1<<REFS0)|(1<<REFS1);
	ADCSRA |= (1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2); 
	
}
unsigned short ADC_read(unsigned char channel){
	unsigned short data=0;
	ADMUX = (ADMUX & (0xE0))|(channel & (0x1F));
	ADCSRA |= (1<<ADSC);
	while(!(ADCSRA & (1<<ADIF )));
	ADCSRA |= (1<<ADIF );
	data = ADCL;
	data |= (unsigned short)(ADCH<<8);
	return data;
	
}