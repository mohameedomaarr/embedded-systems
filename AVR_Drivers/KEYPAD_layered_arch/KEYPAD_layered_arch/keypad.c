/*
* keypad.c
*
* Created: 6/24/2023 5:20:36 AM
*  Author: moham
*/

#include "KeyPad.h"
#include "bit_math.h"

void check1(void){
	PORTD_reg=0xEF;
	if(get_bit(PIND_reg,C1) == 0){
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C1) == 0);
		reset_bit(PORTC,1);
	}
	else if (get_bit(PIND_reg,C2) == 0)
	{
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C2) == 0);
		reset_bit(PORTC,1);
	}
	else if (get_bit(PIND_reg,C3) == 0)
	{
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C3) == 0);
		reset_bit(PORTC,1);
	}
	else if (get_bit(PIND_reg,C4) == 0)
	{
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C4) == 0);
		reset_bit(PORTC,1);
	}
}


void check2(void){
	PORTD_reg=0xDF;
	if(get_bit(PIND_reg,C1) == 0){
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C1) == 0);
		reset_bit(PORTC,1);
	}
	else if (get_bit(PIND_reg,C2) == 0)
	{
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C2) == 0);
		reset_bit(PORTC,1);
	}
	else if (get_bit(PIND_reg,C3) == 0)
	{
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C3) == 0);
		reset_bit(PORTC,1);
	}
	else if (get_bit(PIND_reg,C4) == 0)
	{
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C4) == 0);
		reset_bit(PORTC,1);
	}
	
}
void check3(void){
	PORTD_reg=0xBF;
	if(get_bit(PIND_reg,C1) == 0){
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C1) == 0);
		reset_bit(PORTC,1);
	}
	else if (get_bit(PIND_reg,C2) == 0)
	{
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C2) == 0);
		reset_bit(PORTC,1);
	}
	else if (get_bit(PIND_reg,C3) == 0)
	{
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C3) == 0);
		reset_bit(PORTC,1);
	}
	else if (get_bit(PIND_reg,C4) == 0)
	{
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C4) == 0);
		reset_bit(PORTC,1);
	}
}
void check4(void){
	PORTD_reg=0x7F;
	if(get_bit(PIND_reg,C1) == 0){
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C1) == 0);
		reset_bit(PORTC,1);
	}
	else if (get_bit(PIND_reg,C2) == 0)
	{
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C2) == 0);
		reset_bit(PORTC,1);
	}
	else if (get_bit(PIND_reg,C3) == 0)
	{
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C3) == 0);
		reset_bit(PORTC,1);
	}
	else if (get_bit(PIND_reg,C4) == 0)
	{
		set_bit(PORTC,1);
		while(get_bit(PIND_reg,C4) == 0);
		reset_bit(PORTC,1);
	}
	
}

