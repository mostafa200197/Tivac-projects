/*
 * delay_systick.c
 *
 *  Created on: Nov 19, 2023
 *      Author: DELL G5
 */

#include "HAL/delay/delay_systick/delay_systick.h"

void delay_bool_sys(uint32_t load)
{
    load = ((16000000U)/1000) * load; //turn ms to clk counts
    systick_init(load);
    systick_start();
    systick_bool();
    systick_stop();
}

void delay_ticker_init(uint32_t load)
{
    //NVIC->SYSPRI3 &= ~(0xFF<<24); //set SYSTICK IRQ as highest priority
    systick_init(load);
    systick_interrupt_enable();
    systick_start();
}
