#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/SYSTICK/SYSTICK_int.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/EXTI/EXTI_int.h"
#include "MCAL/NVIC/NVIC_int.h"


#include "MCAL/GPIO/GPIO_prv.h"

void
__initialize_hardware(void)
{

}


MGPIO_Config_t ir_pin={
		.Port=GPIO_PORTA,
		.Pin=PIN0,
		.Mode=GPIO_MODE_INPUT,
		.OutputSpeed=GPIO_LOW,
		.OutputType=GPIO_PUSHPULL,
		.InputPull=GPIO_NO_PULL,
};


MGPIO_Config_t rgb_pins[3]={
		{			.Port=GPIO_PORTA,
				.Pin=PIN1,
				.Mode=GPIO_MODE_INPUT,
				.OutputSpeed=GPIO_LOW,
				.OutputType=GPIO_PUSHPULL,
				.InputPull=GPIO_NO_PULL,},
		{			.Port=GPIO_PORTA,
				.Pin=PIN2,
				.Mode=GPIO_MODE_INPUT,
				.OutputSpeed=GPIO_LOW,
				.OutputType=GPIO_PUSHPULL,
				.InputPull=GPIO_NO_PULL,},
		{			.Port=GPIO_PORTA,
				.Pin=PIN3,
				.Mode=GPIO_MODE_INPUT,
				.OutputSpeed=GPIO_LOW,
				.OutputType=GPIO_PUSHPULL,
				.InputPull=GPIO_NO_PULL,}
};




u8 G_u8StartFlag = 0 ;
u32 FrameData[50];
u32 EdgeCounter=0;

u8 IR_data=0;


void RGB(void){
	switch(IR_data)
	{
	case 70:
		MGPIO_vSetPinValue(rgb_pins[0].Port,rgb_pins[0].Pin,GPIO_HIGH);
		break;
	case 80:
		MGPIO_vSetPinValue(rgb_pins[1].Port,rgb_pins[1].Pin,GPIO_HIGH);
		break;
	}
}

void ParseFrame(void){

	for(u8 i=0 ;i<8;i++){
		if(FrameData[i+17]>=2000 && FrameData[i+17]<=2500 ){
			SET_BIT(IR_data,i);
		}
		else{
			CLR_BIT(IR_data,i);
		}


	}
	G_u8StartFlag=0;
	EdgeCounter=0;
	RGB();
}


void GetFrame(void){

	if(G_u8StartFlag==0){

		MSTK_vSetInterval_Single(1000000,ParseFrame);
		G_u8StartFlag=1;
	}
	else{
		FrameData[EdgeCounter]= MSTK_u32GetElapsedTime();
		MSTK_vSetInterval_Single(1000000,ParseFrame);
		EdgeCounter++;
	}

}



int main(){

	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOA);
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOB);
	MRCC_vEnableClock(RCC_APB2,RCC_SYSCFG_ENABLE);
	MSTK_vInit();



	MGPIO_vInit(&ir_pin);
	for(u8 i=0;i<3;i++){
		MGPIO_vInit(&rgb_pins[i]);
	}

	MEXTI_vSetCallBack(EXTI_LINE_0,GetFrame);
	MEXTI_vEnableLine(EXTI_FALLING,EXTI_LINE_0);
	MRCC_vEnableClock(RCC_APB2,RCC_SYSCFG_ENABLE);
	MNVIC_VoidEnablePeripheral(EXTI0);

	while(1){

//		MSTK_vSetBusyWait(1000000);//delay 1 sec


	}


	return 0;

}
