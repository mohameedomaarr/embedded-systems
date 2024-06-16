
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


#include "RCC_int.h"
#include "RCC_prv.h"
#include "RCC_cfg.h"


void MRCC_vInit(void)
{

#if RCC_HSE_ENABLE == ENABLE
	SET_BIT(RCC->CR, HSEON);
#endif

#if RCC_HSI_ENABLE == ENABLE
	SET_BIT(RCC->CR, HSION);
#endif

#if RCC_CSS_ENABLE == ENABLE
	SET_BIT(RCC->CR, CSSON);
#endif

#if RCC_PLL_ENABLE == ENABLE
	SET_BIT(RCC->CR, PLLON);
#endif

#if HSE_PYB_ENABLE == ENABLE
	SET_BIT(RCC->CR, HSEBYP);
#endif

#if RCC_SYS_CLK == RCC_HSE
	SET_BIT(RCC->CFGR, SW0);
#endif

}



void MRCC_vEnableClock(u32 BusId, u32 PeripheralId){

	if(PeripheralId <= 31 ){

		switch(BusId){
		case RCC_AHB1:
			SET_BIT(RCC->AHB1ENR,PeripheralId);
			break;
		case RCC_AHB2:
			SET_BIT(RCC->AHB2ENR,PeripheralId);
			break;
		case RCC_APB1:
			SET_BIT(RCC->APB1ENR,PeripheralId);
			break;


		default:

		break;
		}
	}




}


void MRCC_vDisableClock(u32 BusId, u32 PeripheralId){

	if(PeripheralId <= 31){

		switch(BusId){
		case RCC_AHB1:
			CLR_BIT(RCC->AHB1ENR,PeripheralId);
			break;
		case RCC_AHB2:
			CLR_BIT(RCC->AHB2ENR,PeripheralId);
			break;
		case RCC_APB1:
			CLR_BIT(RCC->APB1ENR,PeripheralId);
			break;


		default:

		break;
		}
	}


}
