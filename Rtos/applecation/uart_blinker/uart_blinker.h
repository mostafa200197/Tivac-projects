/*
 * uart_blinker.h
 *
 *  Created on: Nov 22, 2023
 *      Author: DELL G5
 */

#ifndef APPLECATION_UART_BLINKER_UART_BLINKER_H_
#define APPLECATION_UART_BLINKER_UART_BLINKER_H_

#include "HAL/LEDS/LEDS.h"
#include "HAL/communication/communication.h"

uint8_t IsSimilar(uint8_t arr1[],uint8_t size,uint8_t arr2[]);
void blinker(uint8_t arr[],uint8_t size);
void blinker_main(void);


#endif /* APPLECATION_UART_BLINKER_UART_BLINKER_H_ */
