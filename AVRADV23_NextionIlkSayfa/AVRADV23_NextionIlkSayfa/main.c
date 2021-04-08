/*
 * AVRADV23_NextionIlkSayfa.c
 *
 * Created: 10.11.2020 12:16:39
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define  F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"
int main(void)
{
	sei();
	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	_delay_ms(100);
	uart_puts("page 0");
	uart_putc(0xFF);
	uart_putc(0xFF);
	uart_putc(0xFF);
	while (1)
	{

	}
}



