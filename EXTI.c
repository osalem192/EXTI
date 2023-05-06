/*
 * EXTI.c
 *
 * Created: 4/19/2023 2:09:23 AM
 *  Author: osale
 */ 

#include "ATmega32_Regs.h"
#include "BIT_MATH.h"
#include "EXTI_Config.h"
#include "STD_TYPE.h"
#include "GPIO_DRIVER.h"

void (*EXTI_CallBack[3]) (void) = {0} ; 


void EXTI_Init()
{
	#if defined EXTI
		
		#if EXTI == INT0
			#if SENSE_MODE == LOW_LEVEL 
				ClrBit(MCUCR,0); ClrBit(MCUCR,1);
			#elif SENSE_MODE == ANY_CHANGE
				SetBit(MCUCR,0); ClrBit(MCUCR,0);
			#elif SENSE_MODE == FALLING_EDGE
				SetBit(MCUCR,1); ClrBit(MCUCR,0);	
			#elif SENSE_MODE == RISING_EDGE
				SetBit(MCUCR,0); SetBit(MCUCR,1);
		#endif
		
		#elif EXTI == INT1
			#if SENSE_MODE == LOW_LEVEL 
				ClrBit(MCUCR,2); ClrBit(MCUCR,3);
			#elif SENSE_MODE == ANY_CHANGE
				SetBit(MCUCR,2); ClrBit(MCUCR,2);
			#elif SENSE_MODE == FALLING_EDGE
				SetBit(MCUCR,3); ClrBit(MCUCR,2);	
			#elif SENSE_MODE == RISING_EDGE
				SetBit(MCUCR,2); SetBit(MCUCR,3);
		#endif
		
		#elif EXTI == INT2
			#if SENSE_MODE == FALLING_EDGE
				ClrBit(MCUCSR,6);	
			#elif SENSE_MODE == RISING_EDGE
				SetBit(MCUCSR,6);
		#endif		
		#endif
		#else 
			#error "Wrong SENSE CONFIGURATION"
	#endif						
}

void EXTI_enable(uint8 INT_num)
{
	SetBit(SREG,7);
	SetBit(GICR, INT_num);
}

void EXIT_disable(uint8 INT_num)
{
	ClrBit(SREG,7);
	ClrBit(GICR, INT_num);
}

void EXTI_Clr_Flag(uint8 INT_num)
{
	SetBit(GIFR,INT_num);
}

uint8 EXTI_Read_Flag(uint8 INT_num)
{
	ReadBit(GIFR,INT_num);
}

void EXTI_SetCallBack( void (*CallBack)() , uint8 INT_num)
{
		if (CallBack != 0) EXTI_CallBack[INT_num] = CallBack;
}

void __vector_1(void) __attribute__((signal));		//ISR for INT0
void __vector_1(void)
{
	if (EXTI_CallBack[0] != 0)
	{
		EXTI_CallBack[0]();
		EXTI_Clr_Flag(INT0);
	}
} 

void __vector_2(void) __attribute__((signal));		//ISR for INT1
void __vector_2(void)
{
	if (EXTI_CallBack[1] != 0)
	{
		EXTI_CallBack[1]();
		EXTI_Clr_Flag(INT1);
	}
}

void __vector_3(void) __attribute__((signal));		//ISR for INT2
void __vector_3(void)
{
	if (EXTI_CallBack[2] != 0)
	{
		EXTI_CallBack[2]();
		EXTI_Clr_Flag(INT2);
	}
}


