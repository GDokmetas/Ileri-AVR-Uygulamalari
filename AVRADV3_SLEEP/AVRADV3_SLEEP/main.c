/*
 * AVRADV3_SLEEP.c
 *
 * Created: 26.10.2020 23:20:09
 * Author : PC
 */ 

#include <avr/io.h>
#include "rgbled.h"
#include "sleep.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
int renk = 0; 

int main(void)
{
	EIMSK |= (1<<INT0);
	PORTD |= (1<<PORTD2);
	sei();
    led_init();
	led_yak(KIRMIZI);
	sleep(IDLE);
	led_yak(YESIL);
    while (1) 
    {
	    renk++;
		led_yak(renk);
		if (renk > 6)
		renk = 0;
		_delay_ms(200);	
    }
}

ISR (INT0_vect)
{
	   
}


