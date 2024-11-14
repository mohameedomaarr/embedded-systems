/*
 * keypad.c
 *
 * Created: 6/24/2023 5:15:27 AM
 * Author : moham
 */ 

#include "KeyPad.h"


int main(void)
{
	DDRD = 0b11110000;
	DDRC = 0b00000010;
    /* Replace with your application code */
    while (1) 
    {
		 check1();
		 check2();
		 check3();
		 check4();

    }
}

