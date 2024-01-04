/*
 * PY_UART.c
 *
 *  Created on: Nov 26, 2023
 *      Author: DELL G5
 */
#include "applecation/python_Uart/PY_UART.h"


void boot_loader_init(void)
{
    TerminalInit();
    LEDS_INIT();

}

void user_interface(void)
{
    uint8_t i = 0;

    sendTextToTerminal(line);
    sendDataToTerminal("\r", 1);
    sendTextToTerminal(version);
    sendDataToTerminal("\r", 1);
    sendTextToTerminal(line);
    sendDataToTerminal("\r", 1);

    for(i = 0;i<5;i++)
    {
        sendTextToTerminal(arr[i]);
        sendDataToTerminal("\r", 1);
    }

}
