/*
 * flashing.h
 *
 *  Created on: Jan 12, 2024
 *      Author: DELL G5
 */

#ifndef HAL_FLASH_MEM_FLASHING_H_
#define HAL_FLASH_MEM_FLASHING_H_

#include "stdbool.h"
#include "stdint.h"
#include "driverlib/flash.h"

#include "assert.h"

#define block_size 1000

void flash_Erase(uint32_t address,uint8_t num);
void jump_to_image(void);



#endif /* HAL_FLASH_MEM_FLASHING_H_ */
