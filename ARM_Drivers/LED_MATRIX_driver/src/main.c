#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_int.h"
#include "HAL/LedMatrix_int.h"
#include "MCAL/SYSTICK/SYSTICK_int.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "RTOS/RTOS.int.h"



void
__initialize_hardware(void)
{

}

void LED1_Task(void){
	MGPIO_vSetPinValue(GPIO_PORTA,PIN0,GPIO_HIGH);
	MSTK_vSetBusyWait(2000000);//delay 2 sec
	MGPIO_vSetPinValue(GPIO_PORTA,PIN0,GPIO_LOW);
	MSTK_vSetBusyWait(2000000);//delay 2 sec
}

void LED2_Task(void){
	MGPIO_vSetPinValue(GPIO_PORTA,PIN0,GPIO_HIGH);
	MSTK_vSetBusyWait(1000000);//delay 1 sec
	MGPIO_vSetPinValue(GPIO_PORTA,PIN0,GPIO_LOW);
	MSTK_vSetBusyWait(1000000);//delay 1 sec
}

void LED3_Task(void){
	MGPIO_vSetPinValue(GPIO_PORTA,PIN0,GPIO_HIGH);
	MSTK_vSetBusyWait(3000000);//delay 3 sec
	MGPIO_vSetPinValue(GPIO_PORTA,PIN0,GPIO_LOW);
	MSTK_vSetBusyWait(3000000);//delay 3 sec
}



int main(){

	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOA);
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOB);
	MRCC_vEnableClock(RCC_APB2,RCC_SYSCFG_ENABLE);
	MSTK_vInit();
	//LEDMTX_vInit();

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

	RTOS_u8CreateTask (  LED1_Task , 20, 0 ,1  );
	RTOS_u8CreateTask (  LED2_Task , 40, 1 ,2  );
	RTOS_u8CreateTask (  LED3_Task , 60, 2 ,3  );

	u16 TickTime=10;

	RTOS_StartOS(TickTime,Scheduler);


	//u8 smiley[]={0, 4, 48, 32, 32, 48, 4, 0};

	//while(1){
		//LEDMTX_vDisplayFrame(smiley,1000);
	//}

	return 0;
}
