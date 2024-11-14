/*
 * KeyPad.h
 *
 * Created: 6/24/2023 5:16:35 AM
 *  Author: moham
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define C1 PD0
#define C2 PD1
#define C3 PD2
#define C4 PD3
#define r1 PD4
#define r2 PD5
#define r3 PD6
#define r4 PD7

void check1(void);
void check2(void);
void check3(void);
void check4(void);


#endif /* KEYPAD_H_ */