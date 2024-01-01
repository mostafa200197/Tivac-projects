/*
 * delayTimer.c
 *
 *  Created on: Dec 29, 2023
 *      Author: DELL G5
 */

#include "delayTimer.h"


void delayInintTimer1(void)
{
    timer1632_clock(timer0_clk); //enable GPTM0 CLK
    timer_1632_init(TIMER0, CONCATENATED, periodic);
}
void delayTimer1(uint32_t Ms)
{
    uint32_t ticks = ((16000000U)/1000U) * Ms;
    timer_32_SetLoad(TIMER0, ticks);
    timer_start(TIMER0);
    timer_32_bool(TIMER0);
    timer_32_Stop(TIMER0);
}
