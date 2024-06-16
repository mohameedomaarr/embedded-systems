/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/



#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/RCC/RCC_cfg.h"
#include "../../MCAL/RCC/RCC_int.h"
#include "../../MCAL/RCC/RCC_prv.h"

#include "../../MCAL/NVIC/NVIC_cfg.h"
#include "../../MCAL/NVIC/NVIC_int.h"
#include "../../MCAL/NVIC/NVIC_prv.h"



static u32 globalStatic_u32GroupConf;

/******************************************************************************/
/*Function: MNVIC_VoidEnablePeripheral	                         			  */
/*I/P Parameters: Interrupt ID              								  */
/*Returns:it returns no thing	                            				  */
/*Desc:This Function Enables the INT of the peripheral in NVIC		          */
/******************************************************************************/
void MNVIC_VoidEnablePeripheral(u8 Copy_u8INTID)
{
    MNVIC->ISER[Copy_u8INTID / 32] = 1 << (Copy_u8INTID % 32);
}

/******************************************************************************/
/*Function: MNVIC_VoidDisablePeripheral	                         			  */
/*I/P Parameters: Interrupt ID              								  */
/*Returns:it returns no thing	                            				  */
/*Desc:This Function Disables the INT of the peripheral in NVIC		          */
/******************************************************************************/
void MNVIC_VoidDisablePeripheral(u8 Copy_u8INTID)
{
    MNVIC->ICER[Copy_u8INTID / 32] = 1 << (Copy_u8INTID % 32);
}

/******************************************************************************/
/*Function: MNVIC_VoidSetPending    	                         			  */
/*I/P Parameters: Interrupt ID              								  */
/*Returns:it returns no thing	                            				  */
/*Desc:This Function Sets pending flag of Peripheral        		          */
/******************************************************************************/
void MNVIC_VoidSetPending(u8 Copy_u8INTID)
{
    MNVIC->ISPR[Copy_u8INTID / 32] = 1 << (Copy_u8INTID % 32);
}

/******************************************************************************/
/*Function: MNVIC_VoidClearPending    	                         			  */
/*I/P Parameters: Interrupt ID              								  */
/*Returns:it returns no thing	                            				  */
/*Desc:This Function Clears pending flag of Peripheral        		          */
/******************************************************************************/
void MNVIC_VoidClearPending(u8 Copy_u8INTID)
{
    MNVIC->ICPR[Copy_u8INTID / 32] = 1 << (Copy_u8INTID % 32);
}

/******************************************************************************/
/*Function: MNVIC_u8GetActive       	                         			  */
/*I/P Parameters: Interrupt ID              								  */
/*Returns:it returns no thing	                            				  */
/*Desc:This Function returns state of active flag in NVIC     		          */
/******************************************************************************/
u8 MNVIC_u8GetActive(u8 Copy_u8INTID)
{
    u8 LOC_u8Active = GET_BIT((MNVIC->IAPR[Copy_u8INTID / 32]), (Copy_u8INTID % 32));
    return LOC_u8Active;
}

/******************************************************************************/
/*Function: MNVIC_voidSetPriorityConfig                         			  */
/*I/P Parameters: Priority option              								  */
/*Returns:it returns no thing	                            				  */
/*Desc:This Function Sets the group and the sub priority configurations       */
/******************************************************************************/
/*
 * Options:- GROUP_4BITS - GROUP_3BITS - GROUP_2BITS - GROUP_1BITS - GROUP_0BITS
/******************************************************************************/
void MNVIC_voidSetPriorityConfig(u8 Copy_u8PriorityOption)
{
    globalStatic_u32GroupConf = 0x05FA0000 | (Copy_u8PriorityOption << 8);
    SCB->AIRCR = globalStatic_u32GroupConf;
}

/******************************************************************************/
/*Function: MNVIC_VoidSetPriority                                			  */
/*I/P Parameters: Interrupt ID              								  */
/*Returns:it returns no thing	                            				  */
/*Desc:This Function Sets the group and the sub priority for required INT     */
/******************************************************************************/
/*
 * Options for Copy_u8GroupPriority:- GROUP_PRIORITY_0 ... GROUP_PRIORITY_15
 * Options for Copy_u8SubPriority  :- SUB_PRIORITY_0   ... SUB_PRIORITY_15
/******************************************************************************/
void MNVIC_VoidSetPriority(s8 Copy_s8INTID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority)
{
    u8 local_u8Priority = Copy_u8SubPriority | Copy_u8GroupPriority << ((globalStatic_u32GroupConf - 0x05FA0300) / 256);
    // Core Peripheral
    if (Copy_s8INTID < 0)
    {
        if (Copy_s8INTID == MEMORY_MANAGE || Copy_s8INTID == BUS_FAULT || Copy_s8INTID == USAGE_FAULT)
        {
        	Copy_s8INTID += 3;
        	SCB->SHPR1 &= (~(0b11111111<<(8 * Copy_s8INTID)));
            SCB->SHPR1 |= ((local_u8Priority) << ((8 * Copy_s8INTID) + 4));
        }
        else if (Copy_s8INTID == SV_CALL)
        {
        	Copy_s8INTID += 7;
        	SCB->SHPR2 &= (~(0b11111111<<(8 * Copy_s8INTID)));
            SCB->SHPR2 |= ((local_u8Priority) << ((8 * Copy_s8INTID) + 4));
        }
        else if (Copy_s8INTID == PEND_SV || Copy_s8INTID == SYSTICK)
        {
        	Copy_s8INTID += 8;
        	SCB->SHPR3 &= (~(0b11111111<<(8 * Copy_s8INTID)));
            SCB->SHPR3 |= ((local_u8Priority) << ((8 * Copy_s8INTID) + 4));
        }
    }
    // External Peripheral
    else if (Copy_s8INTID >= 0)
    {
        MNVIC->IPR[Copy_s8INTID] = local_u8Priority << 4;
    }
}
