/*
 * AVRADV37_ZeroCrossDetector.c
 *
 * Created: 22.3.2021 08:37:40
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"
#include <stdio.h>
#define F_CPU 16000000UL
unsigned long zero_cross, okuma;
#include <util/delay.h>
char buf[25];
int main(void)
{
	EICRA |= (1<<ISC01);
    EIMSK |= (1<<INT0); 	
	TCCR1A = 0; 
	TCCR1B = 0; 
	TCNT1  = 0; 
	OCR1A = 62499; 
	TCCR1B |= (1 << WGM12);
	TCCR1B |= (1 << CS12) | (0 << CS11) | (0 << CS10);
	TIMSK1 |= (1 << OCIE1A);
	_delay_ms(100);
	sei();
	uart_init(UART_BAUD_SELECT(9600,F_CPU));

    while (1) 
    {

    }
}

ISR(TIMER1_COMPA_vect)
{
	okuma = zero_cross;
	zero_cross = 0;
	sprintf(buf,"Zero-Cross/s : %ld \n", okuma );
	uart_puts(buf);
}

ISR(INT0_vect)
{
	
	char temp;
    for (temp= 0;temp< 10;)        
    	{
	if(!(PIND & (1<<PD2)))
          temp++;
        else
          temp = 0;          
        }                           
        if(temp != 0)
          {
            
          zero_cross++;
          }
		  
}
