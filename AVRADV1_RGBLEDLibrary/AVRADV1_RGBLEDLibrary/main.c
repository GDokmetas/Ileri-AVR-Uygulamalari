/*
 * AVRADV1_RGBLEDLibrary.c
 *
 * Created: 26.10.2020 06:50:09
 * Author : PC
 */ 

#include <avr/io.h>
#include "rgbled.h"
#define  F_CPU 16000000UL
#include <util/delay.h>
#define bekleme 500

int main(void)
{
    led_init();
		led_yak(KIRMIZI);
		_delay_ms(bekleme);
		led_yak(YESIL);
		_delay_ms(bekleme);
		led_yak(MAVI);
		_delay_ms(bekleme);
		led_yak(BEYAZ);
		_delay_ms(bekleme);
	DDRC &= ~((1<<PORTC2) | (1<<PORTC3));
	PORTC |= ((1<<PORTC2) | (1<<PORTC3));
	int renk = 0;
    while (1) 
    {
		if (!(PINC & (1<<PORTC2)))
		{
			_delay_ms(200);
			renk++;
			if (renk>6)
		    renk = 6;
			led_yak(renk);
		}
		if (!(PINC & (1<<PORTC3)))
		{
			_delay_ms(200);
			renk--;
			if (renk < 0)
			renk = 0;
			led_yak(renk);
		}
		
    }
}

