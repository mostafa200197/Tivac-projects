

/**
 * main.c
 */


#include "MCAL/Systick/Systick.h"
#include "HAL/delay/delay_systick/delay_systick.h"
#include "HAL/LEDS/LEDS.h"
#include "interrupt_handlers.h"
#include "My_Rtos/My_Rtos.h"



/*space to store thread internal stack*/
uint32_t stack_Arr1[40];



/*space to store thread internal stack*/
uint32_t stack_Arr2[40];



/*space to store thread internal stack*/
uint32_t stack_Arr3[40];


/*space to store thread internal stack*/
uint32_t stack_Arr4[40];

/*space to store thread internal stack*/
uint32_t stack_Idle[40];


BinarySemaphore sema1;



void main_blinky1(void)
{
    uint32_t i = 0;
    static uint8_t c = 0;
    while(1){
        for(i=0;i<1000;i++){
        GPIO_WRITE(GPIOF, PIN1, high);
        GPIO_WRITE(GPIOF, PIN1, low);
        }
        c++;
        if(c==4){
            c=0;
            semaphore_release(&sema1);
        }
        OsDelay(20);
    }
}
void main_blinky2(void)
{
    while(1){
        GPIO_WRITE(GPIOF, PIN2, high);
        GPIO_WRITE(GPIOF, PIN2, low);
    }


}

void main_blinky3(void)
{
    while(1){
        GPIO_WRITE(GPIOF, PIN3, high);
        GPIO_WRITE(GPIOF, PIN3, low);
    }

}
void main_blinky4(void)
{
    uint32_t i = 0;
    while(1){
        for(i=0;i<1000;i++){
        GPIO_WRITE(GPIOF, PIN0, high);
        GPIO_WRITE(GPIOF, PIN0, low);
        }
        semaphore_wait(&sema1);
    }

}


void OsOnIdle(void)
{

}

void main(void)
{

    /*LEDs Initialization*/
    LEDS_INIT();



    /*operating System initialization (set PendSv priority and create idle stack)*/
    OSinit(stack_Idle,sizeof(stack_Idle));

    /*creating threads stacks*/

    OSthreadStart(&main_blinky1, stack_Arr1, sizeof(stack_Arr1),3); //for blincky1
    OSthreadStart(&main_blinky2, stack_Arr2, sizeof(stack_Arr2),1); //for blincky2
    OSthreadStart(&main_blinky3, stack_Arr3, sizeof(stack_Arr3),1); //for blincky3
    OSthreadStart(&main_blinky4, stack_Arr4, sizeof(stack_Arr4),2); //for blincky4

    /*starting the scheduler*/
    SchedularStart();
    while(1)
    {

    }

}



