#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/SYSTICK/SYSTICK_int.h"
#include "MCAL/GPIO/GPIO_int.h"




void
__initialize_hardware(void)
{

}

int main(){

	MRCC_vInit();//HSI 16MHZ //AHB_BUS NO_PRE_SCALER
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOA);
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOB);
	MRCC_vEnableClock(RCC_APB2,RCC_SYSCFG_ENABLE);
	MSTK_vInit();//(AHB/8)=1MHZ


	MGPIO_Config_t led_pin_cfg1={
			.Port=GPIO_PORTA,
			.Pin=PIN0,
			.Mode=GPIO_MODE_OUTPUT,
			.OutputSpeed=GPIO_LOW,
			.OutputType=GPIO_PUSHPULL,
			.InputPull=GPIO_NO_PULL,
		};

	MGPIO_Config_t led_pin_cfg2={
			.Port=GPIO_PORTA,
			.Pin=PIN1,
			.Mode=GPIO_MODE_OUTPUT,
			.OutputSpeed=GPIO_LOW,
			.OutputType=GPIO_PUSHPULL,
			.InputPull=GPIO_NO_PULL,
		};

	MGPIO_Config_t led_pin_cfg3={
			.Port=GPIO_PORTA,
			.Pin=PIN2,
			.Mode=GPIO_MODE_OUTPUT,
			.OutputSpeed=GPIO_LOW,
			.OutputType=GPIO_PUSHPULL,
			.InputPull=GPIO_NO_PULL,
		};

	MGPIO_vInit(&led_pin_cfg1);
	MGPIO_vInit(&led_pin_cfg2);
	MGPIO_vInit(&led_pin_cfg3);





	while(1){

	}

	return 0;
}
