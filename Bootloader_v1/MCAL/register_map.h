/*
 * register_map.h
 *
 *  Created on: Sep 28, 2023
 *      Author: Mostafa Gamal
 */

#ifndef MCAL_REGISTER_MAP_H_
#define MCAL_REGISTER_MAP_H_

#include "stdint.h"


/******************************************** NVIC Base Definition ***************************************************/

#define NVIC_BASE_ADDRESS               0xE000E000UL

/******************************************** NVIC Register Definition ***********************************************/

typedef struct
{
    volatile uint32_t Reserved[2]; /* Reserved 1 */
    volatile uint32_t ACTLR; /* Auxiliary Control  */
    volatile uint32_t Reserved2; /* Reserved 2 */
    /* SysTick Registers */
    volatile uint32_t STCTRL; /* SysTick Control and Status Register */
    volatile uint32_t STRELOAD; /* SysTick Reload Value Register */
    volatile uint32_t STCURRENT; /* SysTick Current Value Register */
    volatile uint32_t Reserved3[57]; /* Reserved 3 */
    /* NVIC Registers */
    volatile uint32_t EN0; /* Interrupt 0-31 Set Enable */
    volatile uint32_t EN1; /* Interrupt 32-63 Set Enable */
    volatile uint32_t EN2; /* Interrupt 64-95 Set Enable */
    volatile uint32_t EN3; /* Interrupt 96-127 Set Enable */
    volatile uint32_t EN4; /* Interrupt 128-138 Set Enable */
    volatile uint32_t Reserved4[27]; /* Reserved 4 */
    volatile uint32_t DIS0; /* Interrupt 0-31 Clear Enable */
    volatile uint32_t DIS1; /* Interrupt 32-63 Clear Enable */
    volatile uint32_t DIS2; /* Interrupt 64-95 Clear Enable */
    volatile uint32_t DIS3; /* Interrupt 96-127 Clear Enable */
    volatile uint32_t DIS4; /* Interrupt 128-138 Clear Enable */
    volatile uint32_t Reserved5[27]; /* Reserved 5 */
    volatile uint32_t PEND0; /* Interrupt 0-31 Set Pending */
    volatile uint32_t PEND1; /* Interrupt 32-63 Set Pending */
    volatile uint32_t PEND2; /* Interrupt 64-95 Set Pending */
    volatile uint32_t PEND3; /* Interrupt 96-127 Set Pending */
    volatile uint32_t PEND4; /* Interrupt 128-138 Set Pending */
    volatile uint32_t Reserved6[27]; /* Reserved 6 */
    volatile uint32_t UNPEND0; /* Interrupt 0-31 Clear Pending */
    volatile uint32_t UNPEND1; /* Interrupt 32-63 Clear Pending */
    volatile uint32_t UNPEND2; /* Interrupt 64-95 Clear Pending */
    volatile uint32_t UNPEND3; /* Interrupt 96-127 Clear Pending */
    volatile uint32_t UNPEND4; /* Interrupt 128-138 Clear Pending */
    volatile uint32_t Reserved7[27]; /* Reserved 7 */
    volatile uint32_t ACTIVE0; /* Interrupt 0-31 Active Bit */
    volatile uint32_t ACTIVE1; /* Interrupt 32-63 Active Bit */
    volatile uint32_t ACTIVE2; /* Interrupt 64-95 Active Bit */
    volatile uint32_t ACTIVE3; /* Interrupt 96-127 Active Bit */
    volatile uint32_t ACTIVE4; /* Interrupt 128-138 Active Bit */
    volatile uint32_t Reserved8[59]; /* Reserved 8 */
    volatile uint32_t PRI0; /* Interrupt 0-3 Priority */
    volatile uint32_t PRI1; /* Interrupt 4-7 Priority */
    volatile uint32_t PRI2; /* Interrupt 8-11 Priority */
    volatile uint32_t PRI3; /* Interrupt 12-15 Priority */
    volatile uint32_t PRI4; /* Interrupt 16-19 Priority */
    volatile uint32_t PRI5; /* Interrupt 20-23 Priority */
    volatile uint32_t PRI6; /* Interrupt 24-27 Priority */
    volatile uint32_t PRI7; /* Interrupt 28-31 Priority */
    volatile uint32_t PRI8; /* Interrupt 32-35 Priority */
    volatile uint32_t PRI9; /* Interrupt 36-39 Priority */
    volatile uint32_t PRI10; /* Interrupt 40-43 Priority */
    volatile uint32_t PRI11; /* Interrupt 44-47 Priority */
    volatile uint32_t PRI12; /* Interrupt 48-51 Priority */
    volatile uint32_t PRI13; /* Interrupt 52-55 Priority */
    volatile uint32_t PRI14; /* Interrupt 56-59 Priority */
    volatile uint32_t PRI15; /* Interrupt 60-63 Priority */
    volatile uint32_t PRI16; /* Interrupt 64-67 Priority */
    volatile uint32_t PRI17; /* Interrupt 68-71 Priority */
    volatile uint32_t PRI18; /* Interrupt 72-75 Priority */
    volatile uint32_t PRI19; /* Interrupt 76-79 Priority */
    volatile uint32_t PRI20; /* Interrupt 80-83 Priority */
    volatile uint32_t PRI21; /* Interrupt 84-87 Priority */
    volatile uint32_t PRI22; /* Interrupt 88-91 Priority */
    volatile uint32_t PRI23; /* Interrupt 92-95 Priority */
    volatile uint32_t PRI24; /* Interrupt 96-99 Priority */
    volatile uint32_t PRI25; /* Interrupt 100-103 Priority */
    volatile uint32_t PRI26; /* Interrupt 104-107 Priority */
    volatile uint32_t PRI27; /* Interrupt 108-111 Priority */
    volatile uint32_t PRI28; /* Interrupt 112-115 Priority */
    volatile uint32_t PRI29; /* Interrupt 116-119 Priority */
    volatile uint32_t PRI30; /* Interrupt 120-123 Priority */
    volatile uint32_t PRI31; /* Interrupt 124-127 Priority */
    volatile uint32_t PRI32; /* Interrupt 128-131 Priority */
    volatile uint32_t PRI33; /* Interrupt 132-135 Priority */
    volatile uint32_t PRI34; /* Interrupt 136-138 Priority */
    volatile uint32_t Reserved9[541]; /* Reserved 9 */
    volatile uint32_t CPUID; /* CPU ID Base */
    volatile uint32_t INTCTRL; /* Interrupt Control and State */
    volatile uint32_t VTABLE; /* Vector Table Offset */
    volatile uint32_t APINT; /* Application Interrupt and Reset Control */
    volatile uint32_t SYSCTRL; /* System Control */
    volatile uint32_t CFGCTRL; /* Configuration and Control */
    volatile uint32_t SYSPRI1; /* System Handler Priority 1 */
    volatile uint32_t SYSPRI2; /* System Handler Priority 2 */
    volatile uint32_t SYSPRI3; /* System Handler Priority 3 */
    volatile uint32_t SYSHNDCTRL; /* System Handler Control and State */
    volatile uint32_t FAULTSTAT; /* Configurable Fault Status  */
    volatile uint32_t HFAULTSTAT; /* Hard Fault Status  */
    volatile uint32_t Reserved10; /* Reserved 10 */
    volatile uint32_t MMADDR; /* Memory Management Fault Address */
    volatile uint32_t FAULTADDR; /* Bus Fault Address */
    volatile uint32_t Reserved11[19]; /* Reserved 11 */
    volatile uint32_t CPAC; /* Coprocessor Access Control */
    volatile uint32_t Reserved12; /* Reserved 12 */
    volatile uint32_t MPUTYPE; /* MPU Type */
    volatile uint32_t MPUCTRL; /* MPU Control */
    volatile uint32_t MPUNUMBER; /* MPU Region Number */
    volatile uint32_t MPUBASE; /* MPU Region Base Address */
    volatile uint32_t MPUATTR; /* MPU Region Attribute and Size */
    volatile uint32_t MPUBASE1; /* MPU Region Base Address Alias 1 */
    volatile uint32_t MPUATTR1; /* MPU Region Attribute and Size Alias 1 */
    volatile uint32_t MPUBASE2; /* MPU Region Base Address Alias 2 */
    volatile uint32_t MPUATTR2; /* MPU Region Attribute and Size Alias 2 */
    volatile uint32_t MPUBASE3; /* MPU Region Base Address Alias 3 */
    volatile uint32_t MPUATTR3; /* MPU Region Attribute and Size Alias 3 */
    volatile uint32_t Reserved13[81]; /* Reserved 13 */
    volatile uint32_t SWTRIG; /* Software Trigger Interrupt */
    volatile uint32_t Reserved14[12]; /* Reserved 14 */
    volatile uint32_t FPCC; /* Floating-Point Context Control */
    volatile uint32_t FPCA; /* Floating-Point Context Address */
    volatile uint32_t FPDSC; /* Floating-Point Default Status Control */
} NVIC_RegDef_t;

#define NVIC                            ((NVIC_RegDef_t*) NVIC_BASE_ADDRESS)
//system contorl
#define system_control_Base  0x400FE000

typedef struct
{
    volatile uint32_t DID0; /* Device Identification 0 */
    volatile uint32_t DID1; /* Device Identification 1 */
    volatile uint32_t Reserved[10]; /* Reserved 1 */
    volatile uint32_t PBORCTL; /* Brown-Out Reset Control */
    volatile uint32_t Reserved2[7]; /* Reserved 2 */
    volatile uint32_t RIS; /* Raw Interrupt Status */
    volatile uint32_t IMC; /* Interrupt Mask Control  */
    volatile uint32_t MISC; /* Masked Interrupt Status and Clear */
    volatile uint32_t RESC; /* Reset Cause */
    volatile uint32_t RCC; /* Run-Mode Clock Configuration */
    volatile uint32_t Reserved3[2]; /* Reserved 3 */
    volatile uint32_t GPIOHCTL; /* GPIO High-Performance Bus Control */
    volatile uint32_t RCC2; /* Run-Mode Clock Configuration  */
    volatile uint32_t Reserved4[2]; /* Reserved 4 */
    volatile uint32_t MOSCCTL; /* Main Oscillator Control */
    volatile uint32_t Reserved5[49]; /* Reserved 5 */
    volatile uint32_t DSLPCLKCFG; /* Deep Sleep Clock Configuration */
    volatile uint32_t Reserved6; /* Reserved 6 */
    volatile uint32_t SYSPROP; /* System Properties */
    volatile uint32_t PIOSCCAL; /* Precision Internal Oscillator Calibration */
    volatile uint32_t PIOSCSTAT; /* Precision Internal Oscillator Statistics */
    volatile uint32_t Reserved7[2]; /* Reserved 7 */
    volatile uint32_t PLLFREQ0; /* PLL Frequency 0 */
    volatile uint32_t PLLFREQ1; /* PLL Frequency 1 */
    volatile uint32_t PLLSTAT; /* PLL Status */
    volatile uint32_t Reserved8[7]; /* Reserved 8 */
    volatile uint32_t SLPPWRCFG; /* Sleep Power Configuration */
    volatile uint32_t DSLPPWRCFG; /* Deep-Sleep Power Configuration */
    volatile uint32_t Reserved9[9]; /* Reserved 9 */
    volatile uint32_t LDOSPCTL; /* LDO Sleep Power Control */
    volatile uint32_t LDOSPCAL; /* LDO Sleep Power Calibration */
    volatile uint32_t LDODPCTL; /* LDO Deep-Sleep Power Control */
    volatile uint32_t LDODPCAL; /* LDO Deep-Sleep Power Calibration */
    volatile uint32_t Reserved10[2]; /* Reserved 10 */
    volatile uint32_t SDPMST; /* Sleep / Deep-Sleep Power Mode Status */
    volatile uint32_t Reserved11[76]; /* Reserved 11 */
    volatile uint32_t PPWD; /* Watchdog Timer Peripheral Present */
    volatile uint32_t PPTIMER; /* 16/32-Bit General-Purpose Timer Peripheral Present */
    volatile uint32_t PPGPIO; /* General-Purpose Input/Output Peripheral Present */
    volatile uint32_t PPDMA; /* Micro Direct Memory Access Peripheral Present */
    volatile uint32_t Reserved12; /* Reserved 12 */
    volatile uint32_t PPHIB; /* Hibernation Peripheral Present */
    volatile uint32_t PPUART; /* Universal Asynchronous Receiver/Transmitter Peripheral Present */
    volatile uint32_t PPSSI; /* Synchronous Serial Interface Peripheral Present */
    volatile uint32_t PPI2C; /* Inter-Integrated Circuit Peripheral Present */
    volatile uint32_t Reserved13; /* Reserved 13 */
    volatile uint32_t PPUSB; /* Universal Serial Bus Peripheral Present */
    volatile uint32_t Reserved14[2]; /* Reserved 14 */
    volatile uint32_t PPCAN; /* Controller Area Network Peripheral Present */
    volatile uint32_t PPADC; /* Analog-to-Digital Converter Peripheral Present */
    volatile uint32_t PPACMP; /* Analog Comparator Peripheral Present */
    volatile uint32_t PPPWM; /* Pulse Width Modulator Peripheral Present */
    volatile uint32_t PPQEI; /* Quadrature Encoder Interface Peripheral Present */
    volatile uint32_t Reserved15[4]; /* Reserved 15 */
    volatile uint32_t PPEEPROM; /* EEPROM Peripheral Present */
    volatile uint32_t PPWTIMER; /* 32/64-Bit Wide General-Purpose Timer Peripheral Present */
    volatile uint32_t Reserved16[104]; /* Reserved 16 */
    volatile uint32_t SRWD; /* Watchdog Timer Software Reset */
    volatile uint32_t SRTIMER; /* 16/32-Bit General-Purpose Timer Software Reset */
    volatile uint32_t SRGPIO; /* General-Purpose Input/Output Software Reset */
    volatile uint32_t SRDMA; /* Micro Direct Memory Access Software Reset */
    volatile uint32_t Reserved17; /* Reserved 17 */
    volatile uint32_t SRHIB; /* Hibernation Software Reset */
    volatile uint32_t SRUART; /* Universal Asynchronous Receiver/Transmitter Software Reset */
    volatile uint32_t SRSSI; /* Synchronous Serial Interface Software Reset */
    volatile uint32_t SRI2C; /* Inter-Integrated Circuit Software Reset */
    volatile uint32_t Reserved18; /* Reserved 18 */
    volatile uint32_t SRUSB; /* Universal Serial Bus Software Reset */
    volatile uint32_t Reserved19[2]; /* Reserved 19 */
    volatile uint32_t SRCAN; /* Controller Area Network Software Reset */
    volatile uint32_t SRADC; /* Analog-to-Digital Converter Software Reset */
    volatile uint32_t SRACMP; /* Analog Comparator Software Reset */
    volatile uint32_t SRPWM; /* Pulse Width Modulator Software Reset */
    volatile uint32_t SRQEI; /* Quadrature Encoder Interface Software Reset */
    volatile uint32_t Reserved20[4]; /* Reserved 20 */
    volatile uint32_t SREEPROM; /* EEPROM Software Reset */
    volatile uint32_t SRWTIMER; /* 32/64-Bit Wide General-Purpose Timer Software Reset */
    volatile uint32_t Reserved21[40]; /* Reserved 21 */
    volatile uint32_t RCGCWD; /* Watchdog Timer Run Mode Clock Gating Control */
    volatile uint32_t RCGCTIMER; /* 16/32-Bit General-Purpose Timer Run Mode Clock Gating Control */
    volatile uint32_t RCGCGPIO; /* General-Purpose Input/Output Run Mode Clock Gating Control */
    volatile uint32_t RCGCDMA; /* Micro Direct Memory Access Run Mode Clock Gating Control */
    volatile uint32_t Reserved22; /* Reserved 22 */
    volatile uint32_t RCGCHIB; /* Hibernation Run Mode Clock Gating Control */
    volatile uint32_t RCGCUART; /* Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating Control */
    volatile uint32_t RCGCSSI; /* Synchronous Serial Interface Run Mode Clock Gating Control */
    volatile uint32_t RCGCI2C; /* Inter-Integrated Circuit Run Mode Clock Gating Control */
    volatile uint32_t Reserved23; /* Reserved 23 */
    volatile uint32_t RCGCUSB; /* Universal Serial Bus Run Mode Clock Gating Control */
    volatile uint32_t Reserved24[2]; /* Reserved 24 */
    volatile uint32_t RCGCCAN; /* Controller Area Network Run Mode Clock Gating Control */
    volatile uint32_t RCGCADC; /* Analog-to-Digital Converter Run Mode Clock Gating Control */
    volatile uint32_t RCGCACMP; /* Analog Comparator Run Mode Clock Gating Control */
    volatile uint32_t RCGCPWM; /* Pulse Width Modulator Run Mode Clock Gating Control */
    volatile uint32_t RCGCQEI; /* Quadrature Encoder Interface Run Mode Clock Gating Control */
    volatile uint32_t Reserved25[4]; /* Reserved 25 */
    volatile uint32_t RCGCEEPROM; /* EEPROM Run Mode Clock Gating Control */
    volatile uint32_t RCGCWTIMER; /* 32/64-Bit Wide General-Purpose Timer Run Mode Clock Gating Control */
    volatile uint32_t Reserved26[40]; /* Reserved 26 */
    volatile uint32_t SCGCWD; /* Watchdog Timer Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCTIMER; /* 16/32-Bit General-Purpose Timer Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCGPIO; /* General-Purpose Input/Output Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCDMA; /* Micro Direct Memory Access Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved27; /* Reserved 27 */
    volatile uint32_t SCGCHIB; /* Hibernation Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCUART; /* Universal Asynchronous Receiver/Transmitter Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCSSI; /* Synchronous Serial Interface Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCI2C; /* Inter-Integrated Circuit Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved28; /* Reserved 28 */
    volatile uint32_t SCGCUSB; /* Universal Serial Bus Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved29[2]; /* Reserved 29 */
    volatile uint32_t SCGCCAN; /* Controller Area Network Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCADC; /* Analog-to-Digital Converter Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCACMP; /* Analog Comparator Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCPWM; /* Pulse Width Modulator Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCQEI; /* Quadrature Encoder Interface Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved30[4]; /* Reserved 30 */
    volatile uint32_t SCGCEEPROM; /* EEPROM Sleep Mode Clock Gating Control */
    volatile uint32_t SCGCWTIMER; /* 32/64-Bit Wide General-Purpose Timer Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved31[40]; /* Reserved 31 */
    volatile uint32_t DCGCWD; /* Watchdog Timer Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCTIMER; /* 16/32-Bit General-Purpose Timer Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCGPIO; /* General-Purpose Input/Output Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCDMA; /* Micro Direct Memory Access Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved32; /* Reserved 32 */
    volatile uint32_t DCGCHIB; /* Hibernation Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCUART; /* Universal Asynchronous Receiver/Transmitter Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCSSI; /* Synchronous Serial Interface Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCI2C; /* Inter-Integrated Circuit Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved33; /* Reserved 33 */
    volatile uint32_t DCGCUSB; /* Universal Serial Bus Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved34[2]; /* Reserved 34 */
    volatile uint32_t DCGCCAN; /* Controller Area Network Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCADC; /* Analog-to-Digital Converter Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCACMP; /* Analog Comparator Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCPWM; /* Pulse Width Modulator Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCQEI; /* Quadrature Encoder Interface Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved35[4]; /* Reserved 35 */
    volatile uint32_t DCGCEEPROM; /* EEPROM Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t DCGCWTIMER; /* 32/64-Bit Wide General-Purpose Timer Deep-Sleep Mode Clock Gating Control */
    volatile uint32_t Reserved36[104]; /* Reserved 36 */
    volatile uint32_t PRWD; /* Watchdog Timer Peripheral Ready */
    volatile uint32_t PRTIMER; /* 16/32-Bit General-Purpose Timer Peripheral Ready */
    volatile uint32_t PRGPIO; /* General-Purpose Input/Output Peripheral Ready */
    volatile uint32_t PRDMA; /* Micro Direct Memory Access Peripheral Ready */
    volatile uint32_t Reserved37; /* Reserved 37 */
    volatile uint32_t PRHIB; /* Hibernation Peripheral Ready */
    volatile uint32_t PRUART; /* Universal Asynchronous Receiver/Transmitter Peripheral Ready */
    volatile uint32_t PRSSI; /* Synchronous Serial Interface Peripheral Ready */
    volatile uint32_t PRI2C; /* Inter-Integrated Circuit Peripheral Ready */
    volatile uint32_t Reserved38; /* Reserved 38 */
    volatile uint32_t PRUSB; /* Universal Serial Bus Peripheral Ready */
    volatile uint32_t Reserved39[2]; /* Reserved 39 */
    volatile uint32_t PRCAN; /* Controller Area Network Peripheral Ready */
    volatile uint32_t PRADC; /* Analog-to-Digital Converter Peripheral Ready */
    volatile uint32_t PRACMP; /* Analog Comparator Peripheral Ready */
    volatile uint32_t PRPWM; /* Pulse Width Modulator Peripheral Ready */
    volatile uint32_t PRQEI; /* Quadrature Encoder Interface Peripheral Ready */
    volatile uint32_t Reserved40[4]; /* Reserved 40 */
    volatile uint32_t PREEPROM; /* EEPROM Peripheral Ready */
    volatile uint32_t PRWTIMER; /* 32/64-Bit Wide General-Purpose Timer Peripheral Ready */
} SystemCtl_reg_mape;

#define SYSCTL ((SystemCtl_reg_mape*)system_control_Base)

/******************************************** GPIO Base Definition ***************************************************/
#define GPIOA_BASE 0x40004000UL
#define GPIOB_BASE 0x40005000UL
#define GPIOC_BASE 0x40006000UL
#define GPIOD_BASE 0x40007000UL
#define GPIOE_BASE 0x40024000UL
#define GPIOF_BASE 0x40025000UL
/******************************************** STRUCT TO POINT AT BASE ADDRESES GPIO ***************************************************/

typedef struct{
    volatile uint32_t GPIODATA[256]; //GPIO data register
    volatile uint32_t GPIODIR; //GPIO direction register
    volatile uint32_t GPIOIS; //GPIO Interrupt Sense
    volatile uint32_t GPIOIBE; //GPIO interrupt both edges
    volatile uint32_t GPIOIEV; //GPIO Interrupt Event
    volatile uint32_t GPIOIM; //GPIO interrupt mask
    volatile uint32_t GPIORIS; //GPIO raw interrupt status
    volatile uint32_t GPIOMIS; //GPIO masked interrupt status states
    volatile uint32_t GPIOICR; //GPIO interrupt clear
    volatile uint32_t GPIOAFSEL; //gpio alternate function setting
    volatile uint32_t rserved[55]; /* reserved 1  still under investigation*/
    volatile uint32_t GPIODR2R;  //GPIO 2-mA Drive Select
    volatile uint32_t GPIODR4R; //GPIO 4-mA Drive Select
    volatile uint32_t GPIODR8R; //GPIO 8-mA Drive Select
    volatile uint32_t GPIOODR; //GPIO Open Drain Select
    volatile uint32_t GPIOPUR; //GPIO Open Drain Select
    volatile uint32_t GPIOPDR; //GPIOPDR
    volatile uint32_t GPIOSLR; //GPIO Slew Rate Control Select
    volatile uint32_t GPIODEN; //GPIO Digital Enable
    volatile uint32_t GPIOLOCK; //GPIO LOCK
    volatile uint32_t GPIOCR; //GPIO commit
    volatile uint32_t GPIOAMSEL; //GPIO analog mode select
    volatile uint32_t GPIOPCTL ; //GPIO Port Control
    volatile uint32_t GPIOADCCTL;//GPIO ADC Control
    volatile uint32_t GPIODMACTL;//GPIO DMA Control
    volatile uint32_t reserved2[678]; /* reserved 2  still under investigation ###*/
    volatile uint32_t GPIOPeriphID4; //GPIO Peripheral Identification 4
    volatile uint32_t GPIOPeriphID5 ;//GPIO Peripheral Identification 5
    volatile uint32_t GPIOPeriphID6 ;//GPIO Peripheral Identification 6
    volatile uint32_t GPIOPeriphID7 ;//GPIO Peripheral Identification 7
    volatile uint32_t GPIOPeriphID0 ;//GPIO Peripheral Identification 0
    volatile uint32_t GPIOPeriphID1 ;//GPIO Peripheral Identification 1
    volatile uint32_t GPIOPeriphID2 ;//GPIO Peripheral Identification 2
    volatile uint32_t GPIOPeriphID3 ;//GPIO Peripheral Identification 3
} gpio_reg_mape;
/******************************************** pointer to structs of type gpio_reg_mape pointing at the base addreses***************************************************/
#define GPIOA ((gpio_reg_mape*)GPIOA_BASE)
#define GPIOB ((gpio_reg_mape*)GPIOB_BASE)
#define GPIOC ((gpio_reg_mape*)GPIOC_BASE)
#define GPIOD ((gpio_reg_mape*)GPIOD_BASE)
#define GPIOE ((gpio_reg_mape*)GPIOE_BASE)
#define GPIOF ((gpio_reg_mape*)GPIOF_BASE)
/**********************************************************************************************************************
 *  PWM Base Definition
 *********************************************************************************************************************/
#define PWM0_BASE_ADDRESS               0x40028000UL
#define PWM1_BASE_ADDRESS               0x40029000UL
/**********************************************************************************************************************
 *  PWM Register Definition
 *********************************************************************************************************************/
typedef struct
{
    volatile uint32_t CTL; /* PWM Master Control */
    volatile uint32_t SYNC; /* PWM Time Base Sync */
    volatile uint32_t ENABLE; /* PWM Output Enable */
    volatile uint32_t INVERT; /* PWM Output Inversion */
    volatile uint32_t FAULT; /* PWM Output Fault */
    volatile uint32_t INTEN; /* PWM Interrupt Enable */
    volatile uint32_t RIS; /* PWM Raw Interrupt Status */
    volatile uint32_t ISC; /* PWM Interrupt Status and Clear */
    volatile uint32_t STATUS; /* PWM Status */
    volatile uint32_t FAULTVAL; /* PWM Fault Condition Value */
    volatile uint32_t ENUPD; /* PWM Enable Update */
    volatile uint32_t RESERVED[5]; /* RESERVED 1 */
    volatile uint32_t _0_CTL; /* PWM0 Control */
    volatile uint32_t _0_INTEN; /* PWM0 Interrupt and Trigger Enable */
    volatile uint32_t _0_RIS; /* PWM0 Raw Interrupt Status */
    volatile uint32_t _0_ISC; /* PWM0 Interrupt Status and Clear */
    volatile uint32_t _0_LOAD; /* PWM0 Load */
    volatile uint32_t _0_COUNT; /* PWM0 Counter */
    volatile uint32_t _0_CMPA; /* PWM0 Compare A */
    volatile uint32_t _0_CMPB; /* PWM0 Compare B */
    volatile uint32_t _0_GENA; /* PWM0 Generator A Control */
    volatile uint32_t _0_GENB; /* PWM0 Generator B Control */
    volatile uint32_t _0_DBCTL; /* PWM0 Dead-Band Control */
    volatile uint32_t _0_DBRISE; /* PWM0 Dead-Band Rising-Edge Delay */
    volatile uint32_t _0_DBFALL; /* PWM0 Dead-Band Falling-Edge-Delay */
    volatile uint32_t _0_FLTSRC0; /* PWM0 Fault Source 0 */
    volatile uint32_t _0_FLTSRC1; /* PWM0 Fault Source 1 */
    volatile uint32_t _0_MINFLTPER; /* PWM0 Minimum Fault Period */
    volatile uint32_t _1_CTL; /* PWM1 Control */
    volatile uint32_t _1_INTEN; /* PWM1 Interrupt and Trigger Enable */
    volatile uint32_t _1_RIS; /* PWM1 Raw Interrupt Status */
    volatile uint32_t _1_ISC; /* PWM1 Interrupt Status and Clear */
    volatile uint32_t _1_LOAD; /* PWM1 Load */
    volatile uint32_t _1_COUNT; /* PWM1 Counter */
    volatile uint32_t _1_CMPA; /* PWM1 Compare A */
    volatile uint32_t _1_CMPB; /* PWM1 Compare B */
    volatile uint32_t _1_GENA; /* PWM1 Generator A Control */
    volatile uint32_t _1_GENB; /* PWM1 Generator B Control */
    volatile uint32_t _1_DBCTL; /* PWM1 Dead-Band Control */
    volatile uint32_t _1_DBRISE; /* PWM1 Dead-Band Rising-Edge Delay */
    volatile uint32_t _1_DBFALL; /* PWM1 Dead-Band Falling-Edge-Delay */
    volatile uint32_t _1_FLTSRC0; /* PWM1 Fault Source 0 */
    volatile uint32_t _1_FLTSRC1; /* PWM1 Fault Source 1 */
    volatile uint32_t _1_MINFLTPER; /* PWM1 Minimum Fault Period */
    volatile uint32_t _2_CTL; /* PWM2 Control */
    volatile uint32_t _2_INTEN; /* PWM2 Interrupt and Trigger Enable */
    volatile uint32_t _2_RIS; /* PWM2 Raw Interrupt Status */
    volatile uint32_t _2_ISC; /* PWM2 Interrupt Status and Clear */
    volatile uint32_t _2_LOAD; /* PWM2 Load */
    volatile uint32_t _2_COUNT; /* PWM2 Counter */
    volatile uint32_t _2_CMPA; /* PWM2 Compare A */
    volatile uint32_t _2_CMPB; /* PWM2 Compare B */
    volatile uint32_t _2_GENA; /* PWM2 Generator A Control */
    volatile uint32_t _2_GENB; /* PWM2 Generator B Control */
    volatile uint32_t _2_DBCTL; /* PWM2 Dead-Band Control */
    volatile uint32_t _2_DBRISE; /* PWM2 Dead-Band Rising-Edge Delay */
    volatile uint32_t _2_DBFALL; /* PWM2 Dead-Band Falling-Edge-Delay */
    volatile uint32_t _2_FLTSRC0; /* PWM2 Fault Source 0 */
    volatile uint32_t _2_FLTSRC1; /* PWM2 Fault Source 1 */
    volatile uint32_t _2_MINFLTPER; /* PWM2 Minimum Fault Period */
    volatile uint32_t _3_CTL; /* PWM3 Control */
    volatile uint32_t _3_INTEN; /* PWM3 Interrupt and Trigger Enable */
    volatile uint32_t _3_RIS; /* PWM3 Raw Interrupt Status */
    volatile uint32_t _3_ISC; /* PWM3 Interrupt Status and Clear */
    volatile uint32_t _3_LOAD; /* PWM3 Load */
    volatile uint32_t _3_COUNT; /* PWM3 Counter */
    volatile uint32_t _3_CMPA; /* PWM3 Compare A */
    volatile uint32_t _3_CMPB; /* PWM3 Compare B */
    volatile uint32_t _3_GENA; /* PWM3 Generator A Control */
    volatile uint32_t _3_GENB; /* PWM3 Generator B Control */
    volatile uint32_t _3_DBCTL; /* PWM3 Dead-Band Control */
    volatile uint32_t _3_DBRISE; /* PWM3 Dead-Band Rising-Edge Delay */
    volatile uint32_t _3_DBFALL; /* PWM3 Dead-Band Falling-Edge-Delay */
    volatile uint32_t _3_FLTSRC0; /* PWM3 Fault Source 0 */
    volatile uint32_t _3_FLTSRC1; /* PWM3 Fault Source 1 */
    volatile uint32_t _3_MINFLTPER; /* PWM3 Minimum Fault Period */
    volatile uint32_t RESERVED2[432]; /* RESERVED 2 */
    volatile uint32_t _0_FLTSEN; /* PWM0 Fault Pin Logic Sense */
    volatile uint32_t _0_FLTSTAT0; /* PWM0 Fault Status 0 */
    volatile uint32_t _0_FLTSTAT1; /* PWM0 Fault Status 1 */
    volatile uint32_t RESERVED3[29]; /* RESERVED 3 */
    volatile uint32_t _1_FLTSEN; /* PWM1 Fault Pin Logic Sense */
    volatile uint32_t _1_FLTSTAT0; /* PWM1 Fault Status 0 */
    volatile uint32_t _1_FLTSTAT1; /* PWM1 Fault Status 1 */
    volatile uint32_t RESERVED4[30]; /* RESERVED 4 */
    volatile uint32_t _2_FLTSTAT0; /* PWM2 Fault Status 0 */
    volatile uint32_t _2_FLTSTAT1; /* PWM2 Fault Status 1 */
    volatile uint32_t RESERVED5[30];
    volatile uint32_t _3_FLTSTAT0; /* PWM3 Fault Status 0 */
    volatile uint32_t _3_FLTSTAT1; /* PWM3 Fault Status 1 */
    volatile uint32_t RESERVED6[397]; /* RESERVED 6 */
    volatile uint32_t PP; /* PWM Peripheral Properties */
} PWM_RegDef_t;

#define PWM0                            ((PWM_RegDef_t*) PWM0_BASE_ADDRESS)
#define PWM1                            ((PWM_RegDef_t*) PWM1_BASE_ADDRESS)
/**********************************************************************************************************************
 *  uDMA Base Definition
 *********************************************************************************************************************/
#define uDMA_BASE_ADDRESS               0x400FF000
/**********************************************************************************************************************
 *  uDMA Registers Definition
 *********************************************************************************************************************/
typedef struct
{
    volatile uint32_t STAT; /* DMA Status */
    volatile uint32_t CFG; /* DMA Configuration */
    volatile uint32_t CTLBASE; /* DMA Channel Control Base Pointer */
    volatile uint32_t ALTBASE; /* DMA Alternate Channel Control Base Pointer */
    volatile uint32_t WAITSTAT; /* DMA Channel Wait-on-Request Status */
    volatile uint32_t SWREQ; /* DMA Channel Software Request */
    volatile uint32_t USEBURSTSET; /* DMA Channel Useburst Set */
    volatile uint32_t USEBURSTCLR; /* DMA Channel Useburst Clear */
    volatile uint32_t REQMASKSET; /* DMA Channel Request Mask Set */
    volatile uint32_t REQMASKCLR; /* DMA Channel Request Mask Clear */
    volatile uint32_t ENASET; /* DMA Channel Enable Set */
    volatile uint32_t ENACLR; /* DMA Channel Enable Clear */
    volatile uint32_t ALTSET; /* DMA Channel Primary Alternate Set */
    volatile uint32_t ALTCLR; /* DMA Channel Primary Alternate Clear */
    volatile uint32_t PRIOSET; /* DMA Channel Priority Set */
    volatile uint32_t PRIOCLR; /* DMA Channel Priority Clear */
    volatile uint32_t RESERVED[3]; /* RESERVED 1 */
    volatile uint32_t ERRCLR; /* DMA Bus Error Clear */
    volatile uint32_t RESERVED2[300]; /* RESERVED 2 */
    volatile uint32_t CHASGN; /* DMA Channel Assignment */
    volatile uint32_t CHIS; /* DMA Channel Interrupt Status */
    volatile uint32_t RESERVED3[2]; /* RESERVED 3 */
    volatile uint32_t CHMAP0; /* DMA Channel Map Select 0 */
    volatile uint32_t CHMAP1; /* DMA Channel Map Select 1 */
    volatile uint32_t CHMAP2; /* DMA Channel Map Select 2 */
    volatile uint32_t CHMAP3; /* DMA Channel Map Select 3 */
    volatile uint32_t RESERVED4[684]; /* RESERVED 4 */
    volatile uint32_t PeriphlD4; /* DMA Peripheral Identification 4 */
    volatile uint32_t PeriphlD5; /* DMA Peripheral Identification 5 */
    volatile uint32_t PeriphlD6; /* DMA Peripheral Identification 6 */
    volatile uint32_t PeriphlD7; /* DMA Peripheral Identification 6 */
    volatile uint32_t PeriphlD0; /* DMA Peripheral Identification 0 */
    volatile uint32_t PeriphlD1; /* DMA Peripheral Identification 1 */
    volatile uint32_t PeriphlD2; /* DMA Peripheral Identification 2 */
    volatile uint32_t PeriphlD3; /* DMA Peripheral Identification 3 */
    volatile uint32_t PCelllD0; /* DMA PrimeCell Identification 0 */
    volatile uint32_t PCelllD1; /* DMA PrimeCell Identification 1 */
    volatile uint32_t PCelllD2; /* DMA PrimeCell Identification 2 */
    volatile uint32_t PCelllD3; /* DMA PrimeCell Identification 3 */
} uDMA_RegDef_t;

#define uDMA                            ((uDMA_RegDef_t*) uDMA_BASE_ADDRESS)
/**********************************************************************************************************************
 *  Timer Base Definition
 *********************************************************************************************************************/

#define TIMER0_BASE_ADDRESS             0x40030000UL
#define TIMER1_BASE_ADDRESS             0x40031000UL
#define TIMER2_BASE_ADDRESS             0x40032000UL
#define TIMER3_BASE_ADDRESS             0x40033000UL
#define TIMER4_BASE_ADDRESS             0x40034000UL
#define TIMER5_BASE_ADDRESS             0x40035000UL
#define WTIMER0_BASE_ADDRESS            0x40036000UL
#define WTIMER1_BASE_ADDRESS            0x40037000UL
#define WTIMER2_BASE_ADDRESS            0x4004C000UL
#define WTIMER3_BASE_ADDRESS            0x4004D000UL
#define WTIMER4_BASE_ADDRESS            0x4004E000UL
#define WTIMER5_BASE_ADDRESS            0x4004F000UL

/**********************************************************************************************************************
 *  Timer Register Definition
 *********************************************************************************************************************/

typedef struct
{
    volatile uint32_t CFG; /* GPTM Configuration */
    volatile uint32_t TAMR; /* GPTM Timer A Mode */
    volatile uint32_t TBMR; /* GPTM Timer B Mode */
    volatile uint32_t CTL; /* GPTM Control */
    volatile uint32_t SYNC; /* GPTM Synchronize */
    volatile uint32_t RESERVED; /* RESERVED 1 */
    volatile uint32_t IMR; /* GPTM Interrupt Mask */
    volatile uint32_t RIS; /* GPTM Raw Interrupt Status */
    volatile uint32_t MIS; /* GPTM Masked Interrupt Status */
    volatile uint32_t ICR; /* GPTM Interrupt Clear */
    volatile uint32_t TAILR; /* GPTM Timer A Interval Load */
    volatile uint32_t TBILR; /* GPTM Timer B Interval Load */
    volatile uint32_t TAMATCHR; /* GPTM Timer A Match */
    volatile uint32_t TBMATCHR; /* GPTM Timer B Match */
    volatile uint32_t TAPR; /* GPTM Timer A Prescale */
    volatile uint32_t TBPR; /* GPTM Timer B Prescale */
    volatile uint32_t TAPMR; /* GPTM TimerA Prescale Match */
    volatile uint32_t TBPMR; /* GPTM TimerB Prescale Match */
    volatile uint32_t TAR; /* GPTM Timer A */
    volatile uint32_t TBR; /* GPTM Timer B */
    volatile uint32_t TAV; /* GPTM Timer A Value */
    volatile uint32_t TBV; /* GPTM Timer B Value */
    volatile uint32_t RTCPD; /* GPTM RTC Predivide */
    volatile uint32_t TAPS; /* GPTM Timer A Prescale Snapshot */
    volatile uint32_t TBPS; /* GPTM Timer B Prescale Snapshot */
    volatile uint32_t TAPV; /* GPTM Timer A Prescale Value */
    volatile uint32_t TBPV; /* GPTM Timer B Prescale Value */
    volatile uint32_t RESERVED2[981]; /* RESERVED 2 */
    volatile uint32_t PP; /* GPTM Peripheral Properties */
} Timer_RegDef_t;

#define TIMER0                          ((Timer_RegDef_t*) TIMER0_BASE_ADDRESS)
#define TIMER1                          ((Timer_RegDef_t*) TIMER1_BASE_ADDRESS)
#define TIMER2                          ((Timer_RegDef_t*) TIMER2_BASE_ADDRESS)
#define TIMER3                          ((Timer_RegDef_t*) TIMER3_BASE_ADDRESS)
#define TIMER4                          ((Timer_RegDef_t*) TIMER4_BASE_ADDRESS)
#define TIMER5                          ((Timer_RegDef_t*) TIMER5_BASE_ADDRESS)
#define WTIMER0                         ((Timer_RegDef_t*) WTIMER0_BASE_ADDRESS)
#define WTIMER1                         ((Timer_RegDef_t*) WTIMER1_BASE_ADDRESS)
#define WTIMER2                         ((Timer_RegDef_t*) WTIMER2_BASE_ADDRESS)
#define WTIMER3                         ((Timer_RegDef_t*) WTIMER3_BASE_ADDRESS)
#define WTIMER4                         ((Timer_RegDef_t*) WTIMER4_BASE_ADDRESS)
#define WTIMER5                         ((Timer_RegDef_t*) WTIMER5_BASE_ADDRESS)

/******************************************** UART Base Definition ***************************************************/

#define UART0_BASE_ADDRESS              0x4000C000UL
#define UART1_BASE_ADDRESS              0x4000D000UL
#define UART2_BASE_ADDRESS              0x4000E000UL
#define UART3_BASE_ADDRESS              0x4000F000UL
#define UART4_BASE_ADDRESS              0x40010000UL
#define UART5_BASE_ADDRESS              0x40011000UL
#define UART6_BASE_ADDRESS              0x40012000UL
#define UART7_BASE_ADDRESS              0x40013000UL

/******************************************** UART Register Definition ***********************************************/

typedef struct
{
    volatile uint32_t DR; /* UART Data */
    volatile uint32_t RSRECR; /* UART Receive Status/Error Clear */
    volatile uint32_t RESERVED[4]; /* Reserved 1 */
    volatile uint32_t FR; /* UART Flag */
    volatile uint32_t RESERVED2; /* Reserved 2 */
    volatile uint32_t ILPR; /* UART IrDA Low-Power Register */
    volatile uint32_t IBRD; /* UART Integer Baud-Rate Divisor */
    volatile uint32_t FBRD; /* UART Fractional Baud-Rate Divisor */
    volatile uint32_t LCRH; /* UART Line Control */
    volatile uint32_t CTL; /* UART Control */
    volatile uint32_t IFLS; /* UART Interrupt FIFO Level Select */
    volatile uint32_t IM; /* UART Interrupt Mask */
    volatile uint32_t RIS; /* UART Raw Interrupt Status */
    volatile uint32_t MIS; /* UART Masked Interrupt Status */
    volatile uint32_t ICR; /* UART Interrupt Clear */
    volatile uint32_t DMACTL; /* UART DMA Control */
    volatile uint32_t RESERVED3[22]; /* Reserved 3 */
    volatile uint32_t _9BITADDR; /* UART 9-Bit Self Address */
    volatile uint32_t _9BITAMASK; /* UART 9-Bit Self Address Mask */
    volatile uint32_t RESERVED4[965]; /* Reserved 4 */
    volatile uint32_t PP; /* UART Peripheral Properties */
    volatile uint32_t RESERVED5; /* Reserved 5 */
    volatile uint32_t CC; /* UART Clock Configuration */
    volatile uint32_t RESERVED6; /* Reserved 6 */
    volatile uint32_t PeriphlD4; /* UART Peripheral Identification 4 */
    volatile uint32_t PeriphID5; /* UART Peripheral Identification 5 */
    volatile uint32_t PeriphID6; /* UART Peripheral Identification 6 */
    volatile uint32_t PeriphID7; /* UART Peripheral Identification 7 */
    volatile uint32_t PeriphID0; /* UART Peripheral Identification 0 */
    volatile uint32_t PeriphID1; /* UART Peripheral Identification 1 */
    volatile uint32_t PeriphID2; /* UART Peripheral Identification 2 */
    volatile uint32_t PeriphID3; /* UART Peripheral Identification 3 */
    volatile uint32_t PCelllD0; /* UART PrimeCell Identification 0 */
    volatile uint32_t PCelllD1; /* UART PrimeCell Identification 1 */
    volatile uint32_t PCelllD2; /* UART PrimeCell Identification 2 */
    volatile uint32_t PCelllD3; /* UART PrimeCell Identification 3 */
} UART_RegDef_t;

#define UART0                           ((UART_RegDef_t*) UART0_BASE_ADDRESS)
#define UART1                           ((UART_RegDef_t*) UART1_BASE_ADDRESS)
#define UART2                           ((UART_RegDef_t*) UART2_BASE_ADDRESS)
#define UART3                           ((UART_RegDef_t*) UART3_BASE_ADDRESS)
#define UART4                           ((UART_RegDef_t*) UART4_BASE_ADDRESS)
#define UART5                           ((UART_RegDef_t*) UART5_BASE_ADDRESS)
#define UART6                           ((UART_RegDef_t*) UART6_BASE_ADDRESS)
#define UART7                           ((UART_RegDef_t*) UART7_BASE_ADDRESS)

#endif /* MCAL_REGISTER_MAP_H_ */
