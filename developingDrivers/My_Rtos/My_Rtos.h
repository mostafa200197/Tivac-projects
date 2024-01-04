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

#define ticks_per_second 100U
/* thread control block (TCB) */
typedef struct{
    void *SP;  //stack pointer of the Task
}OSthread;


typedef void (*OSthreadHandler)();
/*******************************************************************************************************************************************/

void OSthreadStart(OSthread *me/* pointer to TCB*/,
                   OSthreadHandler threadHandler /* pointer to function to thread handler*/,
                   void* StackStor /*pointer to where the stack memory is located*/,
                   uint32_t StackSize /*the stack size*/);
void OSinit(void);
void OSsched(void);

void SchedularStart(void);
void PendSv_handler(void);

#endif /* MY_RTOS_MY_RTOS_H_ */
