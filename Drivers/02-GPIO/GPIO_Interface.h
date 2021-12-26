/********************************************************/
/* Author      : Ahmed Fathy Abd El-Qadir	            */
/* Date        : 3/12/2021                              */
/* Version     : V 1.0                                  */
/* uC          : STM32F103C8T6                          */
/********************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define PORTA	2
#define	PORTB	3
#define PORTC	4

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15

/*************** Output Modes **************/
#define GPIO_OUTPUT_PP_10MHZ	0b0001		//10Mhz push pull
#define GPIO_OUTPUT_OD_10MHZ	0b0101		//10MHz	open drain
#define GPIO_OUTPUT_AFPP_10MHZ	0b1001		//10MHz	alternative function push pul
#define GPIO_OUTPUT_AFOD_10MHZ	0b1101		//10MHz	alternative function open drain

#define GPIO_OUTPUT_PP_2MHZ  	0b0010		//2Mhz  push pull
#define GPIO_OUTPUT_OD_2MHZ	    0b0110		//2MHz	open drain
#define GPIO_OUTPUT_AFPP_2MHZ	0b1010		//2MHz	alternative function push pul
#define GPIO_OUTPUT_AFOD_2MHZ	0b1110		//2MHz	alternative function open drain

#define GPIO_OUTPUT_PP_50MHZ	0b0011		//50Mhz push pull
#define GPIO_OUTPUT_OD_50MHZ	0b0111		//50MHz	open drain
#define GPIO_OUTPUT_AFPP_50MHZ	0b1011		//50MHz	alternative function push pul
#define GPIO_OUTPUT_AFOD_50MHZ	0b1111		//50MHz	alternative function open drain

/*************** Input Modes **************/
#define GPIO_INPUT_ANALOG		0b0000		//Input Analog
#define GPIO_INPUT_FLOATING		0b0100		//Input Floating
#define GPIO_INPUT_PULLUP_DOWN	0b1000 		//Input Pullup/PullDown



/**************************** Functions Prototype **********************************/
/* Functions to set the Direction of the Pins and its mode */
void GPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);

/* Functions to set the Pin to High or Low */
void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

/* Functions to get the Pins value */
u8 GPIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

/* Functions to set the Direction of all Pins in the port and its mode */
void GPIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Mode);

/* Functions to set value to the port */
void GPIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

/* Functions to Lock the change of any pin */
void GPIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8Pin);

/* Functions to open the Lock of any pin */
void GPIO_voidOpenPin(u8 Copy_u8Port, u8 Copy_u8Pin)


#endif