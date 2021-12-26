/********************************************************/
/* Author      : Ahmed Fathy Abd El-Qadir	            */
/* Date        : 3/12/2021                              */
/* Version     : V 1.0                                  */
/* uC          : STM32F103C8T6                          */
/********************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define GPIOA_Address 0x40010800   // statr of boundary address for PORTA
#define GPIOB_Address 0x40010C00   // statr of boundary address for PORTB
#define GPIOC_Address 0x40011000   // statr of boundary address for PORTC

/************* Register Adress For Port A ************/
#define GPIOA_CRL         *((u32*)GPIOA_Address + 0x00)  
#define GPIOA_CRH         *((u32*)GPIOA_Address + 0x04)  
#define GPIOA_IDR         *((u32*)GPIOA_Address + 0x08)
#define GPIOA_ODR         *((u32*)GPIOA_Address + 0x0C)
#define GPIOA_BSRR        *((u32*)GPIOA_Address + 0x10)
#define GPIOA_BRR         *((u32*)GPIOA_Address + 0x14)  
#define GPIOA_LCKR        *((u32*)GPIOA_Address + 0x18) 

/************* Register Adress For Port B ************/
#define GPIOB_CHL         *((u32*)GPIOB_Address + 0x00)  
#define GPIOB_CHH         *((u32*)GPIOB_Address + 0x04)  
#define GPIOB_IDR         *((u32*)GPIOB_Address + 0x08)
#define GPIOB_ODR         *((u32*)GPIOB_Address + 0x0C)
#define GPIOB_BSRR        *((u32*)GPIOB_Address + 0x10)
#define GPIOB_BRR         *((u32*)GPIOB_Address + 0x14)  
#define GPIOB_LCKR        *((u32*)GPIOB_Address + 0x18) 

/************* Register Adress For Port C ************/
#define GPIOC_CHL         *((u32*)GPIOC_Address + 0x00)  
#define GPIOC_CHH         *((u32*)GPIOC_Address + 0x04)  
#define GPIOC_IDR         *((u32*)GPIOC_Address + 0x08)
#define GPIOC_ODR         *((u32*)GPIOC_Address + 0x0C)
#define GPIOC_BSRR        *((u32*)GPIOC_Address + 0x10)
#define GPIOC_BRR         *((u32*)GPIOC_Address + 0x14)  
#define GPIOC_LCKR        *((u32*)GPIOC_Address + 0x18) 


#endif  