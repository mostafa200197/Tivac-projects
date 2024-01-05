/*
 * communication.h
 *
 *  Created on: Nov 21, 2023
 *      Author: Mostafa Gamal
 */

#ifndef HAL_COMMUNICATION_COMMUNICATION_H_
#define HAL_COMMUNICATION_COMMUNICATION_H_

#include "MCAL/UART/UART.h"
#include "MCAL/GPIO/GPIO.h"

void TerminalInit(void);
void sendTextToTerminal(uint8_t *data);
uint8_t recieveByteFromTerminal(void);
void sendDataToTerminal(uint8_t *data,uint32_t size);
uint8_t writeToTermianlWithFeedBack(uint8_t arr[],uint8_t end);
void recieveDataFromTermianl(uint8_t *data,uint32_t size);

#endif /* HAL_COMMUNICATION_COMMUNICATION_H_ */
