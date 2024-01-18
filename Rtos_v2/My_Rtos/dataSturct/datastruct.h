/*
 * datastruct.h
 *
 *  Created on: Jan 11, 2024
 *      Author: DELL G5
 */

#ifndef MY_RTOS_DATASTURCT_DATASTRUCT_H_
#define MY_RTOS_DATASTURCT_DATASTRUCT_H_


#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct TCP{
    void *SP;  //stack pointer of the Task
    uint32_t Timer; /*thread Time out delay counter*/
    uint8_t priority; /*thread priority*/
    uint8_t index; /*index to keep track of the thread (debugging purposes)*/
    uint8_t ready; /*flag to if task is ready or blocked*/
    struct TCP* next;
}OSthread;

void CreateTCB(OSthread ** head,void *SP,uint32_t Timer,uint8_t index,uint8_t ready,uint8_t priority);
OSthread* find(OSthread** head,uint8_t index);
OSthread* find_idle(OSthread** head);
OSthread* find_highest_priority_ready(OSthread** head);
OSthread* find_highest_priority_Notready(OSthread** head);
uint8_t list_len(OSthread * head);
#endif /* MY_RTOS_DATASTURCT_DATASTRUCT_H_ */
