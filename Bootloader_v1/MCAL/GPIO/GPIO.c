/*
 * GPIO.c
 *
 *  Created on: Sep 28, 2023
 *      Author: Mostafa Gamal
 */


#include <MCAL/GPIO/GPIO.h>

#include "tm4c123.h"
uint32_t x;
/*************************************************************************************/
/* function to initialize the GPIO direction, unlocking and committing the specified pins*/
/*************************************************************************************/
void GPIO_CLK_EN(uint32_t gpio)
{
    SYSCTL->RCGCGPIO|=gpio;
}


void GPIO_INIT(gpio_reg_mape *GPIO,uint32_t PINS,uint32_t dir)
{

    GPIO->GPIOLOCK=0x4C4F434BUL; //unlock GPIO
    GPIO->GPIOCR|=PINS; //Committing pins


    if(dir==input)
    {
        GPIO->GPIODIR&=(~PINS);
    }
    else if(dir==output)
    {
        GPIO->GPIODIR|=PINS;
    }

}

/*************************************************************************************/
/* function for digital / analog pins selection*/
/*************************************************************************************/
void GPIO_DIGITAL_ANALOG(gpio_reg_mape *GPIO,uint32_t PINS,uint32_t OUT)
{
    if(OUT==digital)
    {
        GPIO->GPIODEN|=PINS;
    }
    else if(OUT==analog)
    {
        GPIO->GPIODEN&=(~PINS);
    }

}

/*************************************************************************************/
/* function for enabling pullup resisotr mode for pins*/
/*************************************************************************************/
void GPIO_PULLUP(gpio_reg_mape *GPIO,uint32_t PINS)
{
    GPIO->GPIOPUR|=PINS;
}

void GPIO_WRITE(gpio_reg_mape *GPIO,uint32_t PINS,uint8_t value)
{
    if(value==high)
    {
        GPIO->GPIODATA[PINS]|=(uint32_t)PINS;
    }
    else if(value==low)
    {
        GPIO->GPIODATA[PINS]&=(~(uint32_t)PINS);
    }
}
void GPIO_TOGGLE(gpio_reg_mape *GPIO,uint32_t PINS)
{
    GPIO->GPIODATA[PINS] ^= (uint32_t)PINS;

}
uint8_t GPIO_READ(gpio_reg_mape *GPIO)
{
    uint8_t data = GPIO->GPIODATA[255];
    return (uint8_t)data;
}

void GPIO_ALTERNATE_EN(gpio_reg_mape *GPIO,uint32_t PINS,uint32_t alternat_mode)
{
    GPIO->GPIOAFSEL |= PINS;

    switch(PINS)
    {
    case PIN0:
        GPIO->GPIOPCTL |= (alternat_mode << 0);
        break;
    case PIN1:
        GPIO->GPIOPCTL |= (alternat_mode << 4);
        break;
    case PIN2:
        GPIO->GPIOPCTL |= (alternat_mode << 8);
        break;
    case PIN3:
        GPIO->GPIOPCTL |= (alternat_mode << 12);
        break;
    case PIN4:
        GPIO->GPIOPCTL |= (alternat_mode << 16);
        break;
    case PIN5:
        GPIO->GPIOPCTL |= (alternat_mode << 20);
        break;
    case PIN6:
        GPIO->GPIOPCTL |= (alternat_mode << 24);
        break;
    case PIN7:
        GPIO->GPIOPCTL |= (alternat_mode << 28);
        break;
    default:
        break;
    }
}

void GPIO_INTERRUPT_ENABLE(gpio_reg_mape *GPIO,uint32_t PINS,uint32_t state,uint32_t edge,uint32_t level)
{
    GPIO->GPIOIM&=(~PINS); //clear interrupt mask

    if(state==levels)
    {
        GPIO->GPIOIS|=PINS; //configure interrupt sense for level trigger
    }
    else if(state==edges)
    {
        GPIO->GPIOIS&=(~PINS);//configure interrupt sense for edge trigger
        if(edge==both_levels)
        {
            GPIO->GPIOIBE|=PINS; //configure interrupt for both edges
        }
    }

    if(level==high)
    {
        GPIO->GPIOIEV|=PINS;   //high level or rising edge
    }
    else if(level==low)
    {
        GPIO->GPIOIEV&=(~PINS); //low level or falling edge
    }

    GPIO->GPIOICR|=PINS; //clear raw interrupt by setting this bit
    GPIO->GPIOIM|=PINS; //enable interrupt mask
}
