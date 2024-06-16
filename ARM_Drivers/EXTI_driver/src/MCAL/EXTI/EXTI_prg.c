
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "EXTI_cfg.h"
#include "EXTI_prv.h"
#include "EXTI_int.h"
#include "SYSCFG_prv.h"


static void (*EXTI_LINE_0_Callback)(void);

//static void (*EXTI_LINE_1_Callback)(void);
//static void (*EXTI_LINE_2_Callback)(void);


void SYSCFG_vSetExtiPort(u8 A_u8LineNo, u8 A_u8PortNo)
{
	u8 L_u8Index = A_u8LineNo/4;
	u8 L_u8ShiftAmount = (A_u8LineNo%4)*4;

	SYSCFG->EXTICR[L_u8Index] &=~ ((0b1111)    << L_u8ShiftAmount) ;
	SYSCFG->EXTICR[L_u8Index] |= ((A_u8PortNo) << L_u8ShiftAmount) ;
}




void MEXTI_vInit(void)
{
	EXTI->IMR = 0 ;
	EXTI->IMR |= (EXTI_LINE_0_EN << EXTI_LINE_0) |
			     (EXTI_LINE_1_EN << EXTI_LINE_1) /*|
				 (EXTI_LINE_2_EN << 2)*/  ;

#if EXTI_LINE_0_TRIGGER==EXTI_RISING
	SET_BIT(EXTI->RTSR, 0);
#endif

	/* Clear all flags */
	EXTI->PR=0xffffffff;
}

void MEXTI_vEnableLine(u8 A_u8Trigger, u8 A_u8LineNo)
{
	if(A_u8LineNo < 16)
	{
		SET_BIT(EXTI->IMR, A_u8LineNo) ;
		switch(A_u8Trigger)
		{
		case EXTI_RISING:
			SET_BIT(EXTI->RTSR, A_u8LineNo) ;
			CLR_BIT(EXTI->FTSR, A_u8LineNo) ;
			break;
		case EXTI_FALLING:
			SET_BIT(EXTI->FTSR, A_u8LineNo) ;
			CLR_BIT(EXTI->RTSR, A_u8LineNo) ;
			break;
		case EXTI_ONCHANGE:
			SET_BIT(EXTI->RTSR, A_u8LineNo) ;
			SET_BIT(EXTI->FTSR, A_u8LineNo) ;
			break;
		}

	}
}

void MEXTI_vDisableLine( u8 A_u8LineNo)
{
	if(A_u8LineNo < 16)
	{
		CLR_BIT(EXTI->IMR, A_u8LineNo) ;
	}
}



void MEXTI_vSoftwareTrigger(u8 A_u8LineNo)
{
	if(A_u8LineNo < 16)
	{
		SET_BIT(EXTI->SWIER, A_u8LineNo) ;
	}
}

void MEXTI_vSetTrigger(u8 A_u8Trigger, u8 A_u8LineNo)
{
	if(A_u8LineNo < 16)
	{
		switch(A_u8Trigger)
		{
		case EXTI_RISING:
			SET_BIT(EXTI->RTSR, A_u8LineNo) ;
			CLR_BIT(EXTI->FTSR, A_u8LineNo) ;
			break;
		case EXTI_FALLING:
			SET_BIT(EXTI->FTSR, A_u8LineNo) ;
			CLR_BIT(EXTI->RTSR, A_u8LineNo) ;
			break;
		case EXTI_ONCHANGE:
			SET_BIT(EXTI->RTSR, A_u8LineNo) ;
			SET_BIT(EXTI->FTSR, A_u8LineNo) ;
			break;
		}
	}
}

void MEXTI_vSetCallback( u8 A_u8LineNo  ,void (*A_xfptr)(void))
{
	switch(A_u8LineNo)
	{
	case EXTI_LINE_0:
		EXTI_LINE_0_Callback = A_xfptr ;
		break;
	}
}

void MEXTI_vInit_2(EXTI_Config_t* A_xConfig){

	if(A_xConfig->LineNo < 16)
		{
			SET_BIT(EXTI->IMR, A_xConfig->LineNo) ;
			switch(A_xConfig->Trigger)
			{
			case EXTI_RISING:
				SET_BIT(EXTI->RTSR, A_xConfig->LineNo) ;
				CLR_BIT(EXTI->FTSR, A_xConfig->LineNo) ;
				break;
			case EXTI_FALLING:
				SET_BIT(EXTI->FTSR, A_xConfig->LineNo) ;
				CLR_BIT(EXTI->RTSR, A_xConfig->LineNo) ;
				break;
			case EXTI_ONCHANGE:
				SET_BIT(EXTI->RTSR, A_xConfig->LineNo) ;
				SET_BIT(EXTI->FTSR, A_xConfig->LineNo) ;
				break;
			}

		}

}



void  EXTI0_IRQHandler(void)
{
	if(EXTI_LINE_0_Callback != 0)
	{
		EXTI_LINE_0_Callback();
	}
	SET_BIT(EXTI->PR, EXTI_LINE_0);
}

