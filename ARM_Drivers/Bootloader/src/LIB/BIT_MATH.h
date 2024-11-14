/*
 * BIT_MATH.h
 *
 *  Created on: Nov 3, 2023
 *      Author: moham
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_


#define SET_BIT(var, bit_no)      ((var) |=  (1 << (bit_no)))

#define CLR_BIT(var, bit_no)      ((var) &= ~(1 << (bit_no)))

#define TOG_BIT(var, bit_no)      ((var) ^=  (1 << (bit_no)))

#define GET_BIT(var, bit_no)     ((((var) >> (bit_no)) & 0x01))


#endif /* LIB_BIT_MATH_H_ */

