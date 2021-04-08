/*
 * AVRADV21_MAX7219ADC.c
 *
 * Created: 8.11.2020 12:20:15
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define  F_CPU 16000000UL
#include "max7219.h"
#include "adc.h"
#include <stdint.h>
#include <util/delay.h>
int main(void)
{
    adc_init();
	max_init();
    while (1) 
    {
		max_show32bit((uint32_t)adc_read_smooth(0));
		_delay_ms(100);
    }
}

