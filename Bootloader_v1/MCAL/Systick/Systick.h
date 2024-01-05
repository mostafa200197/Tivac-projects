/*
 * Systick.h
 *
 *  Created on: Nov 14, 2023
 *      Author: Mostafa Gamal
 */

#ifndef MCAL_SYSTICK_SYSTICK_H_
#define MCAL_SYSTICK_SYSTICK_H_

#include "MCAL/register_map.h"
#include "stdint.h"

uint32_t System_clk(void);

void systick_init(uint32_t load);
void systick_start(void);
void systick_interrupt_enable(void);
uint8_t systick_bool(void);
void systick_stop(void);

#endif /* MCAL_SYSTICK_SYSTICK_H_ */
