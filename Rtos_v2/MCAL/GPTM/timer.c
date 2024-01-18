/*
 * timer.c
 *
 *  Created on: Nov 13, 2023
 *      Author: DELL G5
 */
#include "MCAL/GPTM/timer.h"

void timer1632_clock(timer_number TN)
{
    SYSCTL->RCGCTIMER |= TN; //ENABLE CLOCK TO TIMER
}

void timer_1632_init(Timer_RegDef_t *timer,timer_state TS,timer_mod TM)
{
    timer->CTL &= (~(1<<0));  //make sure timer A is disabled
    switch(TS)
    {
    case TimerA:
        timer->CFG = 0x04; //16 bit mode
        timer->TAMR &= (~(0x3)); //masking the last 2 bits
        if(TM == periodic || TM == one_shot)
        {
            timer->TAMR |= TM; // timer mode (periodic, one_shot);
            timer->TAPR = 0xF3; //244 prescalar (so that the max load value 65535 is exactly 0.998 sec)
        }
        break;
    case TimerB:
        timer->CFG = 0x04; //16 bit mode
        timer->TBMR &= (~(0x3)); //masking the last 2 bits
        if(TM == periodic || TM == one_shot)
        {
            timer->TBMR |= TM; // timer mode (periodic, one_shot);
            timer->TBPR = 0xF3; //244 prescalar (so that the max load value 65535 is exactly 0.998 sec)
        }
        break;
    case CONCATENATED:
        timer->CFG = 0x00; //32 bit mode
        if(TM == periodic || TM == one_shot)
        {
            timer->TAMR |= TM; // timer mode (periodic, one_shot);
        }
        break;
    default:
        break;
    }
}
void timer_32_SetLoad(Timer_RegDef_t *timer,uint32_t load)
{
    timer->TAILR = load;
}
void timer_16_SetLoad(Timer_RegDef_t *timer,uint32_t load,timer_state TS)
{
    switch(TS)
    {
    case TimerA:
        timer->TAILR = load;
        break;
    case TimerB:
        timer->TBILR = load;
        break;
    }
}

void timer_start(Timer_RegDef_t *timer)
{
    timer->CTL |= (1<<0); //enable timer A or timer in 32 bit mode
}

void timer_32_bool(Timer_RegDef_t *timer)
{
    while((timer->RIS)&(0x01)==0){
    } //wait for raw interrupt status bit
    timer->ICR |= 0x01; //clear the raw flag by setting it
}
void timer_32_intterupt_enable(Timer_RegDef_t *timer)
{
    timer->IMR |=0x01;
}
void timer_32_Stop(Timer_RegDef_t *timer){
    timer->CTL &= (~(1<<0));
    timer->ICR |= 0x01; //clear the raw flag by setting it
}


