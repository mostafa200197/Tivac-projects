/*
 * communication.c
 *
 *  Created on: Nov 21, 2023
 *      Author: DELL G5
 */

#include "communication.h"



void TerminalInit(void)
{
    GPIO_CLK_EN(GPIOA_CLK);
    GPIO_INIT(GPIOA, PIN0, input);
    GPIO_INIT(GPIOA, PIN1, output);
    GPIO_DIGITAL_ANALOG(GPIOA,PIN0|PIN1, digital);
    GPIO_ALTERNATE_EN(GPIOA, PIN0, U0Rx_PA0);
    GPIO_ALTERNATE_EN(GPIOA, PIN1, U0Tx_PA1);

    UART_Clock(UART0_CLK);
    UART_init(UART0, 9600,bits_8 , no_parity,0);
    UART_Enable(UART0);
}
void sendTextToTerminal(uint8_t *data){
    uint8_t i = 0;
    for(i=0;data[i]!='\0';i++)
    {
        UART_SEND_bool(UART0, data[i]);
    }
}

void sendDataToTerminal(uint8_t *data,uint32_t size){
    uint32_t i = 0;
    for(i=0;i<size;i++)
    {
        UART_SEND_bool(UART0, data[i]);
    }
}

uint8_t recieveDataFromTerminal(void){
    uint8_t data  = 0;
    data = UART_RECIEVE_bool(UART0);
    return data;
}

uint8_t writeToTermianlWithFeedBack(uint8_t arr[],uint8_t end)
{
    uint8_t i = 0;
    while(1)
    {
        arr[i] = UART_RECIEVE_bool(UART0);
        UART_SEND_bool(UART0, arr[i]);

        if(arr[i] == end)
        {
            break;
        }
        i++;
    }
    return i;
}
