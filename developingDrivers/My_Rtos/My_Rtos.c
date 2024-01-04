/*
 * My_Rtos.c
 *
 *  Created on: Dec 13, 2023
 *      Author: DELL G5
 */

#include "My_Rtos.h"
#include "assert.h"

#pragma LOCATION(CurrentThread, 0x2000034C)
#pragma LOCATION(NextThread, 0x20000350)
OSthread *volatile CurrentThread;
OSthread *volatile NextThread;


OSthread *ThreadArr[33];
uint8_t ThreadIndex=0;
uint8_t ThreadNum = 0;
uint8_t MaxThreadNum = 32;

OsStartup(){

    NVIC->SYSPRI3 &= ~(0xFF<<24); //set SYSTICK IRQ as highest priority
    systick_init(System_clk()/ticks_per_second);
    systick_interrupt_enable();
    systick_start();
}


void OSinit(void)
{
    /*set PENDSV interrupt as the lowest priority*/
    NVIC->SYSPRI3 |= (0xFF<<16);
}




void OSsched(void)
{
    ++ThreadIndex;
    if(ThreadIndex == ThreadNum)
    {
        ThreadIndex = 0;
    }
    NextThread = ThreadArr[ThreadIndex];
    if(NextThread != CurrentThread)
    {
        NVIC->INTCTRL |= (1<<28); //trigger interrupt
    }
}

void SchedularStart()
{
    OsStartup(); //configure the systick
    interrupts_disable(); //start critical section
    OSsched();
    interrupts_enable();
    /*should not reach this point due to context switch*/
    assert(0);
}

void OSthreadStart(OSthread *me/* pointer to TCB*/,
                   OSthreadHandler threadHandler /* pointer to function to thread handler*/,
                   void* StackStor /*pointer to where the stack memory is located*/,
                   uint32_t StackSize /*the stack size*/)
{
    /* stack pointer pointing to last memory location, round down to 8 Byte boundary.*/

    uint32_t *SP = (uint32_t*)((((uint32_t)StackStor + StackSize)/8)*8);
    uint32_t *stackLimit;

    *(--SP) = (1<<24); //PSR: set machine inSTRuction to thump state
    *(--SP) = (uint32_t)threadHandler; //PC: holding return address of the function
    *(--SP) = 0x0000000EU; //LR experimental value
    *(--SP) = 0x0000000CU; //R12 experimental value
    *(--SP) = 0x00000003U; //R3 experimental value
    *(--SP) = 0x00000002U; //R2 experimental value
    *(--SP) = 0x00000001U; //R1 experimental value
    *(--SP) = 0x00000000U; //R0 experimental value
    /* additional registers R4-R11 */
    *(--SP) = 0x0000000BU; //R11 experimental value
    *(--SP) = 0x0000000AU; //R10 experimental value
    *(--SP) = 0x00000009U; //R9 experimental value
    *(--SP) = 0x00000008U; //R8 experimental value
    *(--SP) = 0x00000007U; //R7 experimental value
    *(--SP) = 0x00000006U; //R6 experimental value
    *(--SP) = 0x00000005U; //R5 experimental value
    *(--SP) = 0x00000004U; //R4 experimental value
    /*save the top of the stack to the OSThread attribute*/
    me->SP =SP;


    if(ThreadIndex < MaxThreadNum)
    {
        ThreadArr[ThreadNum] = me;
        ThreadNum++;
    }
    else{
        assert(0);
    }

    /*round up the stack bottom to 8 Byte boundary*/
    stackLimit = (uint32_t*)(((((uint32_t)StackStor -1U)/8)+1U)*8);


    //fill rest of stack frame to garbage value for demonSTRation
    for(SP = SP - 1U;SP>=stackLimit;SP--)
    {
        *SP = 0xDEADBEEFU;
    }

}



__attribute__ ((naked))
void PendSv_handler(void) {
__asm volatile (
    /* __disable_irq(); */
    "  CPSID         I                 \n"

    /* if (OS_curr != (OSThread *)0) { */
    "  MOVW          r1,#0x034C       \n"
    "  MOVT          r1,#0x2000       \n"
    "  LDR           r1,[r1,#0x00]     \n"
    "  CBZ           r1,PendSV_restore \n"
    /* push registers r4-r11 on the stack */
    "  PUSH          {r4-r11}          \n"
    /* OS_curr->sp = sp; */
    /*loading the global CurrentThread address into R1*/
    "  MOVW          r1,#0x034C       \n"
    "  MOVT          r1,#0x2000       \n"
        /*loading the value stored in global CurrentThread address into R1 (the stack pointer) into R1*/
    "  LDR           r1,[r1,#0x00]     \n"
        /*loading sp value into stack pointer*/
    "  STR           SP,[r1,#0x00]     \n"
    /* } */

    "PendSV_restore:                   \n"
    /* sp = OS_next->sp; */
        /*loading the global NextThread address into R1*/
    "  MOVW          r1,#0x0350       \n"
    "  MOVT          r1,#0x2000       \n"
        /*loading the value stored in global NextThread address into R1 (the stack pointer [pointer address] into R1*/
    "  LDR           r1,[r1,#0x00]     \n"
        /*loading the address the pointer is pointing to (top of stack) value SP register*/
    "  LDR           SP,[r1,#0x00]     \n"

    /* OS_curr = OS_next; */
        /*loading the global NextThread address into R1*/
    "  MOVW          r1,#0x0350       \n"
    "  MOVT          r1,#0x2000       \n"
    "  LDR           r1,[r1,#0x00]     \n"
        /*loading the global CurrentThread address into R2*/
    "  MOVW          r2,#0x034C       \n"
    "  MOVT          r2,#0x2000       \n"
    "  STR           r1,[r2,#0x00]     \n"
    /* pop registers r4-r11 */
    "  POP           {r4-r11}          \n"
    /* __enable_irq(); */
    "  CPSIE         I                 \n"
    /* return to the next thread */
    "  BX            lr                \n"
    );
}



