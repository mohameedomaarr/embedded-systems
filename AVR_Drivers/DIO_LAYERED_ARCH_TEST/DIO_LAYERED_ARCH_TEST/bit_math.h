/*
 * bit_math.h
 *
 * Created: 6/28/2023 5:13:15 AM
 *  Author: moham
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define set_bit(reg,no_bit) (reg |=(1<<no_bit))
#define reset_bit(reg,no_bit) (reg &=~(1<<no_bit))
#define toggle_bit(reg,no_bit) (reg ^=(1<<no_bit))
#define get_bit(reg,no_bit) (reg&=(1<<no_bit))


#endif /* BIT_MATH_H_ */