/*
 * interrupt_handlers.h
 *
 *  Created on: Nov 14, 2023
 *      Author: DELL G5
 */

#ifndef INTERRUPT_HANDLERS_H_
#define INTERRUPT_HANDLERS_H_

#include "MCAL/GPIO/GPIO.h"
#include "MCAL/GPTM/timer.h"
#include "HAL/LEDS/LEDS.h"
#include "My_Rtos/My_Rtos.h"




/*other functions prototypes*/
//uint32_t ticker_value(void);
//void ticker_delay(uint32_t ticks);




/* interrupts IRQs */

void systick_handler(void);
void timer0_handler(void);

#endif /* INTERRUPT_HANDLERS_H_ */
