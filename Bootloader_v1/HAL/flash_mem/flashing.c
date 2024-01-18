/*
 * flashing.c
 *
 *  Created on: Jan 12, 2024
 *      Author: DELL G5
 */




#include "flashing.h"

void flash_Erase(uint32_t address,uint8_t num)
{
    uint8_t i = 0;
    uint8_t flag = 0;
    for(i = 0;i<num;i++)
    {
        flag = FlashErase((uint32_t)address + i*block_size);
        assert(flag==0);
    }
}

void jump_to_image(void){
    __asm("        MOVS      r0,#0x20000");
    __asm("        LDR       r1,[r0, #0x4]");
    __asm("        BX        r1");
}

