/*
 * UART.c
 *
 *  Created on: Nov 20, 2023
 *      Author: DELL G5
 */

#include "MCAL/UART/UART.h"
void UART_Clock(Uart_number_ClkEn UartN)
{
    SYSCTL->RCGCUART |= (1<<UartN); //enable Uart system clock
}

void UART_init(UART_RegDef_t *UART,uint32_t Baud_rate,uart_data_len data_len,parity_state parity,uint8_t FIFO_EN)
{
    float BRD = (float)((16000000.0)/(16 * Baud_rate));
    int DIVINT = (int)BRD;
    float fraction = (BRD - DIVINT);
    int DIVFRAC = (fraction*64 + (0.5));

    UART->CTL &= (~(1<<0)); //disable uart
    UART->IBRD |= DIVINT; //integer divisor
    UART->FBRD |= DIVFRAC; //fraction divisor

    UART->LCRH = 0x00; //clear the control word
    UART->LCRH|= (data_len<<5); //data word length

    UART->LCRH |= (FIFO_EN<<4); //Enable FIFOS

    if(parity == no_parity)
    {
        UART->LCRH &= (~(1<<7)); //clear parity bit
    }
    else{
        UART->LCRH |= parity; //chose either parity check 0 or 1
    }


    UART->CC = 0X00U; //configure UART as system clock
}
void UART_Enable(UART_RegDef_t *UART)
{
    UART->CTL |=(1<<0); //enable UART
}

void UART_SEND_bool(UART_RegDef_t *UART,uint8_t data)
{
    while(((UART->FR)&(1<<5))||((UART->FR)&(1<<3)))
    {
        // Wait until transmit FIFO is not full and transmitter is not busy
        // You can add additional code here if needed
    }
    UART->DR = (uint8_t)data; //push data into transmit FIFO
}
uint8_t UART_RECIEVE_bool(UART_RegDef_t *UART)
{
    while(((UART->FR)&(1<<6))==0); //wait while UART can receive data
    uint8_t data = (uint8_t)(UART->DR);


    return data;
}

