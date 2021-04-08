/*
 * AVRADV15_DS3231LIBRARY.c
 *
 * Created: 4.11.2020 12:23:36
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "uart.h"
#include "i2cmaster.h"
#include "ds3231.h"
#include <stdio.h>
int main(void)
{
    sei();
    uart_init(UART_BAUD_SELECT(9600,F_CPU));
    _delay_ms(100);
    i2c_init();
	char buf[20];
	uint8_t sec = 0, min = 0, hour = 0;
	uint8_t date = 0, month = 0, year = 0;
	write_min(50);
	write_hour(20);
	write_date(6);
	write_month(6);
	write_year(6);
    while (1) 
    {
	sec = read_sec();
	min = read_min();
	hour = read_hour();
	sprintf(buf, "%u:%u:%u \n", hour, min, sec);
	uart_puts(buf);
	date = read_date();
	month = read_month();
	year = read_year();
	sprintf(buf, "%u / %u / %u \n", date, month, year);
	uart_puts(buf);
	_delay_ms(300);
    }
}

