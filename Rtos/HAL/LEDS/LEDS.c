/*
 * LEDS.c
 *
 *  Created on: Nov 14, 2023
 *      Author: DELL G5
 */
#include "HAL/LEDS/LEDS.h"

void LEDS_INIT(void)
{
    GPIO_CLK_EN(GPIOF_CLK);
    GPIO_INIT(GPIOF, PIN0|PIN1|PIN2|PIN3|PIN4, output);
    GPIO_DIGITAL_ANALOG(GPIOF, PIN0|PIN1|PIN2|PIN3|PIN4, digital);
}
void LEDS_ON(uint8_t color)
{
    GPIO_WRITE(GPIOF, color, high);
}
void LEDS_OFF(uint8_t color)
{
    GPIO_WRITE(GPIOF, color, low);
}
void LEDS_TOGGLE(uint8_t color)
{
    GPIO_TOGGLE(GPIOF, color);
}
void TestPin_set(void)
{
    GPIO_WRITE(GPIOF, PIN4, high);
}
void TestPin_clear(void)
{
    GPIO_WRITE(GPIOF, PIN4, low);
}
