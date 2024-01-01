/*
 * uart_blinker.c
 *
 *  Created on: Nov 22, 2023
 *      Author: DELL G5
 */

#include "applecation/uart_blinker/uart_blinker.h"
uint8_t IsSimilar(uint8_t arr1[],uint8_t size,uint8_t arr2[])
{
    uint8_t i = 0;
    uint8_t result = 1;
    for(i = 0; i<size ;i++)
    {
        if(arr1[i] != arr2[i]){
            result = 0;
        }
    }
    return result;
}
void blinker(uint8_t arr[],uint8_t size)
{
    LEDS_INIT();
    if(IsSimilar(arr,size,"red"))
    {
        LEDS_OFF(WHITE_LED);
        LEDS_ON(RED_LED);
    }
    else if (IsSimilar(arr,size,"blue")) {
        LEDS_OFF(WHITE_LED);
        LEDS_ON(BLUE_LED);
    }
    else if (IsSimilar(arr,size,"green")) {
        LEDS_OFF(WHITE_LED);
        LEDS_ON(GREEN_LED);
    }
    else if (IsSimilar(arr,size,"white")) {
        LEDS_OFF(WHITE_LED);
        LEDS_ON(WHITE_LED);
    }
    else if (IsSimilar(arr,size,"purple")) {
        LEDS_OFF(WHITE_LED);
        LEDS_ON(PURPLE_LED);
    }
    else if (IsSimilar(arr,size,"white")) {
        LEDS_OFF(WHITE_LED);
        LEDS_ON(WHITE_LED);
    }
    else if (IsSimilar(arr,size,"cyan")) {
        LEDS_OFF(WHITE_LED);
        LEDS_ON(CYAN_LED);
    }
}

void blinker_main(void)
{
    TerminalInit();
    uint8_t arr[50] = {0};
    //uint8_t terminator = '\r';
    uint8_t *nextline = "\r\n";
    uint8_t i = 0;

    while(1)
    {
        i = writeToTermianlWithFeedBack(arr, '\r');
        sendDataToTerminal(arr, i);
        sendDataToTerminal(nextline, 1);
        blinker(arr, i);
    }
}
