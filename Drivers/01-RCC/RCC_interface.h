/********************************************************/
/* Author      : Ahmed Fathy Abd El-Qadir	            */
/* Date        : 3/12/2021                              */
/* Version     : V 1.0                                  */
/* uC          : STM32F103C8T6                          */
/********************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/****** Bus Type ******/
#define    AHB_BUS           0
#define    APB1_BUS          1
#define    APB2_BUS          2

/****** Clock Type *****/
#define RCC_HSE_CRYSTAL      0
#define RCC_HSE_BYPASS       1
#define RCC_HSI              2
#define RCC_PLL              3

/***** PLL Selection ******/
#define PLL_FROM_HSE         4
#define PLL_FROM_HSE_DIV_2   5
#define PLL_FROM_HSI_DIV_2   6


/***** PLL Clock Factor MULTIPLE BY *****/
#define PLL_CLOCK_MULTIPLE_BY_2                 0b0000
#define PLL_CLOCK_MULTIPLE_BY_3			        0b0001
#define PLL_CLOCK_MULTIPLE_BY_4                 0b0010
#define PLL_CLOCK_MULTIPLE_BY_5                 0b0011
#define PLL_CLOCK_MULTIPLE_BY_6                 0b0100
#define PLL_CLOCK_MULTIPLE_BY_7                 0b0101
#define PLL_CLOCK_MULTIPLE_BY_8                 0b0110
#define PLL_CLOCK_MULTIPLE_BY_9                 0b0111
#define PLL_CLOCK_MULTIPLE_BY_10                0b1000
#define PLL_CLOCK_MULTIPLE_BY_11                0b1001
#define PLL_CLOCK_MULTIPLE_BY_12                0b1010
#define PLL_CLOCK_MULTIPLE_BY_13                0b1011
#define PLL_CLOCK_MULTIPLE_BY_14                0b1100
#define PLL_CLOCK_MULTIPLE_BY_15                0b1101
#define PLL_CLOCK_MULTIPLE_BY_16                0b1110


/**********************************************************************/
/*                                                                    */
/*            Clock Security System May be                     	 	  */
/*            1-Enable:                                         	  */
/* 			  To Set HSI By H.W When There are Failure In HSE  	  	  */
/* 			  To Set HSI By H.W When Leaving Stop Or Standby   		  */
/* 			  2-Disable                                        		  */
/* 			  The Previouse To Feature Doesnot Happen      		      */
/*                                                                    */
/**********************************************************************/

#define DISABLE_CLOCK_SECURITY_SYSTEM              0
#define ENABLE_CLOCK_SECURITY_SYSTEM               1

/***********************************************************************/
/*                                                                     */
/*                 Peripheral Clock Enable For AHB Bus                 */
/*                              0- DMA1                                */
/*                              1- DMA2                                */
/*                              2- SRAM                                */
/*                              3- RESERVED                            */
/*                              4- FLITF                               */
/*                              5- RESERVED                            */
/*                              6- CRC                                 */
/*                              7- RESERVED                            */
/*                              8- FSMC                                */
/*                              9- RESERVED                            */
/*                              10- SDIO                               */
/*                              11:31- RESERVED                        */
/*																	   */
/***********************************************************************/

#define    DMA1_RCC         0
#define    DMA2_RCC         1
#define    SRAM_RCC         2
#define    FLITF_RCC        4
#define    CRC_RCC          6
#define    FSMC_RCC         8
#define    SDIO_RCC         10

/***********************************************************************/
/*                                                                     */
/*                 Peripheral Clock Enable For APB2 Bus                */
/*                              0- AFIO                                */
/*                              1- RESERVED                            */
/*                              2- GPIOA                               */
/*                              3- GPIOB                               */
/*                              4- GPIOC                               */
/*                              5- GPIOD                               */
/*                              6- GPIOE                               */
/*                              7- GPIOF                               */
/*                              8- GPIOG                               */
/*                              9- ADC1                                */
/*                              10- ADC2                               */
/*                              11- TIM1                               */
/*                              12- SPI1                               */
/*                              13- TIM8                               */
/*                              14- USART1                             */
/*                              15- ADC3                               */
/*                              16- RESERVED                           */
/*                              17- RESERVED                           */
/*                              18- RESERVED                           */
/*                              19- TIM9                               */
/*                              20- TIM10                              */
/*                              21- TIM11                              */
/*                              22:31- RESERVED                        */
/*                                                                     */
/***********************************************************************/

#define    AFIO_RCC         0
#define    GPIOA_RCC        2
#define    GPIOB_RCC        3
#define    GPIOC_RCC        4
#define    GPIOD_RCC        5
#define    GPIOE_RCC        6
#define    GPIOF_RCC        7
#define    GPIOG_RCC        8
#define    ADC1_RCC         9
#define    ADC2_RCC         10
#define    TIM1_RCC         11
#define    SPI1_RCC         12
#define    TIM8_RCC         13
#define    USART1_RCC       14
#define    ADC3_RCC         15
#define    TIM9_RCC         19
#define    TIM10_RCC        20
#define    TIM11_RCC        21

/**********************************************************************/
/*                                                                    */
/*                 Peripheral Clock Enable For APB1 Bus               */
/*                              0-TIM2                                */
/*                              1-TIM3                                */
/*                              2-TIM4                                */
/*                              3-TIM5                                */
/*                              4-TIM6                                */
/*                              5-TIM7                                */
/*                              6-TIM12                               */
/*                              7-TIM13                               */
/*                              8-TIM14                               */
/*                              9-RESERVED                            */
/*                              10-RESERVED                           */
/*                              11-WWDG                               */
/*                              12-RESERVED                           */
/*                              13-RESERVED                           */
/*                              14-SPI2                               */
/*                              15-SPI3                               */
/*                              16-RESERVED                           */
/*                              17-USART2                             */
/*                              18-USART3                             */
/*                              19-UART4                              */
/*                              20-UART5                              */
/*                              21-I2C1                               */
/*                              22-I2C2                               */
/*                              23-USB                                */
/*                              24-RESERVED                           */
/*                              25-CAN                                */
/*                              26-RESERVED                           */
/*                              27-BKP                                */
/*                              28-PWR                                */
/*                              29-DAC                                */
/*                              30:31-RESERVED                        */
/*																	  */
/**********************************************************************/

#define    TIM2_RCC         0
#define    TIM3_RCC         1
#define    TIM4_RCC         2
#define    TIM5_RCC         3
#define    TIM6_RCC         4
#define    TIM7_RCC         5
#define    TIM12_RCC        6
#define    TIM13_RCC        7
#define    TIM14_RCC        8
#define    WWDG_RCC         11
#define    SPI2_RCC         14
#define    SPI3_RCC         15
#define    USART2_RCC       17
#define    USART3_RCC       18
#define    UART4_RCC        19
#define    UART5_RCC        20
#define    I2C1_RCC         21
#define    I2C2_RCC         22
#define    USB_RCC          23
#define    CAN_RCC          25
#define    BKP_RCC          27
#define    PWR_RCC          28
#define    DAC_RCC          29


/*************************** Functions Prototype ****************************/
void RCC_voidInitSysClock(void); // Function to Intialize the clock source 
void RCC_voidEnableClock( u8 Copy_u8PeripheralBus , u8 Copy_u8Peripheral ); // Function to enable  clock for the specific Peripheral
void RCC_voidDisableClock( u8 Copy_u8PeripheralBus , u8 Copy_u8Peripheral );// Function to disable clock for the specific Peripheral


#endif
