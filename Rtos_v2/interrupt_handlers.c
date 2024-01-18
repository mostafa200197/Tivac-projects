/*
 * interrupt_handlers.c
 *
 *  Created on: Nov 14, 2023
 *      Author: DELL G5
 */


#include "interrupt_handlers.h"



void systick_handler(void)
{
    TestPin_set();
    //++tickCtr;
    OsTick();
    interrupts_disable;
    OSsched();
    interrupts_enable;
    TestPin_clear();
}





void timer0_handler(void)
{
    LEDS_TOGGLE(BLUE_LED);
    TIMER0->ICR |=1; //clear interrupt flag
    //write code here
}
