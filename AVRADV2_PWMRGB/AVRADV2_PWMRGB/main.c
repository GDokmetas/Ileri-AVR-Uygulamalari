/*
 * AVRADV2_PWMRGB.c
 *
 * Created: 26.10.2020 14:55:15
 * Author : PC
 */ 

#include <avr/io.h>
#define  F_CPU 16000000UL
#include <util/delay.h>
void rgb_renk (unsigned int kirmizi, unsigned int yesil, unsigned int mavi);
int main(void)
{
    // PWM Kanallarý Çýkýþ 
	DDRB |= (1<<PORTB1);
	DDRD |= ((1<<PORTD0) | (1<<PORTD1));
	////////
	TCCR1A|=((1<<COM1A1) ); 
	TCCR1B|=(1<<WGM13); 
	TCCR1B|=(1<<CS10);
	ICR1=65535;
	OCR1A=0; 
	/////////////
	TCCR3A|=((1<<COM3A1) ); 
	TCCR3B|=(1<<WGM13); 
	TCCR3B|=(1<<CS10); 
	ICR3=65535; 
	OCR3A=0; 
	/////////////////
	TCCR4A|=((1<<COM4A1) );
	TCCR4B|=(1<<WGM13); 
	TCCR4B|=(1<<CS10); 
	ICR4=65535; 
	OCR4A=0; 
    while (1) 
    {
		rgb_renk(51, 37, 49);
    }
}


void rgb_renk (unsigned int kirmizi, unsigned int yesil, unsigned int mavi)
{
	kirmizi = kirmizi << 8;
	yesil = yesil << 8;
	mavi = mavi << 8;
	// rgb() uyumu
	OCR1A = kirmizi;
	OCR3A = yesil;
	OCR4A = mavi;
}

