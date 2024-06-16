/*
 * HexParser.prg.c
 *
 *  Created on: Jan 25, 2024
 *      Author: moham
 */


#include "HexParser.int.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/FLASH/FLASH_int.h"



#define FLASH_BASE_ADDR     0x8000000

u16 DataBuffer[100] ;


static u8 HexParser_u8Ascii2Hex(u8 A_u8Ascii)
{
	u8 L_u8HexValue = 0;

	if(A_u8Ascii >= '0' && A_u8Ascii <= '9')
	{
		L_u8HexValue = A_u8Ascii - '0' ;
	}
	else if(A_u8Ascii >= 'A' && A_u8Ascii <='F')
	{
		L_u8HexValue = A_u8Ascii - 55 ; // 55='A'-10
	}
	return L_u8HexValue;
}


void HexParser_vParseData(u8 A_pu8Data[])
{
	/* charachter Count variables */
	u8 CC_high, CC_low, CC ;

	/* 4 digits for conversion */
	u8 digit0,digit1,digit2,digit3 ;

	/* Address variable */
	u32 address = 0;

	/* 1- convert charachter count */
	CC_high = HexParser_u8Ascii2Hex(A_pu8Data[1]);
	CC_low = HexParser_u8Ascii2Hex(A_pu8Data[2]);
	CC = (CC_high<<4)|CC_low ;

	/* 2- convert Address */
	digit0 = HexParser_u8Ascii2Hex(A_pu8Data[3]);
	digit1 = HexParser_u8Ascii2Hex(A_pu8Data[4]);
	digit2 = HexParser_u8Ascii2Hex(A_pu8Data[5]);
	digit3 = HexParser_u8Ascii2Hex(A_pu8Data[6]);


	address = (FLASH_BASE_ADDR) |
			  (digit0 << 12)    |
			  (digit1 << 8 )    |
			  (digit2 << 4 )    |
			  (digit3 << 0 );

	for(u8 i=0; i<(CC/2) ; i++)
	{
		digit0 = HexParser_u8Ascii2Hex(A_pu8Data[(4*i)+9]);
		digit1 = HexParser_u8Ascii2Hex(A_pu8Data[(4*i)+10]);
		digit2 = HexParser_u8Ascii2Hex(A_pu8Data[(4*i)+11]);
		digit3 = HexParser_u8Ascii2Hex(A_pu8Data[(4*i)+12]);

		DataBuffer[i] = (digit0 << 12)    |
				        (digit1 << 8 )    |
				        (digit2 << 4 )    |
				        (digit3 << 0 );

	}

	FMI_vFlashWrite(address, DataBuffer, CC/2);

}

void HexParser_vEraseAppData(void){
	FMI_vEraseAppArea();
}

