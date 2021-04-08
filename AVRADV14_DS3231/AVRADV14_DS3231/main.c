/*
 * AVRADV14_DS3231.c
 *
 * Created: 2.11.2020 14:44:19
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include "i2cmaster.h"
#define DS3231_ADDR (0x68 << 1)
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "uart.h"
#include <stdio.h>
unsigned char saniye_oku();
int main(void)
{
	sei();
	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	_delay_ms(100);
    i2c_init();
	char buf [10];
    while (1) 
    {
		sprintf(buf,"SANIYE:%u \n",saniye_oku());
		uart_puts(buf);
    }
}

unsigned char saniye_oku()
{
	i2c_start(DS3231_ADDR+I2C_WRITE);
	i2c_write(0x00);
	i2c_stop();
	i2c_start(DS3231_ADDR+I2C_READ);
	unsigned char data = i2c_readNak();
	i2c_stop();
	unsigned char sec = data & 0b00001111;
	unsigned char secx10 = ((data & 0b01110000) >> 4);
	sec += secx10 * 10;
	return sec;
}