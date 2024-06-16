


#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"



#include "MCAL/RCC/RCC_int.h"
#include "MCAL/NVIC/NVIC_int.h"
#include "MCAL/GPIO/GPIO_int.h"

#include "MCAL/EXTI/EXTI_cfg.h"
#include "MCAL/EXTI/EXTI_int.h"
#include "MCAL/SYSTICK/SYSTICK_int.h"
#include "MCAL/SPI/SPI_int.h"
#include "MCAL/UART/UART_int.h"


void
__initialize_hardware(void)
{

}








int main()
{
	// Configuration as HSI/2 --> 8 MHz
	MRCC_vInit();
	// Set Systick Configuration
	MSTK_vInit();
	// Enable GPIOA from RCC
	MRCC_vEnableClock(RCC_AHB1, RCC_EN_GPIOA);
	// Enable USART1 from RCC
	MRCC_vEnableClock(RCC_APB2,RCC_USART1_ENABLE);


	MGPIO_Config_t TX_pin={
		.Port=GPIO_PORTA,
		.Pin=PIN9,
		.Mode=GPIO_MODE_ALTFUNC,
		.OutputSpeed=GPIO_SPEED_MEDIUM,
		.OutputType=GPIO_PUSHPULL,
		.AltFunc=GPIO_AF_7
	};

	MGPIO_Config_t RX_pin={
		.Port=GPIO_PORTA,
		.Pin=PIN10,
		.Mode=GPIO_MODE_ALTFUNC,
		.OutputSpeed=GPIO_SPEED_MEDIUM,
		.OutputType=GPIO_PUSHPULL,
		.AltFunc=GPIO_AF_7
	};


	// Configure USART1 Pins as Alternative Function Push Pull
	MGPIO_vInit(&TX_pin);
	MGPIO_vInit(&RX_pin);


	// Configuration of UART
	USART_InitType uart={9600,MODE_8BIT,STOP_BIT_1,DISABLE,EVEN_PARITY,TX_RX,DISABLE,OVER_SAMPLING_16};
	USART_ClockInitTypeDef uartclock ={DISABLE,0,0,0};
	// Initialization of USART1
	MUSART_voidInit(&uart, &uartclock, USART1);
	// Enable USART1
	MUSART_Enable(USART1);
	// Transmit String

	MUSART_voidTransmitString(USART1, "AT\0" );
	// Infinite loop
  while (1)
  {
    // Add your code here.
  }
}
