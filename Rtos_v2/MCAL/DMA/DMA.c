/*
 * DMA.c
 *
 *  Created on: Oct 5, 2023
 *      Author: Mostafa Gamal
 */


#include "MCAL/DMA/DMA.h"


/******************************************************************************
Function: initializeDMA
Description: Initializes the DMA module and control table.
Parameters:
source: End pointer of the source address.
destination: End pointer of the destination address.
channel: Channel number to initialize.
Returns: None
******************************************************************************/

void DMA_init(uint32_t *source,uint32_t channel)
{
    SYSCTL->RCGCDMA|=0x01;  //enable UDMA clock
    uDMA->CFG|=0X01; //enable UDMA
    uDMA->USEBURSTCLR=(1<<channel);
    uDMA->REQMASKCLR=(1<<channel);
    uDMA->CTLBASE=(uint32_t)&control_table[0]; //Program the location of the channel control table
    uDMA->USEBURSTSET |= (1<<17);
    uDMA->ALTCLR=(1<<30); //set for only primary structure
    control_table[channel].SRCENDP=(uint32_t)source; //adding source address
    //control_table[channel].DSTENDP=(uint32_t)destination; //adding destination address
}
/******************************************************************************
Function: DMA_start_transfere
Description: add control parameters and start transfer.
Parameters:
channel_number: Channel number to configure.
modes: control parameters of the channel.
items_number: number of messages to send (array size).
Returns: None
******************************************************************************/
void DMA_start_transfere(uint32_t channel_number,uint32_t *destination,uint32_t modes,uint32_t items_number)
{

    control_table[channel_number].DSTENDP=(uint32_t)destination; //adding destination address
    control_table[channel_number].CHCTL=modes|((items_number-1)<<4);
    uDMA->ENASET|=(1<<channel_number); //enable channel 30
    uDMA->SWREQ|=(1<<channel_number); //start sw request
}



