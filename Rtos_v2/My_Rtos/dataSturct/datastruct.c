/*
 * datastruct.c
 *
 *  Created on: Jan 11, 2024
 *      Author: DELL G5
 */





// Online C Compiler - Build, Compile and Run your C programs online in your favorite browser

#include "datastruct.h"

static OSthread* lastSelectedThread = NULL;
uint8_t list_len(OSthread * head){
    uint8_t counter= 0;
    while(head != NULL){
        counter++;
        head = head->next;
    }
    return counter;
}

OSthread* find(OSthread** head,uint8_t index)
{
    OSthread*Current = *head;
    while(Current->index != index){
        Current = Current->next;
    }
    return (OSthread*)Current;
}
OSthread* find_idle(OSthread** head)
{
    OSthread*Current = *head;
    while(Current->priority != 0){
        Current = Current->next;
    }
    return (OSthread*)Current;
}

void CreateTCB(OSthread ** head,void *SP,uint32_t Timer,uint8_t index,uint8_t ready,uint8_t priority){

    OSthread* new=(OSthread*)malloc(sizeof(OSthread));
    new->SP = SP;
    new->Timer = Timer;
    new->priority = priority;
    new->index = index;
    new->ready = ready;
    new->next = NULL;

    if(*head == NULL){
        *head = new;
    }
    else{
        OSthread* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next=new;
    }
}

OSthread* find_highest_priority_ready(OSthread** head) {
    OSthread* current = *head;
    OSthread* result = NULL;
    uint8_t max = 0;

    // If lastSelectedThread is at the end of the list or is NULL, start from the beginning
    if (lastSelectedThread == NULL || lastSelectedThread->next == NULL) {
        current = *head;
    } else {
        current = lastSelectedThread->next;
    }

    while (current != NULL) {
        if ((current->ready == 1) && (current->priority > max)) {
            max = current->priority;
            result = current;
        }

        current = current->next;
    }

    if((lastSelectedThread->priority > result->priority) && lastSelectedThread->ready == 1){
        result = lastSelectedThread;
    }
    else{
        lastSelectedThread = result;
    }

    return result;
}

OSthread* find_highest_priority_Notready(OSthread** head){

    OSthread* current = *head;
    OSthread* result = NULL;
    uint8_t max = 0;
    while(current != NULL){
        if((current->ready == 0)&&(current->priority >= max)){

            max = current->priority;
            result = current;
        }
        current = current->next;
    }

    return (OSthread*)result;

}

