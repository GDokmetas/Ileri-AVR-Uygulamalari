/*
 * AVRADV5_WDT.c
 *
 * Created: 27.10.2020 04:13:47
 * Author : PC
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "wdt.h"

int main(void)
{
	DDRD |= (1<<0);
    sei();
	wdt_prescaler(MS250);
	wdt_on(INTERRUPT);
    while (1) 
    {
    }
}

ISR (WDT_vect)
{
	PORTD ^= (1<<0);
}
