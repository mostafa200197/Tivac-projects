/*
 * Bootloader.h
 *
 *  Created on: Jan 5, 2024
 *      Author: Mostafa Gamal
 */

#ifndef APPLECATION_BOOTLOADERAPP_V1_BOOTLOADER_H_
#define APPLECATION_BOOTLOADERAPP_V1_BOOTLOADER_H_

#include "HAL/communication/communication.h"
#include "HAL/flash_mem/flashing.h"

#define BootVersion "V1.2#"

#define flash_address 0x00020000
#define code_size 2

uint16_t crc16(uint8_t volatile *data, uint32_t length);
void NumToArray(uint8_t volatile*arr,uint32_t num);
uint32_t con(uint8_t volatile *arr,uint8_t num);
void BootMain(void);




#endif /* APPLECATION_BOOTLOADERAPP_V1_BOOTLOADER_H_ */
