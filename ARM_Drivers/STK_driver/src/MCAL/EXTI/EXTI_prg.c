
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "EXTI_cfg.h"
#include "EXTI_prv.h"
#include "EXTI_int.h"
#include "SYSCFG_prv.h"


static void(*EXTI_LINE_CALLBACK)(void);

void SYSCFG_vSetExtiPort(u8 A_u8LineNo,u8 A_u8PortNo){
	SYSCFG->EXTICR[A_u8LineNo/4] &=~ ((0b1111)<<((A_u8LineNo%4)*4));
	SYSCFG->EXTICR[A_u8LineNo/4] |= ((A_u8PortNo)<<((A_u8LineNo%4)*4));

}


void MEXTI_vINIT(void){

	EXTI->IMR=0;
	EXTI->IMR |= (EXTI_LINE_0_EN<<0)|
				 (EXTI_LINE_1_EN<<1)|
				 (EXTI_LINE_2_EN<<2)|
				 (EXTI_LINE_3_EN<<3)|
				 (EXTI_LINE_4_EN<<4)|
				 (EXTI_LINE_5_EN<<5)|
				 (EXTI_LINE_6_EN<<6)|
				 (EXTI_LINE_7_EN<<7)|
				 (EXTI_LINE_8_EN<<8)|
				 (EXTI_LINE_9_EN<<9)|
				 (EXTI_LINE_10_EN<<10)|
				 (EXTI_LINE_11_EN<<11)|
				 (EXTI_LINE_12_EN<<12)|
				 (EXTI_LINE_13_EN<<13)|
				 (EXTI_LINE_14_EN<<14)|
				 (EXTI_LINE_15_EN<<15);

#if   EXTI_LINE_0_TRIGGER==EXTI_RISING
	SET_BIT(EXTI->RTSR,EXTI_LINE_0);
	CLR_BIT(EXTI->FTSR,EXTI_LINE_0);

#elif EXTI_LINE_0_TRIGGER==EXTI_FALLING
	CLR_BIT(EXTI->RTSR,EXTI_LINE_0);
	SET_BIT(EXTI->FTSR,EXTI_LINE_0);

#elif EXTI_LINE_0_TRIGGER==EXTI_ONCHANGE
	SET_BIT(EXTI->RTSR,EXTI_LINE_0);
	SET_BIT(EXTI->FTSR,EXTI_LINE_0);
#endif


	/*CLR ALL FLAGS */
	EXTI->PR=0xffffffff;

}

void MEXTI_vEnableLine(u8 A_u8Trigger , u8 A_u8LineNo){
	if (A_u8LineNo<16){
		SET_BIT(EXTI->IMR,A_u8LineNo);
		switch(A_u8Trigger){
		case EXTI_RISING:
			SET_BIT(EXTI->RTSR,A_u8LineNo);
			CLR_BIT(EXTI->FTSR,A_u8LineNo);
			break;
		case EXTI_FALLING:
			CLR_BIT(EXTI->RTSR,A_u8LineNo);
			SET_BIT(EXTI->FTSR,A_u8LineNo);
			break;
		case EXTI_ONCHANGE:
			 SET_BIT(EXTI->RTSR,A_u8LineNo);
			 SET_BIT(EXTI->FTSR,A_u8LineNo);
			 break;
		}
	}


}
void MEXTI_vDisableLine(u8 A_u8LineNo){
	if (A_u8LineNo<16){
		CLR_BIT(EXTI->IMR,A_u8LineNo);
	}
}
void MEXTI_vSoftwareTrigger(u8 A_u8LineNo){
	if (A_u8LineNo<16){
			SET_BIT(EXTI->SWIER,A_u8LineNo);
		}
}

void MEXTI_vSetTrigger(u8 A_u8Trigger , u8 A_u8LineNo){
	if (A_u8LineNo<16){

			switch(A_u8Trigger){
			case EXTI_RISING:
				SET_BIT(EXTI->RTSR,A_u8LineNo);
				CLR_BIT(EXTI->FTSR,A_u8LineNo);
				break;
			case EXTI_FALLING:
				CLR_BIT(EXTI->RTSR,A_u8LineNo);
				SET_BIT(EXTI->FTSR,A_u8LineNo);
				break;
			case EXTI_ONCHANGE:
				 SET_BIT(EXTI->RTSR,A_u8LineNo);
				 SET_BIT(EXTI->FTSR,A_u8LineNo);
				 break;
			}
		}
}


void MEXTI_vSetCallBack(u8 A_u8LineNo,void (*A_xfptr)(void)){
	switch(A_u8LineNo){
	case EXTI_LINE_0:
		EXTI_LINE_CALLBACK=A_xfptr;
		break;
	}
}


void EXTI0_IRQHandler(void){
	if(EXTI_LINE_CALLBACK != 0){
		EXTI_LINE_CALLBACK();
	}
	SET_BIT(EXTI->PR,EXTI_LINE_0);

}

