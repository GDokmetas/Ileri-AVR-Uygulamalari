/*
 * AVRADV27_RotaryEncoderNextion.c
 *
 * Created: 20.3.2021 05:51:04
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
	unsigned char val=0, val_tmp =0;
	DDRD &=~ (1 << PD2);
	DDRD &=~ (1 << PD3);
	PORTD |= (1<<PD2);
	PORTD |= (1<<PD3);
	uart_basla(9600);
	val = encoder_oku();
	sei();
	int sayac = 325;
	int eski_sayac = sayac;
	nextion_komut("page 0");
	int ibre_pozitif = 0;
	while (1)
	{
		val_tmp = encoder_oku();
		char buffer[30];
		if(val != val_tmp)
		{
			if( /*(val==2 && val_tmp==3) ||*/
			(val==3 && val_tmp==1) ||
			/*(val==1 && val_tmp==0) ||*/
			(val==0 && val_tmp==2)
			)
			{
				sayac++;
			}
			else if( /*(val==3 && val_tmp==2) ||*/
			(val==2 && val_tmp==0) ||
			/*(val==0 && val_tmp==1) ||*/
			(val==1 && val_tmp==3)
			)
			{
				sayac--;
			}

			val = val_tmp;
		}
		
        /// ENCODER OKUMA /////////////////////////
		if (sayac > 360)
		{
		ibre_pozitif = 1;
		sayac = 0;
		}
		if (sayac < 0)
		{
		sayac = 360;
		ibre_pozitif = 0;
		}
		
		if (sayac > 220 && ibre_pozitif)
		sayac = 220;
	    if (sayac < 325 && !ibre_pozitif)
		sayac = 325;
		// Ýbreye göre sayaç deðiþkenini sýnýrladýk
		if ( sayac != eski_sayac)  // Ekranda titremeyi önlemek için sürekli güncellemeyi engelledik.
		{
		sprintf(buffer,"z0.val=%i", sayac);
		nextion_komut(buffer);
		eski_sayac = sayac;	
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

unsigned char encoder_oku(void )
{
	unsigned char val=0;

	if(!bit_is_clear(PIND, PD2))
	val |= (1<<1);

	if(!bit_is_clear(PIND, PD3))
	val |= (1<<0);

	return val;
}

void nextion_komut(char* komut)
{
	uart_string(komut);
	uart_gonder(0xFF);
	uart_gonder(0xFF);
	uart_gonder(0xFF);
}