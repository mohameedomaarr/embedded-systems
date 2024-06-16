
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/RCC/RCC_int.h"
#include "MCAL/NVIC/NVIC_int.h"
#include "MCAL/GPIO/GPIO_int.h"

#include "MCAL/SYSTICK/SYSTICK_int.h"
#include "MCAL/DMA/DMA_int.h"


void
__initialize_hardware(void)
{

}


#define SIZE 500                //Number of Elements to e transfered

#define DMA2_STREAM0    56      // Vector Position Of DMA2 on NVIC

#define DMA2_CHANNEL0   0       //Stream 0

/*Source Array for Processor*/
volatile u32 GLO_u32Source[SIZE];        //initial values Zero

volatile s16 i ;                         //Global Iterator to be used in processor for loop


/*Step 15 : ISR*/
void App_voidTest(void)
{
  /*Any Action : Indicate That Transfer Complete Successfuly*/
	MGPIO_vSetPinValue(GPIO_PORTA,PIN0,GPIO_HIGH);
	/*Clear Flag*/
    MDMA_voidClearFlagChannel0() ;
}

int main(void)
{


	/*Step 1 : Configuration as HSI/2 --> 8 MHz*/
	MRCC_vInit();

	/*Step 2 : Enable GPIO Peripherial Clock For Port A*/
	MRCC_vEnableClock(RCC_AHB1, RCC_EN_GPIOA);

	/*Step 3 : Enable DMA Peripherial Clock */
	MRCC_vEnableClock(RCC_AHB1,MRCC_PERIPHERAL_EN_DMA2);

	/*Step 4 : Set Pin Direction ->> Output*/
	MGPIO_Config_t pin0={
		.Port=GPIO_PORTA,
		.Pin=PIN0,
		.Mode=GPIO_MODE_OUTPUT,
		.OutputSpeed=GPIO_SPEED_MEDIUM,
		.OutputType=GPIO_PUSHPULL,
	};
	MGPIO_vInit(&pin0);

	/*Step 5 : Enable DMA2 From MNVIC*/
	MNVIC_VoidEnablePeripheral(DMA2_STREAM0) ;       //stream

	/*Step 6 : DMA Function CallBack */
	MDMA_vSetStreamCallback(App_voidTest) ;

	/*Step 7 : Distenation Array for Processor*/
	volatile u32 LOC_u32Distenation[SIZE];                   //Garbage

	/*Step 8 :I will Put Data At Source Array and Transfer it to Distenation For DMA*/
    u32 LOC_u32SRC_Array[SIZE];                     //Garbage

    /*Step 9  :The Distenation Array For DMA*/
    u32 LOC_u32Dis_Array[SIZE] ;                    //Garbage

    /*Step 10 :Initialization for Source Array for DMA*/
    u32 LOC_u32Itrator = 0 ;
    for(LOC_u32Itrator = 0 ; LOC_u32Itrator < SIZE ; LOC_u32Itrator++)
    {
      /*Init Source Array From 0 -->499  {0,1,2,.........,SIZE}*/
    	LOC_u32SRC_Array[LOC_u32Itrator] = LOC_u32Itrator ;
    }


    /*Step 11 : Init DMA --> STREAM0*/
    MDMA_vInit(DMA2_CHANNEL0) ;

    /*Step 12 :Set Source Address and Distination Address For DMA*/
    MDMA_voidSetAddress(LOC_u32SRC_Array,LOC_u32Dis_Array,SIZE,DMA2_CHANNEL0) ;

    /*Step 13: Enable DMA  --> STREAM0 */
    MDMA_vEnableStream(DMA2_CHANNEL0) ;

    /*Step 14 : Transfering by Processor*/
    for(i = SIZE-1 ; i >= 0 ; i--)
//    	for( i=0; i< SIZE; i++)
    {
    	LOC_u32Distenation[i] = GLO_u32Source[i] ;    // what happen if i++ become i-- ??????
    }

	/* Loop forever */
	while(1)
	{

	}

    return 0;
}



