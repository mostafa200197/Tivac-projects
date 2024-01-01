/*
 * My_Rtos.h
 *
 *  Created on: Dec 13, 2023
 *      Author: DELL G5
 */

#ifndef MY_RTOS_MY_RTOS_H_
#define MY_RTOS_MY_RTOS_H_

#include <stdint.h>
#include "MCAL/NVIC/NVIC.h"
#include "MCAL/Systick/Systick.h"
#include "MCAL/register_map.h"

#define ticks_per_second 1000U
#define log2(x) (32 - __clz(x))



/* thread control block (TCB) */
typedef struct{
    void *SP;  //stack pointer of the Task
    uint32_t Timer; /*thread Time out delay counter*/
    uint8_t priority; /*thread priority number*/
}OSthread;


typedef void (*OSthreadHandler)();
/*******************************************************************************************************************************************/


/*idle thread*/
void main_Idle(void);
/*delay thread by given Ticks*/
void OsDelay(uint32_t ticks);
/*decrement timers of all Non-zero threads*/
void OsTick(void);

/*callback function for idle state*/
void OsOnIdle(void);
/*
 * Function: OSthreadStart
 *
 * Description:
 *   a function to create the thread stack and initializes its stack pointer.
 *
 * Parameters:
 *   - param1: OSthread *me (pointer to TCB)
 *   - param2: OSthreadHandler threadHandler (pointer to function to thread handler)
 *   - param3: void* StackStor (pointer to where the stack memory is located)
 *   - param2: uint32_t StackSize (the stack size)
 * Returns:
 *   None
 */
void OSthreadStart(OSthread *me/* pointer to TCB*/,
                   OSthreadHandler threadHandler /* pointer to function to thread handler*/,
                   void* StackStor /*pointer to where the stack memory is located*/,
                   uint32_t StackSize /*the stack size*/,
                   uint8_t prio/*thread prio number*/);
/*
 * Function: OSthreadStart
 *
 * Description:
 *   a function to create the thread stack and initializes its stack pointer.
 *
 * Parameters:
 *   - param1: OSthread *me (pointer to TCB)
 *   - param2: OSthreadHandler threadHandler (pointer to function to thread handler)
 *   - param3: void* StackStor (pointer to where the stack memory is located)
 *   - param2: uint32_t StackSize (the stack size)
 * Returns:
 *   None
 */
void OSinit(void* IdleStackStor,uint8_t IdleStackSize);
/*
 * Function: OSthreadStart
 *
 * Description:
 *   a function to create the thread stack and initializes its stack pointer.
 *
 * Parameters:
 *   - param1: OSthread *me (pointer to TCB)
 *   - param2: OSthreadHandler threadHandler (pointer to function to thread handler)
 *   - param3: void* StackStor (pointer to where the stack memory is located)
 *   - param2: uint32_t StackSize (the stack size)
 * Returns:
 *   None
 */
void OSsched(void);
/*
 * Function: OSthreadStart
 *
 * Description:
 *   .
 *
 * Parameters:
 *   - param1: OSthread *me (pointer to TCB)
 *   - param2: OSthreadHandler threadHandler (pointer to function to thread handler)
 *   - param3: void* StackStor (pointer to where the stack memory is located)
 *   - param2: uint32_t StackSize (the stack size)
 * Returns:
 *   None
 */
void SchedularStart(void);
/*
 * Function: OSthreadStart
 *
 * Description:
 *   a function to create the thread stack and initializes its stack pointer.
 *
 * Parameters:
 *   - param1: OSthread *me (pointer to TCB)
 *   - param2: OSthreadHandler threadHandler (pointer to function to thread handler)
 *   - param3: void* StackStor (pointer to where the stack memory is located)
 *   - param2: uint32_t StackSize (the stack size)
 * Returns:
 *   None
 */
void OsStartup(void);
void PendSv_handler(void);

#endif /* MY_RTOS_MY_RTOS_H_ */
