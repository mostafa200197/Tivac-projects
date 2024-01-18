/*
 * communication.h
 *
 *  Created on: Nov 21, 2023
 *      Author: DELL G5
 */

#ifndef HAL_COMMUNICATION_COMMUNICATION_H_
#define HAL_COMMUNICATION_COMMUNICATION_H_

#include "MCAL/UART/UART.h"
#include "MCAL/GPIO/GPIO.h"

void TerminalInit(void);
void sendTextToTerminal(uint8_t *data);
uint8_t recieveDataFromTerminal(void);
void sendDataToTerminal(uint8_t *data,uint32_t size);
uint8_t writeToTermianlWithFeedBack(uint8_t arr[],uint8_t end);


#endif /* HAL_COMMUNICATION_COMMUNICATION_H_ */
