/*
 * timer.h
 *
 *  Created on: Nov 13, 2023
 *      Author: Mostafa Gamal
 */

#ifndef MCAL_GPTM_TIMER_H_
#define MCAL_GPTM_TIMER_H_

#include "stdint.h"
#include "MCAL/register_map.h"
#include "MCAL/NVIC/NVIC.h"

typedef enum{
 timer0_clk = (1<<0), timer1_clk= (1<<1), timer2_clk= (1<<2), timer3_clk= (1<<3), timer4_clk= (1<<4), timer5_clk= (1<<5)
}timer_number;

typedef enum{
    one_shot = 0x1, periodic = 0x2,IEC = 0x3
}timer_mod;

typedef enum{
    TimerA,TimerB,CONCATENATED
}timer_state;



void timer_1632_init(Timer_RegDef_t *timer,timer_state TS,timer_mod TM);
void timer1632_clock(timer_number TN);
void timer_32_SetLoad(Timer_RegDef_t *timer,uint32_t load);
void timer_16_SetLoad(Timer_RegDef_t *timer,uint32_t load,timer_state TS);
void timer_start(Timer_RegDef_t *timer);
void timer_32_intterupt_enable(Timer_RegDef_t *timer);
void timer_32_bool(Timer_RegDef_t *timer);
void timer_32_Stop(Timer_RegDef_t *timer);

#endif /* MCAL_GPTM_TIMER_H_ */








