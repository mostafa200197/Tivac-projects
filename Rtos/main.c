

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
//TCB object
OSthread blincky1;         //currently a pointer to void

/*space to store thread internal stack*/
uint32_t stack_Arr2[40];
//TCB object
OSthread blincky2;         //currently a pointer to void

/*space to store thread internal stack*/
uint32_t stack_Arr3[40];
//TCB object
OSthread blincky3;

/*space to store thread internal stack*/
uint32_t stack_Idle[40];

void FFdelay(void)
{
    uint32_t i = 0;
    for(i = 0; i<2100;i++)
    {
    }
}

void main_blinky1(void)
{
    while(1)
    {
        LEDS_OFF(PIN0);
        LEDS_ON(RED_LED);
        FFdelay();
        LEDS_OFF(RED_LED);
        OsDelay(20);
    }

}
void main_blinky2(void)
{
    while(1){
        LEDS_OFF(PIN0);
        LEDS_ON(BLUE_LED);
        FFdelay();
        LEDS_OFF(BLUE_LED);
        OsDelay(20);
    }
}

void main_blinky3(void)
{
    while(1){
        LEDS_OFF(PIN0);
        LEDS_ON(GREEN_LED);
        FFdelay();
        LEDS_OFF(GREEN_LED);
        OsDelay(20);
    }
}


void OsOnIdle(void)
{
    GPIO_WRITE(GPIOF, PIN0, high);
}

void main(void)
{

    /*LEDs Initialization*/
    LEDS_INIT();



    /*operating System initialization (set PendSv priority and create idle stack)*/
    OSinit(stack_Idle,sizeof(stack_Idle));

    /*creating threads stacks*/
    OSthreadStart(&blincky1, &main_blinky1, stack_Arr1, sizeof(stack_Arr1),5); //for blincky1
    OSthreadStart(&blincky2, &main_blinky2, stack_Arr2, sizeof(stack_Arr2),4); //for blincky2
    OSthreadStart(&blincky3, &main_blinky3, stack_Arr3, sizeof(stack_Arr3),3); //for blincky3

    /*starting the scheduler*/
    SchedularStart();
    while(1)
    {

    }

}



