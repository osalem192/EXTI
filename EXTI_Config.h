/*
 * EXTI_Config.h
 *
 * Created: 4/19/2023 2:36:07 AM
 *  Author: osale
 */ 


#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> changeable Config <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#define EXTI INT0
#define SENSE_MODE  LOW_LEVEL
// #define SENSE_MODE  ANY_CHANGE
// #define SENSE_MODE  FALLING_EDGE
//#define SENSE_MODE  RISING_EDGE 

#define FALLING_EDGE  0
#define RISING_EDGE   1
#define LOW_LEVEL     2
#define ANY_CHANGE    3

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Non-changeable Config <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#define INT0 6
#define INT1 7
#define INT2 5


#endif /* EXTI_CONFIG_H_ */