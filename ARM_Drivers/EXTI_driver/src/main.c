
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"


#include "MCAL/RCC/RCC_int.h"
#include "MCAL/NVIC/NVIC_int.h"
#include "MCAL/GPIO/GPIO_int.h"


//#include "MCAL/EXTI/EXTI_cfg.h"

#include "MCAL/EXTI/EXTI_int.h"
#include "MCAL/SYSTICK/SYSTICK_int.h"

//#include "MCAL/EXTI/EXTI_prv.h"




void
__initialize_hardware(void)
{

}


//#define ARM_DELAY(d)	do{unsigned int i=d*500;while(i--){asm("nop");}}while(0);

u8 flag=0;

void toggle(void){
	//MSTK_vSetBusyWait(1000000);//delay 1 sec


	if(flag==0){
		MGPIO_vSetPinValue(GPIO_PORTA, PIN1, GPIO_HIGH );
		flag=1;
		MSTK_vSetBusyWait(1000000);
	}
	else if (flag==1){
		MGPIO_vSetPinValue(GPIO_PORTA, PIN1, GPIO_LOW  );
		flag=0;
		MSTK_vSetBusyWait(1000000);
	}


	//MGPIO_vSetPinValue(GPIO_PORTA, PIN1, GPIO_HIGH );
	//MSTK_vSetBusyWait(1000000);//delay 1 sec
	//MGPIO_vSetPinValue(GPIO_PORTA, PIN1, GPIO_LOW);
	//MSTK_vSetBusyWait(1000000);//delay 1 sec

}




int main(void){


	MGPIO_Config_t led_pin_cfg={
		.Port=GPIO_PORTA,
		.Pin=PIN1,
		.Mode=GPIO_MODE_OUTPUT,
		.OutputSpeed=GPIO_LOW,
		.OutputType=GPIO_PUSHPULL,
		.InputPull=GPIO_NO_PULL,
	};


	MGPIO_Config_t led2_pin_cfg={
		.Port=GPIO_PORTA,
		.Pin=PIN2,
		.Mode=GPIO_MODE_OUTPUT,
		.OutputSpeed=GPIO_LOW,
		.OutputType=GPIO_PUSHPULL,
		.InputPull=GPIO_NO_PULL,
	};


	MGPIO_Config_t Button_cfg={
				.Port=GPIO_PORTA,
				.Pin=PIN0,
				.Mode=GPIO_MODE_INPUT,
				.OutputSpeed=GPIO_HIGH,
				.OutputType=GPIO_PUSHPULL,
				.InputPull=GPIO_IO_PULL_UP,
			};

	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOA);
	MRCC_vEnableClock(RCC_APB2,RCC_SYSCFG_ENABLE);


	MGPIO_vInit(&led_pin_cfg);
	MGPIO_vInit(&led2_pin_cfg);
	MGPIO_vInit(&Button_cfg);

	MSTK_vInit();

	EXTI_Config_t EXT0={.LineNo=EXTI_LINE_0,.Trigger=EXTI_FALLING};
	MEXTI_vInit_2(&EXT0);

	//MEXTI_vInit();
	MEXTI_vEnableLine(EXTI_FALLING,EXTI_LINE_0);
	//MEXTI_vSoftwareTrigger(EXTI_LINE_0);
	MEXTI_vSetCallback(EXTI_LINE_0,toggle);
	SYSCFG_vSetExtiPort(EXTI_LINE_0,GPIO_PORTA);//////////////////////
	//MNVIC_VoidSetPending(EXTI0);

	MNVIC_VoidEnablePeripheral(EXTI0);
	MNVIC_voidSetPriorityConfig(GROUP_2BITS);
	MNVIC_VoidSetPriority(EXTI0,GROUP_PRIORITY_0,SUB_PRIORITY_0);

	while(1){
		//MGPIO_vSetPinValue(GPIO_PORTA, PIN0, GPIO_HIGH );
		//MGPIO_vSetPinValue(GPIO_PORTA, PIN1, GPIO_HIGH );
		MGPIO_vSetPinValue(GPIO_PORTA, PIN2, GPIO_HIGH );




	}



	return 0;
}
