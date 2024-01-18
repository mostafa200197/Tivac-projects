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
#include "dataSturct/datastruct.h"

#define ticks_per_second 1000U
#define log2(x) (32 - __clz(x))

//*********************************************************************************
// Typedefs
//*********************************************************************************

typedef struct {
  uint8_t locked;
  OSthread* waiting_task;
} BinarySemaphore;

void semaphore_release(BinarySemaphore* semaphore);
void semaphore_wait(BinarySemaphore* semaphore);

/*type to hold thread handler*/
typedef void (*OSthreadHandler)();


//*********************************************************************************
// Function prototypes
//*********************************************************************************

//******************************************************************************
// Function: main_Idle
// Description: Idle thread.
// Parameters: None
// Returns: None
//******************************************************************************
void main_Idle(void);

//******************************************************************************
// Function: OsDelay
// Description: Delay thread by given Ticks.
// Parameters:
//    -uint32_t ticks: number of delay tickss
// Returns: None
//******************************************************************************
void OsDelay(uint32_t ticks);

//******************************************************************************
// Function: OsTick
// Description: Timing management of tasks(decrement all not zero task timers).
// Parameters: None
// Returns: None
//******************************************************************************
void OsTick(void);

//******************************************************************************
// Function: OsOnIdle
// Description: Idle state CallBack function.
// Parameters: None
// Returns: None
//******************************************************************************
void OsOnIdle(void);

//******************************************************************************
// Function: OSthreadStart
// Description: Creates thread stack and initializes its stack pointer.
// Parameters:
//     - OSthread *me: Pointer to TCB
//     - OSthreadHandler threadHandler: Pointer to thread handler function
//     - void* StackStor: Pointer to stack memory location
//     - uint32_t StackSize: Stack size
// Returns: None
//******************************************************************************

void OSthreadStart(
                   OSthreadHandler threadHandler /* pointer to function to thread handler*/,
                   void* StackStor /*pointer to where the stack memory is located*/,
                   uint32_t StackSize /*the stack size*/,
                   uint8_t prio/*thread prio number*/);

//******************************************************************************
// Function: OSinit
// Description: Sets PendSv priority and sets up idle stack.
// Parameters:
//     - void* IdleStackStor: Pointer to idle stack memory location
//     - uint8_t IdleStackSize: Idle stack size
// Returns: None
//******************************************************************************

void OSinit(void* IdleStackStor,uint8_t IdleStackSize);
//******************************************************************************
// Function: OSsched
// Description: Manages threads and triggers context switch.
// Parameters: None
// Returns: None
//******************************************************************************
void OSsched(void);

//******************************************************************************
// Function: SchedularStart
// Description: Starts OS, configures interrupts, and starts first OSsched.
// Parameters: None
// Returns: None
//******************************************************************************
void SchedularStart(void);

//******************************************************************************
// Function: OsStartup
// Description: Configures system interrupts for the first time, called by schedularStart.
// Parameters: None
// Returns: None
//******************************************************************************
void OsStartup(void);

//******************************************************************************
// Function: PendSv_handler
// Description: PendSv IRQ responsible for context switch between threads.
// Parameters: None
// Returns: None
//******************************************************************************
void PendSv_handler(void);

#endif /* MY_RTOS_MY_RTOS_H_ */
