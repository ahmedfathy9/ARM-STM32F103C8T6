/********************************************************/
/* Author      : Ahmed Fathy Abd El-Qadir	            */
/* Date        : 3/12/2021                              */
/* Version     : V 1.0                                  */
/* uC          : STM32F103C8T6                          */
/********************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/* Clock options:
                1- RCC_HSE_CRYSTAL
				2- RCC_HSE_BYPASS
				3- RCC_HSI
				4- RCC_PLL
 */
#define SYSTEM_CLOCK_TYPE    RCC_HSE_CRYSTAL

/* PLL Input options :  (Note: Only when RCC_PLL Clock Type Selected)
				     1- PLL_FROM_HSE         
					 2- PLL_FROM_HSE_DIV_2   
					 3- PLL_FROM_HSI_DIV_2
 */
 #if SYSTEM_CLOCK_TYPE == RCC_PLL
 #define PLL_INPUT_TYPE   PLL_FROM_HSE
 #endif
 
 /* PLL Multiplication Factor options :  (Note: Only when RCC_PLL Clock Type Selected)
									  1-  PLL_CLOCK_MULTIPLE_BY_2
									  2-  PLL_CLOCK_MULTIPLE_BY_3
									  3-  PLL_CLOCK_MULTIPLE_BY_4
									  4-  PLL_CLOCK_MULTIPLE_BY_5
									  5-  PLL_CLOCK_MULTIPLE_BY_6 
									  6-  PLL_CLOCK_MULTIPLE_BY_7
									  7-  PLL_CLOCK_MULTIPLE_BY_8
									  8-  PLL_CLOCK_MULTIPLE_BY_9
									  9-  PLL_CLOCK_MULTIPLE_BY_10
									  10- PLL_CLOCK_MULTIPLE_BY_11
									  11- PLL_CLOCK_MULTIPLE_BY_12
									  12- PLL_CLOCK_MULTIPLE_BY_13
									  13- PLL_CLOCK_MULTIPLE_BY_14
									  14- PLL_CLOCK_MULTIPLE_BY_15
									  15- PLL_CLOCK_MULTIPLE_BY_16
									  16- PLL_CLOCK_MULTIPLE_BY_16
 */
 #if SYSTEM_CLOCK_TYPE == RCC_PLL
 #define PLL_MUL_FACTOR   PLL_CLOCK_MULTIPLE_BY_2
 #endif
 
#endif