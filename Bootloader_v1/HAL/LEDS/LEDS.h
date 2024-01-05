/*
 * LEDS.h
 *
 *  Created on: Nov 14, 2023
 *      Author: Mostafa Gamal
 */

#ifndef HAL_LEDS_LEDS_H_
#define HAL_LEDS_LEDS_H_

#include "stdint.h"
#include "MCAL/GPIO/GPIO.h"

#define RED_LED PIN1
#define BLUE_LED PIN2
#define GREEN_LED PIN3
#define CYAN_LED BLUE_LED|GREEN_LED
#define PURPLE_LED RED_LED|BLUE_LED
#define YELLOW_LED RED_LED|GREEN_LED
#define WHITE_LED RED_LED|GREEN_LED|BLUE_LED
#define NO_LED 0U

void LEDS_INIT(void);
void LEDS_ON(uint8_t color);
void LEDS_OFF(uint8_t color);
void LEDS_TOGGLE(uint8_t color);
void TestPin_set(void);
void TestPin_clear(void);

#endif /* HAL_LEDS_LEDS_H_ */
