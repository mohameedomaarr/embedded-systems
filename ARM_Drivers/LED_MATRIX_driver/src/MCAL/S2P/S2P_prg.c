#include "../../LIB/STD_TYPES.h"

#include "S2P_cfg.h"
#include "S2P_prv.h"
#include "S2P_int.h"

#include "../GPIO/GPIO_int.h"
#include "../SYSTICK/SYSTICK_int.h"

extern MGPIO_Config_t S2p_data_pin ;
extern MGPIO_Config_t S2p_latch_pin ;
extern MGPIO_Config_t S2p_shift_pin ;


void S2P_vInit(void)
{
	MGPIO_vInit(&S2p_shift_pin);
	MGPIO_vInit(&S2p_latch_pin);
	MGPIO_vInit(&S2p_data_pin);
}

/**
 * send a pulse on Shift pin
 */
static void ShiftData(void)
{
	MGPIO_vSetPinValue(S2p_shift_pin.Port, S2p_shift_pin.Pin, GPIO_HIGH);
	/* delay */
	MSTK_vSetBusyWait(500);
	MGPIO_vSetPinValue(S2p_shift_pin.Port, S2p_shift_pin.Pin, GPIO_LOW);
	/* delay */
	MSTK_vSetBusyWait(500);
}

/**
 * send a pulse on Latch pin
 */
static void LatchData(void)
{
	MGPIO_vSetPinValue(S2p_latch_pin.Port, S2p_latch_pin.Pin, GPIO_HIGH);
	/* delay */
	MGPIO_vSetPinValue(S2p_latch_pin.Port, S2p_latch_pin.Pin, GPIO_LOW);
	/* delay */
}




void S2P_vSendData(u32 A_u32Data)
{
	/* 1- put data on data pin */
	/* 2- Shift data using shift pin
	 * 	2a- send high
	 * 	2b- delay
	 * 	2c- send low
	 *
	 * */

	/* 3- send a latch signal for the output
	 * 	3a- send high
	 * 	3b- delay
	 * 	3c- send low
	 *
	 *  */
	/*------------------------------------------------*/

	for(int i=0; i< 8*S2P_NUMBER_OF_REGS ; i++)
	{
		MGPIO_vSetPinValue(S2p_data_pin.Port, S2p_data_pin.Pin, GET_BIT(A_u32Data, i));
			ShiftData();
	}

	LatchData();




}
