/*
 * DMA.h
 *
 *  Created on: Oct 5, 2023
 *      Author: mostafa gamal
 */

#ifndef MCAL_DMA_DMA_H_
#define MCAL_DMA_DMA_H_
/******************************************************************************
includes
******************************************************************************/
#include "MCAL/register_map.h"


/******************************************************************************
#defines
******************************************************************************/
#define UDMA_DST_INC_8          0x00000000
#define UDMA_DST_INC_16         0x40000000
#define UDMA_DST_INC_32         0x80000000
#define UDMA_DST_INC_NONE       0xc0000000
#define UDMA_SRC_INC_8          0x00000000
#define UDMA_SRC_INC_16         0x04000000
#define UDMA_SRC_INC_32         0x08000000
#define UDMA_SRC_INC_NONE       0x0c000000
#define UDMA_SIZE_8             0x00000000
#define UDMA_SIZE_16            0x11000000
#define UDMA_SIZE_32            0x22000000
#define UDMA_DST_PROT_PRIV      0x00200000
#define UDMA_SRC_PROT_PRIV      0x00040000
#define UDMA_ARB_1              0x00000000
#define UDMA_ARB_2              0x00004000
#define UDMA_ARB_4              0x00008000
#define UDMA_ARB_8              0x0000c000
#define UDMA_ARB_16             0x00010000
#define UDMA_ARB_32             0x00014000
#define UDMA_ARB_64             0x00018000
#define UDMA_ARB_128            0x0001c000
#define UDMA_ARB_256            0x00020000
#define UDMA_ARB_512            0x00024000
#define UDMA_ARB_1024           0x00028000
#define UDMA_NEXT_USEBURST      0x00000008


#define UDMA_MODE_STOP          0x00000000
#define UDMA_MODE_BASIC         0x00000001
#define UDMA_MODE_AUTO          0x00000002
#define UDMA_MODE_PINGPONG      0x00000003
#define UDMA_MODE_MEM_SCATTER_GATHER                                          \
                                0x00000004
#define UDMA_MODE_PER_SCATTER_GATHER                                          \
                                0x00000006
#define UDMA_MODE_ALT_SELECT    0x00000001
/******************************************************************************
type defines
******************************************************************************/
typedef struct
{
    volatile uint32_t SRCENDP; /* DMA Channel Source Address End Pointer */
    volatile uint32_t DSTENDP; /* DMA Channel Destination Address End Pointer */
    volatile uint32_t CHCTL; /* DMA Channel Control Word */
    volatile uint32_t UNUSED;
} uDMA_Channel_Control_Structure_RegDef_t;
/******************************************************************************
function prototypes
******************************************************************************/
void DMA_init(uint32_t *source,uint32_t channel);
uDMA_Channel_Control_Structure_RegDef_t control_table[30] __attribute__((aligned(1024)));
void DMA_start_transfere(uint32_t channel_number,uint32_t *destination,uint32_t modes,uint32_t items_number);

#endif /* MCAL_DMA_DMA_H_ */
