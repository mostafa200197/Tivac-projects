/*
 * PWM.c
 *
 *  Created on: Jan 4, 2024
 *      Author: DELL G5
 */

#include "PWM.h"

/*enable PWM module and clock divisor*/
void PWM_ModuleInit(PwmClockDivision Div){
    /*enable PWM0 clock*/
    SYSCTL->RCGCPWM |= (1<<0);

    /*configure the PWM divisor*/
    if(Div != Div1)
    {
        /*make PWM divisor as input clock source*/
        SYSCTL->RCC |= (1<<20);
        /*set the division value*/
        SYSCTL->RCC &= ~(0xF<<16);
        SYSCTL->RCC |= (Div<<17);
    }
    else{
        SYSCTL->RCC &= ~(1<<20);
    }
}
void PWM_GenConfigLoad(PWM_RegDef_t *PWM,PwmGenerator gen,uint16_t Load)
{
    switch(gen)
    {
    case GEN0:
        /*enable immediate updating*/
        PWM->_0_CTL = 0;
        PWM->_0_GENA = 0x0000008C;
        PWM->_0_GENB = 0x0000080C;
        PWM->_0_LOAD = Load;
        break;
    case GEN1:
        /*enable immediate updating*/
        PWM->_1_CTL = 0;
        PWM->_1_GENA = 0x0000008C;
        PWM->_1_GENB = 0x0000080C;
        PWM->_1_LOAD = Load;
        break;
    case GEN2:
        /*enable immediate updating*/
        PWM->_2_CTL = 0;
        PWM->_2_GENA = 0x0000008C;
        PWM->_2_GENB = 0x0000080C;
        PWM->_2_LOAD = Load;
        break;
    case GEN3:
        /*enable immediate updating*/
        PWM->_3_CTL = 0;
        PWM->_3_GENA = 0x0000008C;
        PWM->_3_GENB = 0x0000080C;
        PWM->_3_LOAD = Load;
        break;
    }
}
void PWM_ComparatorConfig(PWM_RegDef_t *PWM,PwmGenerator gen,PwmOutId outputId,uint16_t compare)
{
    switch (gen)
    {
        case GEN0:
        {
            if (outputId == PwmA)
            {
                PWM->_0_CMPA = compare;
            }
            else if (outputId == PwmB)
            {
                PWM->_0_CMPB = compare;
            }
            break;
        }

        case GEN1:
        {
            if (outputId == PwmA)
            {
                PWM->_1_CMPA = compare;
            }
            else if (outputId == PwmB)
            {
                PWM->_1_CMPB = compare;
            }
            break;
        }

        case GEN2:
        {
            if (outputId == PwmA)
            {
                PWM->_2_CMPA = compare;
            }
            else if (outputId == PwmB)
            {
                PWM->_2_CMPB = compare;
            }
            break;
        }

        case GEN3:
        {
            if (outputId == PwmA)
            {
                PWM->_3_CMPA = compare;
            }
            else if (outputId == PwmB)
            {
                PWM->_3_CMPB = compare;
            }
            break;
        }
    }
}
void PWM_EnableGenerator(PWM_RegDef_t *PWM,PwmGenerator gen,PwmGenState state)
{
    switch(gen)
    {
    case GEN0:
        if(state ==On)
        {
            PWM->_0_CTL = 1;
        }
        else{
            PWM->_0_CTL = 0;
        }
        break;
    case GEN1:
        if(state ==On)
        {
            PWM->_1_CTL = 1;
        }
        else{
            PWM->_1_CTL = 0;
        }
        break;
    case GEN2:
        if(state ==On)
        {
            PWM->_2_CTL = 1;
        }
        else{
            PWM->_2_CTL = 0;
        }
        break;
    case GEN3:
        if(state ==On)
        {
            PWM->_3_CTL = 1;
        }
        else{
            PWM->_3_CTL = 0;
        }
        break;
    }

}

void PWM_EnableOutput(PWM_RegDef_t *PWM,PwmGenerator gen,PwmOutId outputId,PwmGenState state)
{
    switch (gen)
    {
        case GEN0:
        {
            if (outputId == PwmA)
            {
                PWM->ENABLE |= (1<<0);
            }
            else if (outputId == PwmB)
            {
                PWM->ENABLE |= (1<<1);
            }
            break;
        }

        case GEN1:
        {
            if (outputId == PwmA)
            {
                PWM->ENABLE |= (1<<2);
            }
            else if (outputId == PwmB)
            {
                PWM->ENABLE |= (1<<3);;
            }
            break;
        }

        case GEN2:
        {
            if (outputId == PwmA)
            {
                PWM->ENABLE |= (1<<4);
            }
            else if (outputId == PwmB)
            {
                PWM->ENABLE |= (1<<5);
            }
            break;
        }

        case GEN3:
        {
            if (outputId == PwmA)
            {
                PWM->ENABLE |= (1<<6);
            }
            else if (outputId == PwmB)
            {
                PWM->ENABLE |= (1<<7);
            }
            break;
        }
    }
}



