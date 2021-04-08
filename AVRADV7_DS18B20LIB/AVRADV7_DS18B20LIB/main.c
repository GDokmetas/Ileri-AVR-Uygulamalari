/*
 * AVRADV7_DS18B20LIB.c
 *
 * Created: 30.10.2020 08:15:29
 * Author : PC
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "ds18S20.h"
#include "uart.h"
#include <stdlib.h>
#include "avr/interrupt.h"
#include <util/delay.h>
char buffer[10];
int main(void)
{
    sei();
    uart_init(UART_BAUD_SELECT(9600,F_CPU));
    _delay_ms(100);
	
	TSDS18x20 DS18x20;
	TSDS18x20 *pDS18x20 = &DS18x20;
	
	if (DS18x20_Init(pDS18x20,&PORTD,PD2))
	{
		uart_puts("Error!!! Can not find 1-Wire device attached on the bus!");
		return -1;
	}
	else
	uart_puts("1-Wire device detected on the bus.");
	uart_putc(0x0D);

	// Set DS18B20 resolution to 9 bits.
	DS18x20_SetResolution(pDS18x20,CONF_RES_9b);
	DS18x20_WriteScratchpad(pDS18x20);
	
	// Initiate a temperature conversion and get the temperature reading
	if (DS18x20_MeasureTemperature(pDS18x20))
	{
		// Send the temperature over serial port
		uart_puts("Current Temperature is: ");
		dtostrf(DS18x20_TemperatureValue(pDS18x20),9,4,buffer);
		uart_puts(buffer);
		uart_putc('C');
		uart_putc(0x0D);
	}
	else
	uart_puts("CRC error!!!");
    while (1) 
    {
		if (DS18x20_MeasureTemperature(pDS18x20))
		{
			// Send the temperature over serial port
			uart_puts("Current Temperature is: ");
			dtostrf(DS18x20_TemperatureValue(pDS18x20),9,4,buffer);
			uart_puts(buffer);
			uart_putc('C');
			uart_putc(0x0D);
			uart_putc('\n');
		}
    }
}

