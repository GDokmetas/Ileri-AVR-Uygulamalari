/*
 * wdt.c
 *
 * Created: 27.10.2020 04:14:10
 *  Author: PC
 */ 
#include "wdt.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void wdt_off(void)
{
	
	cli();
	asm("WDR");
	MCUSR &= ~(1<<WDRF);
	WDTCSR |= ((1<<WDCE)|(1<<WDE));
	WDTCSR = 0x00;
	sei();
}

void wdt_prescaler(int value)
{
	cli();
	asm("WDR");
	WDTCSR |= (1<<WDCE) |(1<<WDE);
	WDTCSR = (1<<WDE) | (value);
	sei();
}

void wdt_on(int mode)
{
	switch(mode)
	{
		case INTERRUPT:
		WDTCSR |= (1<<WDIE);
		break;
		case RESET:
		WDTCSR |= (1<<WDE);
		break;
		case INTERRUPT_RESET:
		WDTCSR |= (1<<WDIE) | (1<<WDE);
		break;
	}
}