/*
 * Systick.c
 *
 *  Created on: Nov 14, 2023
 *      Author: DELL G5
 */

#include "Systick.h"

uint32_t cpu_clk = 16000000U;
uint32_t System_clk(void)
{
    uint32_t clk = cpu_clk;
    return clk;

}
void systick_init(uint32_t load)
{
    NVIC->STRELOAD = load; //load compare value
    NVIC->STCURRENT = 0x01; //clear current value
    NVIC->STCTRL |= (1<<2); //system clock source
}

void systick_start(void)
{
    NVIC->STCTRL |= (1<<0); //start systick bit
}

void systick_stop(void)
{
    NVIC->STCTRL &= (~(1<<0)); //clear systick start bit
}

uint8_t systick_bool(void)
{
    while(((NVIC->STCTRL)&(1<<16)) == 0); //bool on the cout bit status
    return 1;
}

void systick_interrupt_enable(void)
{
    NVIC->STCTRL |= (1<<1); //enable interrupt generation
}


