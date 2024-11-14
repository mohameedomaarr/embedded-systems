
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"



#include "MCAL/RCC/RCC_int.h"
#include "MCAL/NVIC/NVIC_int.h"
#include "MCAL/GPIO/GPIO_int.h"

#include "MCAL/EXTI/EXTI_cfg.h"
#include "MCAL/EXTI/EXTI_int.h"
#include "MCAL/SYSTICK/SYSTICK_int.h"
#include "MCAL/SPI/SPI_int.h"

#include "TFT_test_img.h"
#include "HAL/TFT/TFT_int.h"

void
__initialize_hardware(void)
{

}


//#define ARM_DELAY(d)	do{unsigned int i=d*500;while(i--){asm("nop");}}while(0);


int main(void){

	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOA);
	MRCC_vEnableClock(RCC_APB2,RCC_SYSCFG_ENABLE);
	MRCC_vEnableClock(RCC_APB2,RCC_SPI1_ENABLE);



	MSTK_vInit();
	MSPI_vInit();
	TFT_vInit();

	TFT_vShowImage(tft_test_img,sizeof(tft_test_img)/sizeof(tft_test_img[0]));






	while(1){

	}



	return 0;
}
