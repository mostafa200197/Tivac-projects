/*
 * NVIC.c
 *
 *  Created on: Nov 18, 2023
 *      Author: Mostafa Gamal
 */

#include "NVIC.h"
//void interrupts_enable(void)
//{
//   __asm(" CPSIE I");
//}
//
//void interrupts_disable(void)
//{
//    __asm(" CPSID I");
//}

void NVIC_interrupt_enable(IRQn_type number)
{
    uint8_t reg = number/31;
    uint8_t bit = number%31;

    switch(reg)
    {
    case 0:
        NVIC->EN0 |= (1<<bit);
        break;
    case 1:
        NVIC->EN1 |= (1<<bit);
        break;
    case 2:
        NVIC->EN2 |= (1<<bit);
        break;
    case 3:
        NVIC->EN3 |= (1<<bit);
        break;
    case 4:
        NVIC->EN4 |= (1<<bit);
        break;
    default:
        break;
    }
}
void NVIC_interrupt_disable(IRQn_type number)
{
    uint8_t reg = number/31;
    uint8_t bit = number%31;

    switch(reg)
    {
    case 0:
        NVIC->EN0 &= ~(1<<bit);
        break;
    case 1:
        NVIC->EN1 &= ~(1<<bit);
        break;
    case 2:
        NVIC->EN2 &= ~(1<<bit);
        break;
    case 3:
        NVIC->EN3 &= ~(1<<bit);
        break;
    case 4:
        NVIC->EN4 &= ~(1<<bit);
        break;
    default:
        break;
    }
}
