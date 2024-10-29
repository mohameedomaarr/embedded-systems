/*
 * bit_math.h
 *
 * Created: 7/7/2020 8:09:49 AM
 *  Author: Mohmed
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define set_bit(reg,no_bit) (reg|=(1<<no_bit))
#define reset_bit(reg,no_bit) (reg&=~(1<<no_bit))
#define toggle_bit (reg,no_bit) (reg^=(1<<no_bit))
#define get_bit(reg,no_bit) ((reg>>no_bit)&1)

#endif /* BIT_MATH_H_ */