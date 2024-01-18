/*
 * ADC.h
 *
 *  Created on: Dec 31, 2023
 *      Author: DELL G5
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

typedef enum{
    ADC0_clk=0,
    ADC1_clk=1
}ADCmodule;

typedef enum{
    SS0 = 0,
    SS1 = 1,
    SS2 = 2,
    SS3 = 3
}ADCsequencer;

typedef enum{
    proccesor = 0x0,
    Analog_comparator = 0x1,
    timer = 0x5,
    always = 0xF
}TrigerEvent;

typedef enum{
    s0,
    s1,
    s2,
    s3,
    s4,
    s5,
    s6,
    s7
}ADCsample;
typedef enum{
    AIN0,
    AIN1,
    AIN2,
    AIN3,
    AIN4,
    AIN5,
    AIN6,
    AIN7,
    AIN8,
    AIN9,
    AIN10,
    AIN11
}ADCsrc;
typedef enum{
    NOT_END_BIT = 0X0,
    END_BIT = 2
}ADCendbit;

void ADC_SequenceEnable(ADC_RegDef_t *ADC,ADCsequencer SS);
void ADC_SampleConifg(ADC_RegDef_t *ADC,ADCsequencer SS,ADCsample S,ADCsrc source,ADCendbit END);
void ADC_SequenceInit(ADC_RegDef_t *ADC,ADCsequencer SS,TrigerEvent event);
void ADC_clk(ADCmodule adc);

#endif /* MCAL_ADC_ADC_H_ */
