/*
 * wifi.c
 *
 *  Created on: Apr 13, 2024
 *      Author: moham
 */



// NOTE: These realtive paths might not be correct, modify them according to your project

#include "../LIB/STD_TYPES.h"
#include "../MCAL/UART/UART_int.h"

volatile char recv_buffer[100];
static u32 BufferIterator = 0;
u8 uart_flag = 0;

void UART_Callback(void)
{
	recv_buffer[BufferIterator] = MUSART_u8ReadDataRegister(USART1);
	BufferIterator ++ ;

}

void ESP8266_vInit(void)
{
	MUSART1_voidSetCallBack(UART_Callback);

	USART_InitType uart={115200,MODE_8BIT,STOP_BIT_1,DISABLE,EVEN_PARITY,TX_RX,DISABLE,OVER_SAMPLING_16};
	USART_ClockInitTypeDef uartclock ={DISABLE,0,0,0};
	// Initialization of USART1
	MUSART_voidInit(&uart, &uartclock, USART1);


	// disable the Echo
	MUSART_voidTransmitString(USART1, "ATE0\r\n" );

	// set Mode: station+AccessPoint
	MUSART_voidTransmitString(USART1,"AT+CWMODE=3\r\n");

}


void ESP8266_vConnectToAccessPoint(char* ssid, char* password)
{
	MUSART_voidTransmitString(USART1,"AT+CWJAP_CUR=\"");
	MUSART_voidTransmitString(USART1,ssid);
	MUSART_voidTransmitString(USART1,"\",\"");
	MUSART_voidTransmitString(USART1,password);
	MUSART_voidTransmitString(USART1,"\"\r\n");

	// STK_busywaitdelay(5)
}


void ESP8266_vOpenServerTCPConnection(char* ServerIp, char* PortNo)
{
	MUSART_voidTransmitString(USART1,"AT+CIPSTART=\"TCP\",\"");
	MUSART_voidTransmitString(USART1,ServerIp);
	MUSART_voidTransmitString(USART1,"\",");
	MUSART_voidTransmitString(USART1,PortNo);
	MUSART_voidTransmitString(USART1,"\r\n");
}


void ESP8266_vSendHttpRequest(char* url, char* length)
{
	MUSART_voidTransmitString(USART1,"AT+CIPSEND=");
	MUSART_voidTransmitString(USART1,length);
	MUSART_voidTransmitString(USART1,"\r\n");

	// delay for 1 or 2  seconds if needed

	MUSART_voidTransmitString(USART1,url);
	MUSART_voidTransmitString(USART1,"\r\n");
}















