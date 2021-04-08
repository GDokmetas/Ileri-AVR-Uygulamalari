/*
 * AVRADV16_AD1115.c
 *
 * Created: 6.11.2020 08:27:20
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
#define ADS1115_ADDR (0x48 << 1)
uint16_t ads1115_oku();
int main(void)
{
    sei();
    uart_init(UART_BAUD_SELECT(9600,F_CPU));
    _delay_ms(100);
    i2c_init();
	//////////
	char buf[20];
    while (1) 
    {
	uint16_t adc_deger = ads1115_oku();
	sprintf(buf, "ADC DEGER: %u \n", adc_deger);
	uart_puts(buf);
	_delay_ms(200);	
    }
}

uint16_t ads1115_oku()
{
	i2c_start_wait(ADS1115_ADDR+I2C_WRITE);
	i2c_write(0x01);
	i2c_write(0b10000000);
    i2c_write(0x00);
	_delay_ms(8);
	i2c_start_wait(ADS1115_ADDR+I2C_WRITE);
	i2c_write(0x00);
	i2c_stop();
	i2c_rep_start(ADS1115_ADDR+I2C_READ);
	uint8_t msb = i2c_readAck();
	uint8_t lsb = i2c_readNak();
	uint16_t data = (msb << 8 | lsb);
	return data;
	
}