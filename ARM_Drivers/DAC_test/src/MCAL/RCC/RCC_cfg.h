/*
 * RCC_cfg.h
 *
 *  Created on: Nov 3, 2023
 *      Author: moham
 */

#ifndef MCAL_RCC_CFG_H_
#define MCAL_RCC_CFG_H_


#define RCC_HSE_ENABLE		DISABLE
#define RCC_HSI_ENABLE		ENABLE		//16MHZ
#define RCC_PLL_ENABLE		ENABLE


#define RCC_CSS_ENABLE		ENABLE

#define RCC_SYS_CLK			RCC_HSE  /*RCC_HSE OR RCC_HSI OR RCC_PLL*/

#define HSE_PYB_ENABLE		DISABLE




#endif /* MCAL_RCC_CFG_H_ */
