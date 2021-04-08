/*
 * AVRADV18_BH1750.c
 *
 * Created: 6.11.2020 13:35:18
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define  F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdio.h>
#include "uart.h"
#include "i2cmaster.h"
#define BH17150_ADDR (0x23 << 1)
int main(void)
{
	uint16_t okuma = 0;
	sei();
	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	_delay_ms(100);
	i2c_init();
	i2c_rep_start(BH17150_ADDR+I2C_WRITE);
	i2c_write(0x10);
	i2c_stop();
	_delay_ms(10);
	i2c_rep_start(BH17150_ADDR+I2C_WRITE);
	i2c_write(0x10);
	i2c_stop();
	_delay_ms(200);
	i2c_start_wait(BH17150_ADDR+I2C_READ);
	
	okuma = i2c_readAck();
	okuma <<= 8;
	okuma |= i2c_readNak();
	float lux  = okuma / 1.2F;
	//////////
	char buf[20];
	sprintf(buf, "OKUMA : %u", (unsigned int)lux);
	uart_puts(buf);
	while (1)
	{

	}
}
