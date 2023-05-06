/*
 * EXTI.h
 *
 * Created: 4/19/2023 2:29:07 AM
 *  Author: osale
 */ 

#include "STD_TYPE.h"
#include "EXTI_Config.h"

#ifndef EXTI_H_
#define EXTI_H_

void EXTI_Init();
void EXTI_enable(uint8 INT_num);
void EXIT_disable(uint8 INT_num);	
void EXTI_Clr_Flag(uint8 INT_num);
uint8 EXTI_Read_Flag(uint8 INT_num);
void EXTI_SetCallBack( void (*CallBack)() , uint8 INT_num);


#endif /* EXTI_H_ */