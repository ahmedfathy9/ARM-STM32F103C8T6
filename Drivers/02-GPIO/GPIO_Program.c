/********************************************************/
/* Author      : Ahmed Fathy Abd El-Qadir	            */
/* Date        : 3/12/2021                              */
/* Version     : V 1.0                                  */
/* uC          : STM32F103C8T6                          */
/********************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case PORTA:
			if (Copy_u8Pin <=7 )
			{
				GPIOA_CRL &= ~((0x1111) << (Copy_u8Pin*4));
				GPIOA_CRL |= (Copy_u8Mode) << (Copy_u8Pin*4);
				if (Copy_u8Mode == GPIO_INPUT_PULLUP_DOWN)
				{
					switch(MODE_OF_PULL)
	                {
						case PULL_UP:
						      SET_BIT(GPIOA_ODR, Copy_u8Pin);
							  break;
						case PULL_DOWN:
				    	      CLR_BIT(GPIOA_ODR, Copy_u8Pin);
							  break;
						default:
							  break;
					}
				}
			}
			else if (Copy_u8Pin <= 15)
			{
				Copy_u8Pin -= 8;
				GPIOA_CRH &= ~((0b1111) << (Copy_u8Pin*4));
				GPIOA_CRH |= (Copy_u8Mode) << (Copy_u8Pin*4);
				if (Copy_u8Mode == GPIO_INPUT_PULLUP_DOWN)
				{
					switch(MODE_OF_PULL)
	                {
						case PULL_UP:
						      SET_BIT(GPIOA_ODR, Copy_u8Pin+8);
							  break;
						case PULL_DOWN:
				    	      CLR_BIT(GPIOA_ODR, Copy_u8Pin+8);
							  break;
						default:
							  break;
					}
				}
			}
			break;
			
		case PORTB:
			if (Copy_u8Pin <= 7)
			{
				GPIOA_CRL &= ~((0b1111) << (Copy_u8Pin*4));
				GPIOA_CRL |= (Copy_u8Mode) << (Copy_u8Pin*4);
				if (Copy_u8Mode == GPIO_INPUT_PULLUP_DOWN)
				{
					switch(MODE_OF_PULL)
	                {
						case PULL_UP:
						      SET_BIT(GPIOB_ODR, Copy_u8Pin);
							  break;
						case PULL_DOWN:
				    	      CLR_BIT(GPIOB_ODR, Copy_u8Pin);
							  break;
						default:
							  break;
					}
				}
			}
			else if (Copy_u8Pin <= 15)
			{
				Copy_u8Pin -= 8;
				GPIOA_CRH &= ~((0b1111) << (Copy_u8Pin*4));
				GPIOA_CRH |= (Copy_u8Mode) << (Copy_u8Pin*4);
				if (Copy_u8Mode == GPIO_INPUT_PULLUP_DOWN)
				{
					switch(MODE_OF_PULL)
	                {
						case PULL_UP:
						      SET_BIT(GPIOB_ODR, Copy_u8Pin+8);
							  break;
						case PULL_DOWN:
				    	      CLR_BIT(GPIOB_ODR, Copy_u8Pin+8);
							  break;
						default:
							  break;
					}
				}
			}
			break;
			
		case PORTC:
			if (Copy_u8Pin <= 7)
			{
				GPIOA_CRL &= ~((0b1111) << (Copy_u8Pin*4));
				GPIOA_CRL |= (Copy_u8Mode) << (Copy_u8Pin*4);
				if (Copy_u8Mode == GPIO_INPUT_PULLUP_DOWN)
				{
					switch(MODE_OF_PULL)
	                {
						case PULL_UP:
						      SET_BIT(GPIOC_ODR, Copy_u8Pin);
							  break;
						case PULL_DOWN:
				    	      CLR_BIT(GPIOC_ODR, Copy_u8Pin);
							  break;
						default:
							  break;
					}
				}
			}
			else if (Copy_u8Pin <= 15)
			{
				Copy_u8Pin -= 8;
				GPIOA_CRH &= ~((0b1111) << (Copy_u8Pin*4));
				GPIOA_CRH |= (Copy_u8Mode) << (Copy_u8Pin*4);
				if (Copy_u8Mode == GPIO_INPUT_PULLUP_DOWN)
				{
					switch(MODE_OF_PULL)
	                {
						case PULL_UP:
						      SET_BIT(GPIOC_ODR, Copy_u8Pin+8);
							  break;
						case PULL_DOWN:
				    	      CLR_BIT(GPIOC_ODR, Copy_u8Pin+8);
							  break;
						default:
							  break;
					}
				}
			}
			break;
			
		default:
		   break;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////

void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Value)
{
	if (Copy_u8Value == HIGH)
	{
    	switch (Copy_u8Port)
		{
			case PORTA:
				GPIOA_BSRR = (1 << Copy_u8Pin);
				/* SET_BIT(GPIOA_ODR, Copy_u8Pin) */
				break;
			case PORTB:
				GPIOB_BSRR = (1 << Copy_u8Pin);
				/* SET_BIT(GPIOB_ODR, Copy_u8Pin) */
				break;
			case PORTC:
				GPIOC_BSRR = (1 << Copy_u8Pin);
				/* SET_BIT(GPIOC_ODR, Copy_u8Pin) */
				break;
			default: 
			    break;
		}
	}
    else if (Copy_u8Value == LOW)
	{
		switch (Copy_u8Port)
		{
			case PORTA:
				GPIOA_BRR	= (1 << Copy_u8Pin);
				/* CLR_BIT(GPIOA_ODR, Copy_u8Pin) */
				/* GPIOA_BSRR = (1 << Copy_u8Pin+16) */
				break;
			case PORTB:
				GPIOB_BRR	= (1 << Copy_u8Pin);
				/* CLR_BIT(GPIOB_ODR, Copy_u8Pin) */
				/* GPIOB_BSRR = (1 << Copy_u8Pin+16) */
				break;
			case PORTC:
				GPIOC_BRR	= (1 << Copy_u8Pin);
				/* CLR_BIT(GPIOC_ODR, Copy_u8Pin) */
				/* GPIOC_BSRR = (1 << Copy_u8Pin+16) */
				break;
			default: 
			    break;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////

u8 GPIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 LOC_u8Result = 0;
	switch (Copy_u8Port)
	{
		case PORTA:
			LOC_u8Result = GET_BIT(GPIOA_IDR, Copy_u8Pin);
			break;
		case PORTB:
			LOC_u8Result = GET_BIT(GPIOB_IDR, Copy_u8Pin);
			break;
		case PORTC:
			LOC_u8Result = GET_BIT(GPIOC_IDR, Copy_u8Pin);
			break;
		default:
     		break;
	}
	return LOC_u8Result;
}
//////////////////////////////////////////////////////////////////////////////////////////////

void GPIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Mode)
{
	u32 LOC1_u32Mode = Copy_u8Mode;  // for CRL register
	u32 LOC2_u32Mode = Copy_u8Mode;  // for CRH register
	
	for (u8 i=0; i<7; i++)
	{
		LOC1_u32Mode = (LOC1_u32Mode << 4);
		LOC1_u32Mode |= Copy_u8Mode;
	}
	for (u8 i=0; i<7; i++)
	{
		LOC2_u32Mode = (LOC2_u32Mode << 4);
		LOC2_u32Mode |= Copy_u8Mode;
	}
	
	switch(Copy_u8Port)
	{
		case PORTA:
			GPIOA_CRL &= 0x0;
			GPIOA_CRH &= 0x0;
			GPIOA_CRL |= LOC1_u32Mode;
			GPIOA_CRH |= LOC2_u32Mode;
			break;
		case PORTB:
			GPIOB_CRL &= 0x0;
			GPIOB_CRH &= 0x0;
			GPIOB_CRL |= LOC1_u32Mode;
			GPIOB_CRH |= LOC2_u32Mode;
			break;
		case PORTC:
			GPIOC_CRL &= 0x0;
			GPIOC_CRH &= 0x0;
			GPIOC_CRL |= LOC1_u32Mode;
			GPIOC_CRH |= LOC2_u32Mode;
			break;
		default: 
		    break;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////

void GPIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	switch (Copy_u8Port)
	{
		case PORTA:
			GPIOA_ODR = Copy_u8Value;
			break;
		case PORTB:
			GPIOB_ODR = Copy_u8Value;
			break;
		case PORTC:
			GPIOC_ODR = Copy_u8Value;
			break;
		default: 
      		break;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////

void GPIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	switch (Copy_u8Port)
	{
		case PORTA:
			/* Sequence 1-0-1-0-1 to bit 16 */
		    SET_BIT(GPIOA_LCKR, 16);
			CLR_BIT(GPIOA_LCKR, 16);
			SET_BIT(GPIOA_LCKR, 16);
			CLR_BIT(GPIOA_LCKR, 16);
			SET_BIT(GPIOA_LCKR, 16);
			/* Lock the pin*/
			SET_BIT(GPIOA_LCKR, Copy_u8Pin);
			break;
		case PORTB:
		    /* Sequence 1-0-1-0-1 to bit 16 */
		    SET_BIT(GPIOB_LCKR, 16);
			CLR_BIT(GPIOB_LCKR, 16);
			SET_BIT(GPIOB_LCKR, 16);
			CLR_BIT(GPIOB_LCKR, 16);
			SET_BIT(GPIOB_LCKR, 16);
			/* Lock the pin*/
			SET_BIT(GPIOB_LCKR, Copy_u8Pin);
			break;
		case PORTC:
			/* Sequence 1-0-1-0-1 to bit 16 */
		    SET_BIT(GPIOC_LCKR, 16);
			CLR_BIT(GPIOC_LCKR, 16);
			SET_BIT(GPIOC_LCKR, 16);
			CLR_BIT(GPIOC_LCKR, 16);
			SET_BIT(GPIOC_LCKR, 16);
			/* Lock the pin*/
			SET_BIT(GPIOC_LCKR, Copy_u8Pin);
			break;
		default: break;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////

void GPIO_voidOpenPin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	switch (Copy_u8Port)
	{
		case PORTA:
			/* Sequence 1-0-1-0-1 to bit 16 */
		    SET_BIT(GPIOA_LCKR, 16);
			CLR_BIT(GPIOA_LCKR, 16);
			SET_BIT(GPIOA_LCKR, 16);
			CLR_BIT(GPIOA_LCKR, 16);
			SET_BIT(GPIOA_LCKR, 16);
			/* Lock the pin*/
			CLR_BIT(GPIOA_LCKR, Copy_u8Pin);
			break;
		case PORTB:
		    /* Sequence 1-0-1-0-1 to bit 16 */
		    SET_BIT(GPIOB_LCKR, 16);
			CLR_BIT(GPIOB_LCKR, 16);
			SET_BIT(GPIOB_LCKR, 16);
			CLR_BIT(GPIOB_LCKR, 16);
			SET_BIT(GPIOB_LCKR, 16);
			/* Lock the pin*/
			CLR_BIT(GPIOB_LCKR, Copy_u8Pin);
			break;
		case PORTC:
			/* Sequence 1-0-1-0-1 to bit 16 */
		    SET_BIT(GPIOC_LCKR, 16);
			CLR_BIT(GPIOC_LCKR, 16);
			SET_BIT(GPIOC_LCKR, 16);
			CLR_BIT(GPIOC_LCKR, 16);
			SET_BIT(GPIOC_LCKR, 16);
			/* Lock the pin*/
			CLR_BIT(GPIOC_LCKR, Copy_u8Pin);
			break;
		default: break;
	}
}