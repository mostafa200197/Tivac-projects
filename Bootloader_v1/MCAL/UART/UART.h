/*
 * UART.h
 *
 *  Created on: Nov 20, 2023
 *      Author: Mostafa Gamal
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include "MCAL/register_map.h"
#include "stdint.h"

typedef enum{
    UART0_CLK, UART1_CLK, UART2_CLK, UART3_CLK, UART4_CLK, UART5_CLK, UART6_CLK, UART7_CLK
}Uart_number_ClkEn;

typedef enum{
    bits_5 = 0x0, bits_6 = 0x1, bits_7 = 0x2, bits_8 = 0x3
}uart_data_len;
typedef enum{
    no_parity = 0, parity_0 = (1<<1)|(1<<2)|(1<<7), parity_1 = (1<<1)|(1<<7)
}parity_state;

void UART_Clock(Uart_number_ClkEn UartN);
void UART_init(UART_RegDef_t *UART,uint32_t Baud_rate,uart_data_len data_len,parity_state parity,uint8_t FIFO_EN);
void UART_Enable(UART_RegDef_t *UART);
void UART_SEND_bool(UART_RegDef_t *UART,uint8_t data);
uint8_t UART_RECIEVE_bool(UART_RegDef_t *UART);


#endif /* MCAL_UART_UART_H_ */
