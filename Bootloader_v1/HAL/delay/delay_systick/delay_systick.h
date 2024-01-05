/*
 * dealy_systick.h
 *
 *  Created on: Nov 19, 2023
 *      Author: Mostafa Gamal
 */

#ifndef HAL_DELAY_DELAY_SYSTICK_DELAY_SYSTICK_H_
#define HAL_DELAY_DELAY_SYSTICK_DELAY_SYSTICK_H_

#include "MCAL/Systick/Systick.h"
;
void delay_bool_sys(uint32_t load);
void delay_ticker_init(uint32_t load);

#endif /* HAL_DELAY_DELAY_SYSTICK_DELAY_SYSTICK_H_ */
