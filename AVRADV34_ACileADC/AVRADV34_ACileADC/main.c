/*
 * AVRADV34_ACileADC.c
 *
 * Created: 21.3.2021 09:39:07
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include "bitfieldarduino.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "uart.h"
void adc_oku();
unsigned int analog_deger;
int main(void)
{
    D2_dir = OUTPUT;
	D2_out = HIGH;
	ACSR |= (1<<ACIE);
	ACSR |= (1<<ACIS1); // interrupt falling
	sei();
	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	char buf[25];
	_delay_ms(100);

    while (1) 
    {
	adc_oku();
	_delay_us(1000);
	sprintf(buf, "Analog Deger:%i \n", analog_deger);
	uart_puts(buf);
    }
}

void adc_oku()
	{
		D2_out = LOW; // Deþarj
		TCCR1B |= (1<<CS10); // Zamanlayýcýyý baþlat kesme bekle
	}
	
ISR(ANALOG_COMP_vect)
	{
		analog_deger = TCNT1; 
		TCCR1B &=~(1<<CS10);
		TCNT1 = 0;
		D2_out = HIGH; // Þarj Et
		_delay_us(1000);
	}