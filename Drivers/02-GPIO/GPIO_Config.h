/********************************************************/
/* Author      : Ahmed Fathy Abd El-Qadir	            */
/* Date        : 3/12/2021                              */
/* Version     : V 1.0                                  */
/* uC          : STM32F103C8T6                          */
/********************************************************/

#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

#define PULL_UP			1
#define PULL_DOWN		0

/*
Select the MODE_OF_PULL:
                        PULL_UP
			         or PULL_DOWN
*/
#define MODE_OF_PULL    PULL_UP

#define HIGH	1
#define LOW		0

#endif