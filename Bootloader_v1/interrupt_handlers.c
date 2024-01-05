/*
 * interrupt_handlers.c
 *
 *  Created on: Nov 14, 2023
 *      Author: Mostafa Gamal
 */


#include "interrupt_handlers.h"

;

void systick_handler(void)
{

}




void timer0_handler(void)
{

    TIMER0->ICR |=1; //clear interrupt flag
    //write code here
}
