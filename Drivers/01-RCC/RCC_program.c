/********************************************************/
/* Author      : Ahmed Fathy Abd El-Qadir	            */
/* Date        : 3/12/2021                              */
/* Version     : V 1.0                                  */
/* uC          : STM32F103C8T6                          */
/********************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/********************* Initialization System Clock **********************/

void RCC_voidInitSysClock(void)
{
	if(SYSTEM_CLOCK_TYPE == RCC_HSE_CRYSTAL)
	{
		RCC_CR =   0x00010000 ; // High on Bit no.16
		RCC_CFGR = 0x00000001; //put sw[1:0] bits = 01
	}
	else if(SYSTEM_CLOCK_TYPE == RCC_HSE_BYPASS)
	{
		RCC_CR =   0x00050000 ; // High on Bits no.16 & no.18
		RCC_CFGR = 0x00000001; //put sw[1:0] bits = 01
		
	}
	else if (SYSTEM_CLOCK_TYPE == RCC_HSI)
	{
		RCC_CR =  0x00000081 ; //Tramming bits (3:7) must equal 16 = 0b10000 for HSI + High on Bits no.1
		RCC_CFGR= 0x00000000 ; //put sw[1:0] bits = 00
		
	}
	else if (SYSTEM_CLOCK_TYPE == RCC_PLL)
	{
		if(PLL_INPUT_TYPE == PLL_FROM_HSE)
		{
		RCC_CR = 0x01000000; // High on Bit no.24 to enable PLL
		RCC_CFGR=0x00010002; //High on Bit no.16 and put sw[1:0] bits = 10
			
		}
		else if(PLL_INPUT_TYPE == PLL_FROM_HSE_DIV_2)
		{
		RCC_CR = 0x01000000; // High on Bit no.24 to enable PLL
		RCC_CFGR=0x00030002; //High on Bit no.16 & no.17 and put sw[1:0] bits = 10
			
		}
		else if(PLL_INPUT_TYPE == PLL_FROM_HSI_DIV_2)
		{
		RCC_CR = 0x01000000; // High on Bit no.24 to enable PLL
		RCC_CFGR=0x00000002; //Low on Bit no.16 & no.17 and put sw[1:0] bits = 10
		}
	   // Set Mul Factor for PLL
	   switch (PLL_MUL_FACTOR) 
	   {
		    // Need to write on Bits 18:21 only and keep other Bits same as in RCC_CFGR
			case PLL_CLOCK_MULTIPLE_BY_2 :    // Put 0b0000 in Bits 18:21
			{
				CLR_BIT(RCC_CFGR,18);
				CLR_BIT(RCC_CFGR,19);
				CLR_BIT(RCC_CFGR,20);
				CLR_BIT(RCC_CFGR,21);  
				break;
			}          
			case PLL_CLOCK_MULTIPLE_BY_3 :	  // Put 0b0001 in Bits 18:21 
			{
				SET_BIT(RCC_CFGR,18);
				CLR_BIT(RCC_CFGR,19);
				CLR_BIT(RCC_CFGR,20);
				CLR_BIT(RCC_CFGR,21);  
				break;
			}
			case PLL_CLOCK_MULTIPLE_BY_4  :   // Put 0b0010 in Bits 18:21 
			{
				CLR_BIT(RCC_CFGR,18);
				SET_BIT(RCC_CFGR,19);
				CLR_BIT(RCC_CFGR,20);
				CLR_BIT(RCC_CFGR,21);  
				break;
			} 
			case PLL_CLOCK_MULTIPLE_BY_5  :   // Put 0b0011 in Bits 18:21            
			{
				SET_BIT(RCC_CFGR,18);
				SET_BIT(RCC_CFGR,19);
				CLR_BIT(RCC_CFGR,20);
				CLR_BIT(RCC_CFGR,21);  
				break;
			} 
			case PLL_CLOCK_MULTIPLE_BY_6  :   // Put 0b0100 in Bits 18:21            
			{
				CLR_BIT(RCC_CFGR,18);
				CLR_BIT(RCC_CFGR,19);
				SET_BIT(RCC_CFGR,20);
				CLR_BIT(RCC_CFGR,21);  
				break;
			}
			case PLL_CLOCK_MULTIPLE_BY_7  :   // Put 0b0101 in Bits 18:21           
			{
				SET_BIT(RCC_CFGR,18);
				CLR_BIT(RCC_CFGR,19);
				SET_BIT(RCC_CFGR,20);
				CLR_BIT(RCC_CFGR,21);  
				break;
			}
			case PLL_CLOCK_MULTIPLE_BY_8  :   // Put 0b0110 in Bits 18:21             
			{
				CLR_BIT(RCC_CFGR,18);
				SET_BIT(RCC_CFGR,19);
				SET_BIT(RCC_CFGR,20);
				CLR_BIT(RCC_CFGR,21);  
				break;
			}
			case PLL_CLOCK_MULTIPLE_BY_9  :   // Put 0b0111 in Bits 18:21            
			{
				SET_BIT(RCC_CFGR,18);
				SET_BIT(RCC_CFGR,19);
				SET_BIT(RCC_CFGR,20);
				CLR_BIT(RCC_CFGR,21);  
				break;
			}
			case PLL_CLOCK_MULTIPLE_BY_10 :   // Put 0b1000 in Bits 18:21            
			{
				CLR_BIT(RCC_CFGR,18);
				CLR_BIT(RCC_CFGR,19);
				CLR_BIT(RCC_CFGR,20);
				SET_BIT(RCC_CFGR,21);  
				break;
			}
			case PLL_CLOCK_MULTIPLE_BY_11 :   // Put 0b1001 in Bits 18:21           
			{
				SET_BIT(RCC_CFGR,18);
				CLR_BIT(RCC_CFGR,19);
				CLR_BIT(RCC_CFGR,20);
				SET_BIT(RCC_CFGR,21);  
				break;
			}
			case PLL_CLOCK_MULTIPLE_BY_12 :   // Put 0b1010 in Bits 18:21           
			{
				CLR_BIT(RCC_CFGR,18);
				SET_BIT(RCC_CFGR,19);
				CLR_BIT(RCC_CFGR,20);
				SET_BIT(RCC_CFGR,21);  
				break;
			}
			case PLL_CLOCK_MULTIPLE_BY_13 :   // Put 0b1011 in Bits 18:21            
			{
				SET_BIT(RCC_CFGR,18);
				SET_BIT(RCC_CFGR,19);
				CLR_BIT(RCC_CFGR,20);
				SET_BIT(RCC_CFGR,21);  
				break;
			}
			case PLL_CLOCK_MULTIPLE_BY_14 :   // Put 0b1100 in Bits 18:21           
			{
				CLR_BIT(RCC_CFGR,18);
				CLR_BIT(RCC_CFGR,19);
				SET_BIT(RCC_CFGR,20);
				SET_BIT(RCC_CFGR,21);  
				break;
			}
			case PLL_CLOCK_MULTIPLE_BY_15 :   // Put 0b1101 in Bits 18:21           
			{
				SET_BIT(RCC_CFGR,18);
				CLR_BIT(RCC_CFGR,19);
				SET_BIT(RCC_CFGR,20);
				SET_BIT(RCC_CFGR,21);  
				break;
			}
			case PLL_CLOCK_MULTIPLE_BY_16 :   // Put 0b1110 in Bits 18:21           
			{
				CLR_BIT(RCC_CFGR,18);
				SET_BIT(RCC_CFGR,19);
				SET_BIT(RCC_CFGR,20);
				SET_BIT(RCC_CFGR,21);  
				break;
			}
	   }
	}
}


/************************ Enable Peripherals Clock ************************/

void RCC_voidEnableClock( u8 Copy_u8PeripheralBus , u8 Copy_u8Peripheral )
{
	switch (Copy_u8PeripheralBus)
	{
		case AHB_BUS :
		SET_BIT(RCC_AHBENR, Copy_u8Peripheral);
		break;
		
		case APB1_BUS :
		SET_BIT(RCC_APB1ENR, Copy_u8Peripheral);
		break;
		
		case APB2_BUS :
		SET_BIT(RCC_APB2ENR, Copy_u8Peripheral);
	    break;
	}
	
}

/*************************** Disable Peripherals Clock **********************/

void RCC_voidDisableClock( u8 Copy_u8PeripheralBus , u8 Copy_u8Peripheral )
{
	switch (Copy_u8PeripheralBus)
	{
		case AHB_BUS :
		CLR_BIT(RCC_AHBENR, Copy_u8Peripheral)
		break;
		
		case APB1_BUS :
		CLR_BIT(RCC_APB1ENR, Copy_u8Peripheral)
		break;
		
		case APB2_BUS :
		CLR_BIT(RCC_APB2ENR, Copy_u8Peripheral)
		break;
	}
	
}

