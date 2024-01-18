/*
 * ADC.c
 *
 *  Created on: Dec 31, 2023
 *      Author: Mostafa Gamal
 */
#include "MCAL/register_map.h"
#include "ADC.h"

void ADC_clk(ADCmodule adc)
{
    /*enable ADC clock gating*/
    SYSCTL->RCGCADC |=(1<<adc);
}
void ADC_SequenceInit(ADC_RegDef_t *ADC,ADCsequencer SS,TrigerEvent event)
{
    /*make sure sequencer is disabled before configuring*/
    ADC->ACTSS &= ~(1<<SS);
    /*chose the trigger event*/
    ADC->EMUX |= (event<<(4*SS));
}
void ADC_SampleConifg(ADC_RegDef_t *ADC,ADCsequencer SS,ADCsample S,ADCsrc source,ADCendbit END)
{
    switch(SS){
    case SS0:
        /*chose the sample source*/
        ADC->SSMUX0 |= (source<<(4*S));
        /*Configure the sample source to be from MUX not temp*/
        ADC->SSCTL0 &= ~(1<<(4*S));
        /*add the end bit if required at this sample*/
        ADC->SSCTL0 |= (END<<(4*S));
        break;
    case SS1:
        ADC->SSMUX1 |= (source<<(4*S));
        ADC->SSCTL0 &= ~(1<<(4*S));
        ADC->SSCTL0 |= (END<<(4*S));
        break;
    case SS2:
        ADC->SSMUX2 |= (source<<(4*S));
        ADC->SSCTL0 &= ~(1<<(4*S));
        ADC->SSCTL0 |= (END<<(4*S));
        break;
    case SS3:
        ADC->SSMUX3 |= (source<<(4*S));
        ADC->SSCTL0 &= ~(1<<(4*S));
        ADC->SSCTL0 |= (END<<(4*S));
        break;
    }
}
void ADC_SequenceEnable(ADC_RegDef_t *ADC,ADCsequencer SS)
{
    /*enable sequencer*/
    ADC->ACTSS |= (1<<SS);
}
