

/**
 * main.c
 */


#include "MCAL/Systick/Systick.h"
#include "HAL/delay/delay_systick/delay_systick.h"
#include "HAL/LEDS/LEDS.h"
#include "interrupt_handlers.h"
#include "My_Rtos/My_Rtos.h"

uint32_t stack_Arr1[40];
OSthread blincky1;         //currently a pointer to void

uint32_t stack_Arr2[40];
OSthread blincky2;         //currently a pointer to void


uint32_t stack_Arr3[40];
OSthread blincky3;



void main_blinky1(void)
{
    while(1)
    {
        LEDS_ON(RED_LED);
        //ticker_delay(ticks_per_second/4U);
        LEDS_OFF(RED_LED);
       // ticker_delay(ticks_per_second*3U/4U);

    }

}
void main_blinky2(void)
{
    while(1){
    LEDS_ON(BLUE_LED);
    //ticker_delay(ticks_per_second/2U);
    LEDS_OFF(BLUE_LED);
    //ticker_delay(ticks_per_second/3U);
    }
}

void main_blinky3(void)
{
    while(1){
    LEDS_ON(GREEN_LED);
    //ticker_delay(ticks_per_second/5U);
    LEDS_OFF(GREEN_LED);
    //ticker_delay(ticks_per_second/6U);
    }
}


int main(void)
{
//    void *volatile address1 = &blincky1;
//    void *volatile address2 = &blincky2;
    LEDS_INIT();
    //delay_ticker_init(System_clk()/ticks_per_second);
    OSinit();

    OSthreadStart(&blincky1, &main_blinky1, stack_Arr1, sizeof(stack_Arr1)); //for blincky1
    OSthreadStart(&blincky2, &main_blinky2, stack_Arr2, sizeof(stack_Arr2)); //for blincky2
    OSthreadStart(&blincky3, &main_blinky3, stack_Arr3, sizeof(stack_Arr3)); //for blincky3
    /*all threads are now in dormant state*/
    SchedularStart();
    while(1)
    {
    }
	return 0;
}



