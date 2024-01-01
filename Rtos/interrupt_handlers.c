/*
 * interrupt_handlers.c
 *
 *  Created on: Nov 14, 2023
 *      Author: DELL G5
 */


#include "interrupt_handlers.h"

//static uint32_t volatile tickCtr;

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



//uint32_t ticker_value(void)
//{
//    uint32_t ticker;
//    interrupts_disable();
//    ticker = tickCtr;
//    interrupts_enable();
//    return ticker;
//}

//void ticker_delay(uint32_t ticks)
//{
//    uint32_t start = ticker_value();
//    while((ticker_value() - start) < ticks){
//
//    }
//}

void timer0_handler(void)
{
    LEDS_TOGGLE(BLUE_LED);
    TIMER0->ICR |=1; //clear interrupt flag
    //write code here
}
