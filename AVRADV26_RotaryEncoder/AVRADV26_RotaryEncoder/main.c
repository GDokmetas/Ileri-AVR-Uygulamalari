/*
 * AVRADV26_RotaryEncoder.c
 *
 * Created: 19.3.2021 11:53:47
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
	int sayac = 0;
	while (1)
	{
		 val_tmp = encoder_oku();
		 char buffer[10];
		 if(val != val_tmp)
		 {
			 if( /*(val==2 && val_tmp==3) ||*/
			 (val==3 && val_tmp==1) ||
			 /*(val==1 && val_tmp==0) ||*/
			 (val==0 && val_tmp==2)
			 )
			 {
				 sayac++;
				 sprintf(buffer,"%i",sayac);
				 uart_string(buffer);
				 uart_string("\n");
			 }
			 else if( /*(val==3 && val_tmp==2) ||*/
			 (val==2 && val_tmp==0) ||
			 /*(val==0 && val_tmp==1) ||*/
			 (val==1 && val_tmp==3)
			 )
			 {
				 sayac--;
				 sprintf(buffer,"%i",sayac);
				 uart_string(buffer);
				 uart_string("\n");
			 }

			 val = val_tmp;
		 }

		 _delay_ms(1);
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
