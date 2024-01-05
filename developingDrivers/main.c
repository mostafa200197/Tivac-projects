





#include "MCAL/PWM/PWM.h"
#include "MCAL/GPIO/GPIO.h"
int main(void)
{

    PWM_ModuleInit(Div2);

    GPIO_CLK_EN(GPIOB_CLK);
    GPIO_DIGITAL_ANALOG(GPIOB, PIN6|PIN7, digital);
    GPIO_ALTERNATE_EN(GPIOB, PIN6, M0PWM0_B6);
    GPIO_ALTERNATE_EN(GPIOB, PIN7, M0PWM1_B7);

    PWM_GenConfigLoad(PWM0, GEN0, 319);
    PWM_ComparatorConfig(PWM0, GEN0,PwmA, 160);
    PWM_ComparatorConfig(PWM0, GEN0,PwmB, 80);

    PWM_EnableGenerator(PWM0, GEN0, On);

    PWM_EnableOutput(PWM0, GEN0, PwmA, On);
    PWM_EnableOutput(PWM0, GEN0, PwmB, On);

    while(1){

    }

}



