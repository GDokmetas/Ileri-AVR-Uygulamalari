/*
 * AVRADV28_NextionDim.c
 *
 * Created: 20.3.2021 06:56:37
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define  F_CPU 16000000UL
#include <util/delay.h>
#include <stdio.h>
#define BAUD 9600
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)
void uart_basla(uint32_t baud);
void uart_gonder(uint8_t data);
void uart_string(const char *s );
unsigned char encoder_oku(void );
void nextion_komut(char* komut);
//-------------------------------------------------------
int main(void)
{
	
	uart_basla(9600);
	
	nextion_komut("page 0");
	char buffer[30];
	while (1)
	{
	    for (int i = 0; i < 100; i++)
		{
		sprintf(buffer,"dim=%i", i);
		nextion_komut(buffer);	
		_delay_ms(20);
		}
		
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

void nextion_komut(char* komut)
{
	uart_string(komut);
	uart_gonder(0xFF);
	uart_gonder(0xFF);
	uart_gonder(0xFF);
}

