/*
 * max7219.c
 *
 * Created: 8.11.2020 11:23:31
 *  Author: GDokmetas
 */ 
#include "max7219.h"
#include <avr/io.h>
#include "spi.h"


void max_init()
{
	spi_init(MASTER);
	max_send_byte(0x09, 0xFF);
	max_send_byte(0x0B, 7);
	max_send_byte(0x0A, 0x00); // PARLAKLIK
	max_send_byte(0x0C, 1);  // A�-KAPA
	max_clear_display();
}

void max_send_byte(uint8_t addr,uint8_t data)
{
	
	PORTB &=~(1<<PORTB2);  // CS 10
	spi_transceive(addr);
	spi_transceive(data);
	PORTB |= (1<<PORTB2);
}

void max_clear_display()
{
	char i = 8;
	
	do {
		max_send_byte(i, 0xF);
	} while (--i);
}

void max_digit(uint8_t digit, uint8_t value)
{
	max_send_byte(digit, value);
}

void max_show32bit(uint32_t number)
{
	max_clear_display();
	max_digit(1, number % 10);
	max_digit(2, (number / 10) % 10);
	max_digit(3, (number / 100) % 10);
	max_digit(4, (number / 1000) % 10);
	max_digit(5, (number / 10000) % 10);
	max_digit(6, (number / 100000) % 10);
	max_digit(7, (number / 1000000) % 10);
	max_digit(8, (number / 10000000) % 10);
}
