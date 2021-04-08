/*
 * AVRADV36_VCCHesaplama.c
 *
 * Created: 21.3.2021 13:28:07
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdlib.h>
#include "adc.h"
void uart_basla(uint32_t baud);
void uart_gonder(uint8_t uData);
void uart_string(const char *s );

int main(void)
{
	char buffer [10];
	_delay_ms(100);
	uart_basla(9600);
    adc_init();
	
    while (1) 
    {
		ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
		_delay_ms(3); //delay for 3 milliseconds
		ADCSRA |= _BV(ADSC); // Start ADC conversion
		while (bit_is_set(ADCSRA,ADSC)); //wait until conversion is complete
		int result = ADCL; //get first half of result
		result |= ADCH<<8; //get rest of the result
		float vcc_value = (1.1 / result)*1024;
		dtostrf(vcc_value ,7,4,buffer);
		uart_string("OKUMA:");
		uart_string(buffer);
		uart_gonder('\n');
		_delay_ms(400);
    }
}

void uart_basla(uint32_t baud){
	uint16_t baudRate=F_CPU/baud/16-1;
	UBRR0H=(baudRate>>8);
	UBRR0L=baudRate;
	UCSR0B|=(1<<RXEN0)|(1<<TXEN0);
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);
}

void uart_gonder(uint8_t uData){
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0=uData;
}

void uart_string(const char *s )
{
	while (*s)
	uart_gonder(*s++);

}