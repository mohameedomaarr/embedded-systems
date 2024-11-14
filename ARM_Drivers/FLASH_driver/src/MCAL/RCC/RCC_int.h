/*
 * RCC_int.h
 *
 *  Created on: Nov 3, 2023
 *      Author: moham
 */

#ifndef MCAL_RCC_INT_H_
#define MCAL_RCC_INT_H_


#define HSEON   16
#define HSEBYP	18
#define CSSON	19
#define HSION	0
#define PLLON	24

#define SW0     0
#define SW1		1

#define RCC_AHB1    0
#define RCC_AHB2	1
#define RCC_APB1	2
#define RCC_APB2	3
#define RCC_AHB1LP	4

#define RCC_EN_GPIOA  0
#define RCC_EN_GPIOB  1

#define RCC_SYSCFG_ENABLE 14

#define RCC_SPI1_ENABLE 12
#define RCC_USART1_ENABLE 4
#define MRCC_PERIPHERAL_EN_DMA2 22
#define RCC_EN_FMI	15


/*
 * and so on ...
 * */


void MRCC_vInit(void) ;
void MRCC_vEnableClock(u32 BusId, u32 PeripheralId);
void MRCC_vDisableClock(u32 BusId, u32 PeripheralId);





#endif /* MCAL_RCC_INT_H_ */
