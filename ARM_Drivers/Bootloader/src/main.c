
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/RCC/RCC_int.h"
#include "MCAL/NVIC/NVIC_int.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/UART/UART_int.h"
#include "MCAL/SYSTICK/SYSTICK_int.h"
#include "APP/HexParser/HexParser.int.h"
#include "MCAL/FLASH/FLASH_int.h"



void
__initialize_hardware(void)
{

}

u8 G_pu8RxBuffer[50] ;
u8 G_u8RxBufferCounter = 0;


typedef void (*function_t)(void);

function_t App_Call;

u8 TimeoutFlag = 0 ;
u8 EraseFlag   = 0 ;

u8  MUART_vReceive_synch(u8* A_pu8Byte)
{
	u8 L_u8status = 1 ;
	if( GET_BIT(USART1->SR, MUSART_SR_RXNE_BIT) == 1 )
	{
		*A_pu8Byte = USART1->DR ;
	}
	else
	{
		L_u8status = 0;
	}

	return L_u8status ;
}

void STK_Callback(void)
{
	TimeoutFlag = 1 ;

#define SCB_VTOR   *((volatile u32*)(0xE000ED00+0x08))

	SCB_VTOR = 0x08004000 ;

	App_Call = (function_t*) 0x08004004 ;

	App_Call();

}

int main(void)
{
	MRCC_vInit(); // HSI
	MRCC_vEnableClock(RCC_AHB1, RCC_EN_FMI);
	MRCC_vEnableClock(RCC_APB2, RCC_USART1_ENABLE);
	MRCC_vEnableClock(RCC_AHB1, RCC_EN_GPIOA);


MGPIO_Config_t uart_tx_pin = {
		.Port = GPIO_PORTA,
		.Pin  = PIN9,
		.Mode = GPIO_MODE_ALTFUNC,
		.OutputSpeed = GPIO_SPEED_MEDIUM,
		.OutputType = GPIO_PUSHPULL,
		.AltFunc    = GPIO_AF_7
};

MGPIO_Config_t uart_rx_pin = {
		.Port = GPIO_PORTA,
		.Pin  = PIN10,
		.Mode = GPIO_MODE_ALTFUNC,
		.OutputSpeed = GPIO_SPEED_MEDIUM,
		.OutputType = GPIO_PUSHPULL,
		.AltFunc    = GPIO_AF_7
};
	MGPIO_vInit(&uart_tx_pin);
	MGPIO_vInit(&uart_rx_pin);

	USART_InitType uart={9600,MODE_8BIT,STOP_BIT_1,DISABLE,EVEN_PARITY,TX_RX,DISABLE,OVER_SAMPLING_16};
	USART_ClockInitTypeDef uartclock ={DISABLE,0,0,0};
	// Initialization of USART1
	MUSART_voidInit(&uart, &uartclock, USART1);


	// enable STK interrupt
	MSTK_vInit(); // HSI/8 -> 2MHZ -> TickTime = 0.5 us

	MSTK_vSetInterval_Single(15000000*2, STK_Callback);
	u8 L_u8UartRXStatus = 0;
	while(TimeoutFlag == 0)
	{
		L_u8UartRXStatus = MUART_vReceive_synch(&G_pu8RxBuffer[G_u8RxBufferCounter]) ;
		if(L_u8UartRXStatus == 1)
		{
			if(EraseFlag != 1)
			{
				EraseFlag = 1;
				HexParser_vEraseAppData();
			}


			/* stop the timeout */
			MSTK_vStopTimer(); // CLR_BIT(STK->CTRL, EN); STK->VAL = 0;

			if(G_pu8RxBuffer[G_u8RxBufferCounter] == '\n')
			{

				HexParser_vParseData(G_pu8RxBuffer) ;
				MUSART_voidTransmitString(USART1,"ok");
				G_u8RxBufferCounter = 0 ;
			}
			else
			{
				G_u8RxBufferCounter++ ;
			}

			// End of file
			if(G_pu8RxBuffer[8] == '1')
			{
				MSTK_vSetInterval_Single(1000000,STK_Callback);
//				STK_Callback();
			}
		}
	}
}




