#include "LIB/STD_TYPES.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/SYSTICK/SYSTICK_int.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "song.h"
#include "HAL/DAC/DAC_int.h"

#include "MCAL/GPIO/GPIO_prv.h"

void
__initialize_hardware(void)
{

}

void DAC_ISR(void){
	static u32 song_iterator=0;
	//ODR=song_test[song_iterator]
	GPIOA->ODR &=~ (0xff);
	//GPIOA->ODR|=((u16)song_test_raw[song_iterator] & 0x00ff);

	DAC_vAnalogWrite(song_test_raw[song_iterator]);
	if (song_iterator < sizeof(song_test_raw)/sizeof(song_test_raw[0])){
		song_iterator++;
	}
	else{
		song_iterator=0;
	}
}



int main(){

	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOA);
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOB);
	MRCC_vEnableClock(RCC_APB2,RCC_SYSCFG_ENABLE);
	MSTK_vInit();
	DAC_vInit();

	MSTK_vSetInterval_Periodic(3125,DAC_ISR);//MSTK_vSetInterval_Periodic(NUMBER_TICKS_125MICRO_SEC,DAC_ISR);



	while(1){

//		MSTK_vSetBusyWait(1000000);//delay 1 sec


	}


	return 0;

}




