/*
 * Bootloader.c
 *
 *  Created on: Jan 5, 2024
 *      Author: Mostafa Gamal
 */


/*space to hold new image*/
#include "Bootloader.h"
#include "stdint.h"

uint8_t HexImage[1500];

/*CRC computation*/
uint16_t crc16(uint8_t volatile *data, uint32_t length) {
    uint16_t crc = 0xFFFF;
    uint32_t i = 0,j=0;
    for (i = 0; i < length; ++i) {
        crc ^= (uint16_t)data[i];
        for (j = 0; j < 8; ++j) {
            if (crc & 0x0001) {
                crc >>= 1;
                crc ^= 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}
/*convert number to array*/
void NumToArray(uint8_t volatile*arr,uint32_t num)
{
    uint8_t i = 0;
    while((num)!= 0)
    {
        arr[i] = num%10;
        i++;
        num = num/10;
    }
}
/*concatenate array into a single number*/
uint32_t con(uint8_t volatile *arr,uint8_t num)
{
    uint32_t result = 0;
    uint32_t muli = 1;
    uint8_t i = 0;
    for(i = 0;i<num;i++)
    {
        result += arr[i] * muli;
        muli*=10;
    }
    return result;
}
void BootMain(void)
{
    TerminalInit();
    uint8_t size_Arr[4] = {0};
    uint16_t CRC=0,size=0;
    uint8_t CRCarr[5];

    /*Receive size*/
    recieveDataFromTermianl(size_Arr, 4);

    /*turn size array to 1 variable*/
    size = con(size_Arr, 4);

    /*send acknowledge of received size*/
    UART_SEND_bool(UART0, 'A');

    /*Receive image hex*/
    recieveDataFromTermianl(HexImage, size);



    /*Resend the code image for verification*/
    sendDataToTerminal(HexImage, size);

    /*compute CRC*/
    CRC = crc16(HexImage, size);
    /*convert to array*/
    NumToArray(CRCarr, CRC);
    /*send the CRC array*/
    sendDataToTerminal(CRCarr,5);


    while(1)
    {

    }

}
