/*
 * AVRADV35_AVRDAC.c
 *
 * Created: 21.3.2021 12:07:47
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    DDRD = 0xFF;
    while (1) 
    {
	for (int i = 0; i < 0b00111111 ; i++)
	{
		PORTD = i << 2;
		_delay_us(1);
	}
}
}

// geliþtiricilecek üçgen dalga ve sinüs dalga eklenecek.