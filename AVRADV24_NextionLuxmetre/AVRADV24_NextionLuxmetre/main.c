/*
 * AVRADV24_NextionLuxmetre.c
 *
 * Created: 10.11.2020 13:57:17
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "i2cmaster.h"
#include "uart.h"
#include <inttypes.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
uint32_t bh1750_oku();
void nextion_komut(char* komut);

int main(void)
{
    i2c_init();
	sei();
	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	_delay_ms(100);
	char buf[20];
	uint32_t lux = 0;
    while (1) 
    {
		lux = bh1750_oku();
		sprintf(buf,"n0.val=%lu", lux);
		nextion_komut(buf);
		
    }
}

uint32_t bh1750_oku()
{
	uint8_t bh1750_addr = (0x23 << 1);
	i2c_rep_start(bh1750_addr+I2C_WRITE);
	i2c_write(0x10);
	i2c_stop();
	_delay_ms(10);
	i2c_rep_start(bh1750_addr+I2C_WRITE);
	i2c_write(0x10);
	i2c_stop();
	_delay_ms(200);
	i2c_start_wait(bh1750_addr+I2C_READ);
	uint16_t okuma = 0;
	okuma = i2c_readAck();
	okuma <<= 8;
	okuma |= i2c_readNak();
	float lux  = okuma / 1.2F;
	return (uint32_t)lux;
}

void nextion_komut(char* komut)
{
	uart_puts(komut);
	uart_putc(0xFF);
	uart_putc(0xFF);
	uart_putc(0xFF);
}