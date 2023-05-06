/*
 * ATmega32_Regs.h
 *
 * Created: 2/8/2023 3:28:12 PM
 *  Author: omar salem
 */ 


#ifndef ATMEGA32_REGS_H_
#define ATMEGA32_REGS_H_

#define MYPORTA *((volatile unsigned char *)(0x3b))
#define MYPORTB *((volatile unsigned char *)(0x38))
#define MYPORTC *((volatile unsigned char *)(0x35))
#define MYPORTD *((volatile unsigned char *)(0x32))
#define MYDDRA  *((volatile unsigned  char *)(0x3a))
#define MYDDRB  *((volatile unsigned  char *)(0x37))
#define MYDDRC  *((volatile unsigned  char *)(0x34))
#define MYDDRD  *((volatile unsigned  char *)(0x31))
#define MYPINA  *((volatile unsigned  char *)(0x39))
#define MYPINB  *((volatile unsigned  char *)(0x36))
#define MYPINC  *((volatile unsigned  char *)(0x33))
#define MYPIND  *((volatile unsigned  char *)(0x30))
#define SFIOR	*((volatile unsigned  char *)(0x50))
#define MCUCR	*((volatile unsigned  char *)(0x55))
#define MCUCSR	*((volatile unsigned  char *)(0x54))
#define GICR	*((volatile unsigned  char *)(0x5B))
#define GIFR	*((volatile unsigned  char *)(0x5A))
#define SREG	*((volatile unsigned  char *)(0x5F))
#endif /* ATMEGA32_REGS_H_ */