/*
 * PWM.h
 *
 *  Created on: Jan 4, 2024
 *      Author: DELL G5
 */

#ifndef MCAL_PWM_PWM_H_
#define MCAL_PWM_PWM_H_

#include "mcal/register_map.h"
#include "MCAL/GPIO/GPIO.h"

typedef enum{
    Div2=0x0,
    Div4=0x1,
    Div8=0x2,
    Div16=0x3,
    Div32=0x4,
    Div64=0x7,
    Div1
}PwmClockDivision;
typedef enum{
    GEN0,
    GEN1,
    GEN2,
    GEN3
}PwmGenerator;
typedef enum{
    PwmA,PwmB
}PwmOutId;
typedef enum{
    On,Off
}PwmGenState;

void PWM_ModuleInit(PwmClockDivision Div);
void PWM_GenConfigLoad(PWM_RegDef_t *PWM,PwmGenerator gen,uint16_t Load);
void PWM_ComparatorConfig(PWM_RegDef_t *PWM,PwmGenerator gen,PwmOutId outputId,uint16_t compare);
void PWM_EnableGenerator(PWM_RegDef_t *PWM,PwmGenerator gen,PwmGenState state);
void PWM_EnableOutput(PWM_RegDef_t *PWM,PwmGenerator gen,PwmOutId outputId,PwmGenState state);



#endif /* MCAL_PWM_PWM_H_ */
