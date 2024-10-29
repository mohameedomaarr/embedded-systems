/*
 * servo_motor.c
 *
 * Created: 7/9/2023 8:56:00 AM
 * Author : moham
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define mini_count 249
#define max_count 498
#define mini_angle 0
#define max_angle 180

void servo_control(unsigned short angle){
	OCR1A = ((((angle-mini_angle)*(max_count-mini_count))/(max_angle-mini_angle)) + mini_count);
}

int main(void)
{
	DDRD |= (1<<5);
   TCCR1A |= (1<<WGM11)|(1<<COM1A1);
   ICR1 =4999;
   TCCR1B |= (1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10)|(1<<CS11);
    while (1) 
    {
		
		servo_control(30);
		_delay_ms(2000);
		servo_control(90);
		_delay_ms(2000);
		servo_control(180);
		_delay_ms(2000);
		servo_control(0);
    }
}

