/********************************************************/
/* Author      : Ahmed Fathy Abd El-Qadir	            */
/* Date        : 3/12/2021                              */
/* Version     : V 1.0                                  */
/* uC          : STM32F103C8T6                          */
/********************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_
#include "STD_TYPES.h"

/********** Register Definations **********/
#define RCC_CR         *((u32*)0x40021000)  // clock selection for processor
#define RCC_CFGR       *((u32*)0x40021004)  // clock selection for processor
#define RCC_CIR        *((u32*)0x40021008)
#define RCC_APB2RSTR   *((u32*)0x4002100C)
#define RCC_APB1RSTR   *((u32*)0x40021010)
#define RCC_AHBENR     *((u32*)0x40021014)  // E or D clocks for peripherals
#define RCC_APB2ENR    *((u32*)0x40021018)  // E or D clocks for peripherals
#define RCC_APB1ENR    *((u32*)0x4002101c)  // E or D clocks for peripherals
#define RCC_BDCR       *((u32*)0x40021020)
#define RCC_CSR        *((u32*)0x40021024)

#endif  