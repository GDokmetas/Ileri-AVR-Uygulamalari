/*
 * AVDADV30_BitfieldArduino.c
 *
 * Created: 20.3.2021 07:52:13
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include "bitfieldarduino.h"

int main(void)
{
	// Düðmeler
    D2_pinMode = INPUT;
	D3_pinMode = INPUT;
	D2_pullUp = PULL_UP;
	D3_pullUp = PULL_UP;
	// Ledler
	D4_pinMode = OUTPUT;
	D5_pinMode = OUTPUT;
    while (1) 
    {
	   D4_digitalWrite = !D2_digitalRead;
	   D5_digitalWrite = !D3_digitalRead;
    }
}

