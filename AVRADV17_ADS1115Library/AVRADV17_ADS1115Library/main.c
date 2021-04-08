/*
 * AVRADV17_ADS1115Library.c
 *
 * Created: 6.11.2020 08:57:11
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
#define ADS1115_ADDR 0x48
#include "ads1115.h"
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
		uint16_t adc_deger = ads1115_readADC_SingleEnded(ADS1115_ADDR, 0, DATARATE_8SPS, ADS1115_PGA_6_144);
		sprintf(buf, "ADC DEGER: %u \n", adc_deger);
		uart_puts(buf);
		_delay_ms(200);
	}
}
