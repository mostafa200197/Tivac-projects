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

uint8_t MaxThreadNum = 32U; /*Max number of threads*/
OSthread IdleThread;   /*TCB object for Idle thread*/
uint32_t OsReadyMask; /*mask to hold the ready state of each thread*/
uint32_t OsDelayedSet; /*mask holding all the delayed threads*/


void main_Idle(void)
{
    while(1){
        /*what to do inside the Idle task*/
        OsOnIdle();
    }
}

void OSinit(void* IdleStackStor,uint8_t IdleStackSize)
{
    /*set PENDSV interrupt as the lowest priority*/
    NVIC->SYSPRI3 |= (0xFF<<16);
    /*create Idle task stack*/
    OSthreadStart(&IdleThread, &main_Idle,IdleStackStor,IdleStackSize,0);
}
void OsStartup(void){
    NVIC->SYSPRI3 &= ~(0xFF<<24); //set SYSTICK IRQ as highest priority
    systick_init(System_clk()/ticks_per_second); //configure the Systick handler
    systick_interrupt_enable(); //enable Systick interrupt
    systick_start(); //start Systick
}

void OSsched(void)
{
    /*checks if all threads are blocked*/
    if(OsReadyMask == 0)
    {
        NextThread = ThreadArr[0]; /*point the next thread to Idle thread*/
    }
    /*else go through the thread ready mask and check for ready threads*/
    else{
        /*set the next running thread to the highest priority ready thread*/
        NextThread = ThreadArr[log2(OsReadyMask)];
        /*make sure next thread is not pointing to void*/
        assert(NextThread != (OSthread*)0);
    }

    //NextThread = ThreadArr[ThreadIndex];
    if(NextThread != CurrentThread)
    {
        NVIC->INTCTRL |= (1<<28); //trigger PendSv interrupt
    }
}

void SchedularStart()
{
    /*start and configure interrupts*/
    OsStartup();

    /*critical section*/
    interrupts_disable;
    OSsched();
    interrupts_enable;
    /*should not reach this point due to context switch*/
    assert(0U);
}

void OsDelay(uint32_t ticks)
{
    interrupts_disable;
    /*make sure delay is not called from Idle thread*/
    assert(CurrentThread != ThreadArr[0]);
    /*set the timer in TCB to the required delay ticks*/
    CurrentThread->Timer = ticks;
    /*set thread state as blocked in the thread ready mask*/
    OsReadyMask &= ~(1<< (CurrentThread->priority - 1U));
    /*add the thread to the delayed thread mask*/
    OsDelayedSet |= (1<<(CurrentThread->priority - 1U));
    /*call OsSched() to take control away from the blocked thread*/
    OSsched();
    interrupts_enable;
}
void OsTick(void)
{
    /*a temporary variable used to make sure the while loop iterated across all the delayed tasks*/
    uint32_t workingset = OsDelayedSet;
    /*while there is still non processed delayed thread*/
    while(workingset != 0U)
    {
        /*temporary variable to hold the highest priority delayed non processed thread*/
        OSthread* temp = ThreadArr[log2(workingset)];
        /*decrement the timer*/
        (temp->Timer)--;
        /*if it reached zero (ready)*/
        if((temp->Timer) == 0U)
        {
            /*make it ready in the ready mask*/
            OsReadyMask |= (1<<(temp->priority - 1U));
            /*and remove it from the delayed set*/
            OsDelayedSet &= ~(1<<(temp->priority - 1U));
        }
        /*remove the processed thread from the working threads mask*/
        workingset &= ~(1<<(temp->priority - 1U));
    }

}

void OSthreadStart(OSthread *me/* pointer to TCB*/,
                   OSthreadHandler threadHandler /* pointer to function to thread handler*/,
                   void* StackStor /*pointer to where the stack memory is located*/,
                   uint32_t StackSize /*the stack size*/,
                   uint8_t prio/*thread prio number*/)
{

    /*check if priority is in valid limits and is not already used*/
    assert((prio < MaxThreadNum) && (ThreadArr[prio] == (OSthread*)0));

    /* stack pointer pointing to last memory location, round down to 8 Byte boundary.*/
    uint32_t *SP = (uint32_t*)((((uint32_t)StackStor + StackSize)/8)*8);
    uint32_t *stackLimit;

    *(--SP) = (1<<24); //PSR: set machine instruction For arm M4 thump state
    *(--SP) = (uint32_t)threadHandler; //PC: holding return address of the thread handler
    *(--SP) = 0x0000000EU; //LR initial value
    *(--SP) = 0x0000000CU; //R12 initial value
    *(--SP) = 0x00000003U; //R3 initial value
    *(--SP) = 0x00000002U; //R2 initial value
    *(--SP) = 0x00000001U; //R1 initial value
    *(--SP) = 0x00000000U; //R0 initial value
    /* additional registers R4-R11 For AAPCS compliance*/
    *(--SP) = 0x0000000BU; //R11 initial value
    *(--SP) = 0x0000000AU; //R10 initial value
    *(--SP) = 0x00000009U; //R9 initial value
    *(--SP) = 0x00000008U; //R8 initial value
    *(--SP) = 0x00000007U; //R7 initial value
    *(--SP) = 0x00000006U; //R6 initial value
    *(--SP) = 0x00000005U; //R5 initial value
    *(--SP) = 0x00000004U; //R4 initial value
    /*save the top of the stack to the OSThread attribute (TCB)*/
    me->SP =SP;
    /*save thread priority in its TCB*/
    me->priority = prio;

    /*save thread in the thread array according to its priority number*/
        ThreadArr[prio] = me;
    /*if priority is not zero (idle) set it to ready state in read mask*/
        if(prio > 0U)
        {
            /*make thread in ready state*/
            OsReadyMask |= (1<<(prio-1));
        }

    /*round up the stack bottom to 8 Byte boundary*/
    stackLimit = (uint32_t*)(((((uint32_t)StackStor -1U)/8)+1U)*8);
    //fill rest of stack frame to garbage value for illustration
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
    /*loading the global CurrentThread address into R1*/
    "  MOVW          r1,#0x034C       \n"
    "  MOVT          r1,#0x2000       \n"
    /*loading the value stored in global CurrentThread address into R1 (the stack pointer) into R1*/
    "  LDR           r1,[r1,#0x00]     \n"
    /*loading sp value into stack pointer*/
    "  STR           SP,[r1,#0x00]     \n"
    /* } */
    "PendSV_restore:                   \n"
    /*loading the global NextThread address into R1*/
    "  MOVW          r1,#0x0350       \n"
    "  MOVT          r1,#0x2000       \n"
    /*loading the value stored in global NextThread address into R1 (the stack pointer [pointer address] into R1*/
    "  LDR           r1,[r1,#0x00]     \n"
    /*loading the address the pointer is pointing to (top of stack) value SP register*/
    "  LDR           SP,[r1,#0x00]     \n"
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
    "  CPSIE         I                 \n"
    /* return to the next thread */
    "  BX            lr                \n"
    );
}



