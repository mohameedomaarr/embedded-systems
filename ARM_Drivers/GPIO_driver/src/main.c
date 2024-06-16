
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/RCC/RCC_int.h"

#define ARM_DELAY(d)	do{unsigned int i=d*500;while(i--){asm("nop");}}while(0);





int main(void){

	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOA);
	//MGPIO_vSetPinMode(GPIO_PORTA,PIN0, GPIO_MODE_OUTPUT);
	//MGPIO_vSetPinOutputSpeed(GPIO_PORTA,PIN0,GPIO_SPEED_LOW);
	//MGPIO_vSetPinOutputType(GPIO_PORTA,PIN0,GPIO_PUSHPULL);

	MGPIO_Config_t led_pin_cfg={
		.Port=GPIO_PORTA,
		.Pin=PIN0,
		.Mode=GPIO_MODE_OUTPUT,
		.OutputSpeed=GPIO_LOW,
		.OutputType=GPIO_PUSHPULL,
		.InputPull=GPIO_NO_PULL,
	};

	MGPIO_vInit(&led_pin_cfg);
	MGPIO_vSetPinValue(GPIO_PORTA,PIN0,GPIO_HIGH);

	while(1){
			int i;
			for(i=0;i<=5;i++){
				MGPIO_vSetPinValue(GPIO_PORTA,PIN0,GPIO_HIGH);
				//ARM_DELAY(5000)
				//MGPIO_vSetPinValue(GPIO_PORTA,PIN0,GPIO_LOW);
				//ARM_DELAY(5000)

			}

	}



	return 0;
}
