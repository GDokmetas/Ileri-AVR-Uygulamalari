/*
 * AVRADV20_MAX7219Library.c
 *
 * Created: 8.11.2020 11:22:28
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "max7219.h"

int main(void)
{
    max_init();
	max_clear_display();
	max_show32bit(12345678);
    while (1) 
    {
    }
}

