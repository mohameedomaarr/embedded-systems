/*
 * UART_int.h
 *
 *  Created on: Jan 16, 2024
 *      Author: moham
 */
#include "UART_prv.h"

#ifndef HAL_UART_INT_H_
#define HAL_UART_INT_H_

#define OVER_SAMPLING_16	0
#define OVER_SAMPLING_8 	1

#define TX_ONLY             0
#define RX_ONLY             1
#define TX_RX               2

#define EVEN_PARITY         0
#define ODD_PARITY          1

#define MODE_8BIT			0
#define MODE_9BIT			1

#define STOP_BIT_1			0
#define STOP_BIT_0_5		1
#define STOP_BIT_2			2
#define STOP_BIT_1_5		3

#define ENABLE				1
#define DISABLE				0


void MUSART_voidInit(USART_InitType *A_InitStruct,USART_ClockInitTypeDef *A_ClockInitStruct,USART_t *USARTx);
void MUSART_Enable(USART_t *USARTx);
void MUSART_voidTransmitByte (USART_t *USARTx,u8 A_u8Byte);
void MUSART_voidTransmitString (USART_t *USARTx, u8 * A_ptru8String );
u8 MUSART_u8ReceiveByteSynchNonBlocking ( USART_t *USARTx );
u8 * MUSART_ptrReceiveStringSynchNonBlocking ( USART_t *USARTx );
void MUSART_RxIntSetStatus(USART_t *USARTx, u8 copy_u8Status);
void MUSART_voidClearFlags(USART_t *USARTx);
u8 MUSART_u8ReadDataRegister(USART_t *USARTx);
void MUSART1_voidSetCallBack( void (*ptr) (void) );
void MUSART2_voidSetCallBack( void (*ptr) (void) );
void MUSART6_voidSetCallBack( void (*ptr) (void) );

u8 MUSART_u8ReceiveByte ( USART_t *USARTx );
u8 * MUSART_ptrReceiveString ( USART_t *USARTx );

#endif /* HAL_UART_INT_H_ */
