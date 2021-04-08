/*
 * sleep.c
 *
 * Created: 26.10.2020 23:20:35
 *  Author: PC
 */ 
#include "sleep.h"
#include <avr/io.h>
void sleep(int mode)
{
	SMCR = mode;
	SMCR |= (1<<SE);
	asm("SLEEP");
}

void bod_disable_sleep()
 {
	 MCUCR |= ((1<<BODS) | (1<<BODSE));
	 MCUCR |= ((1<<BODS));
	 MCUCR &= ~(1<<BODSE);
	 asm("SLEEP");
 }
 
 void sleep_mode(int mode)
 {
	 SMCR = mode;
	 SMCR |= (1<<SE);
 }