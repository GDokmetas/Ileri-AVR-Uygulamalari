/*
 * AVRADV20_MAX7219MATRIX.c
 *
 * Created: 8.11.2020 08:33:35
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include "spi.h"
#define F_CPU 16000000UL
#include <util/delay.h>
void max_send_byte(uint8_t addr, uint8_t data);
void max_init();
void max_clear_display();
void max_digit(uint8_t digit, uint8_t value);
int main(void)
{
    spi_init(MASTER);
	max_init();
	_delay_ms(100);
	int deger = 0;
    while (1) 
    {
	deger++;
	if(deger > 999) 
	deger = 0;
	max_digit(1, deger % 10);
	max_digit(2, (deger / 10) % 10);
	max_digit(3, deger / 100);	
	_delay_ms(250);
	max_clear_display();
	}
    
}

void max_init()
{
		max_send_byte(0x09, 0xFF);
		max_send_byte(0x0B, 7); 
		max_send_byte(0x0A, 0x00); // PARLAKLIK
		max_send_byte(0x0C, 1);  // AÇ-KAPA
		max_clear_display();
}

 void max_send_byte(uint8_t addr,uint8_t data)
 {
	 
	 PORTB &=~(1<<PORTB2);
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