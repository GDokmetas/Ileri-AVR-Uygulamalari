/*
 * AVRI2CLCD.c
 *
 * Created: 29.6.2020 09:35:53
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include <avr/pgmspace.h>
#define F_CPU 16000000UL
#include "lcd1602.h"

int main(void)
{
    lcd1602_init();
	lcd1602_clear();
	lcd1602_send_string("MERHABA");
	lcd1602_goto_xy(0,1);
	lcd1602_send_string("DUNYA");
    while (1) 
    {

    }
}

