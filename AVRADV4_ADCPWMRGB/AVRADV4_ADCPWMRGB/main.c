/*
 * AVRADV4_ADCPWMRGB.c
 *
 * Created: 27.10.2020 00:34:34
 * Author : PC
 */ 

#include <avr/io.h>
#include "adc.h"
#define offset 1000
int main(void)
{
    adc_left_adjust();
	adc_init();
	///////
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
		OCR1A = adc_read(0) - (offset);
		OCR3A = adc_read(2) - (offset);
		OCR4A = adc_read(1) - (offset);
    }
}

