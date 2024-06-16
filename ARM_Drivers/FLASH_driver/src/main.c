
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/RCC/RCC_int.h"
#include "MCAL/NVIC/NVIC_int.h"
#include "MCAL/GPIO/GPIO_int.h"

#include "MCAL/SYSTICK/SYSTICK_int.h"



void
__initialize_hardware(void)
{

}

int main(void)
{


	/*Step 1 : Configuration as HSI/2 --> 8 MHz*/
	MRCC_vInit();

	/*Step 2 : Enable GPIO Peripherial Clock For Port A*/
	MRCC_vEnableClock(RCC_AHB1, RCC_EN_GPIOA);

	/**/
	MRCC_vEnableClock(RCC_AHB1LP, RCC_EN_FMI);

	/*Step 4 : Set Pin Direction ->> Output*/
	MGPIO_Config_t pin0={
		.Port=GPIO_PORTA,
		.Pin=PIN0,
		.Mode=GPIO_MODE_OUTPUT,
		.OutputSpeed=GPIO_SPEED_MEDIUM,
		.OutputType=GPIO_PUSHPULL,
	};
	MGPIO_vInit(&pin0);


	u16 data[3]={0x30,0x31,0x31};

	FMI_vFlashWrite(0x8008000,data,3);


	/* Loop forever */
	while(1)
	{

	}

    return 0;
}



