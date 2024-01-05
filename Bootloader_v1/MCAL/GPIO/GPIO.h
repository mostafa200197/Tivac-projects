/*
 * GPIO.h
 *
 *  Created on: Sep 28, 2023
 *      Author: Mostafa Gamal
 */

#ifndef MCAL_GPIO_GPIO_H_
#define MCAL_GPIO_GPIO_H_

#include <MCAL/register_map.h>
#include "stdint.h"

#define PIN0 0X01U
#define PIN1 0X02U
#define PIN2 0X04U
#define PIN3 0X08U
#define PIN4 0X10U
#define PIN5 0X20U
#define PIN6 0X40U
#define PIN7 0X80U
#define ALL_PINS 0XFFU

#define GPIOA_CLK 0x01
#define GPIOB_CLK 0x02
#define GPIOC_CLK 0x04
#define GPIOD_CLK 0x08
#define GPIOE_CLK 0x10
#define GPIOF_CLK 0x20

#define input 0
#define output 1

#define digital 1
#define analog 0

#define high 1
#define low 0


#define edges 0
#define levels 1
#define both_levels 0

#define U0Rx_PA0 1
#define U0Tx_PA1 1
#define U1Rx_PB0 1
#define U1Tx_PB1 1
#define U1Rx_PC4 2
#define U1Tx_PC5 2
#define U2Rx_PD6 1
#define U2Tx_PD7 1

void GPIO_INIT(gpio_reg_mape *GPIO,uint32_t PINS,uint32_t dir);
void GPIO_DIGITAL_ANALOG(gpio_reg_mape *GPIO,uint32_t PINS,uint32_t OUT);
void GPIO_PULLUP(gpio_reg_mape *GPIO,uint32_t PINS);
void GPIO_CLK_EN(uint32_t gpio);
void GPIO_TOGGLE(gpio_reg_mape *GPIO,uint32_t PINS);
void GPIO_WRITE(gpio_reg_mape *GPIO,uint32_t PINS,uint8_t value);
uint8_t GPIO_READ(gpio_reg_mape *GPIO);
void GPIO_ALTERNATE_EN(gpio_reg_mape *GPIO,uint32_t PINS,uint32_t alternat_mode);
void GPIO_INTERRUPT_ENABLE(gpio_reg_mape *GPIO,uint32_t PINS,uint32_t state,uint32_t edge,uint32_t level);

#endif /* MCAL_GPIO_GPIO_H_ */
