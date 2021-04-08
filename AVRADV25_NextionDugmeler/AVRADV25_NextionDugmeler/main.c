/*
 * AVRADV25_NextionDugmeler.c
 *
 * Created: 10.11.2020 14:48:34
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "uart.h"
#include <inttypes.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
void nextion_komut(char* komut);
int main(void)
{
    sei();
    uart_init(UART_BAUD_SELECT(9600,F_CPU));
    _delay_ms(100);
	nextion_komut("page 0");
	 while (1)
	 {
		 char buf [20];
		 if (uart_available() > 0)
		 {
			 int i = 0;
			 
			 while(1)
			 {
				 
				 buf[i] = uart_getc();
				 if (buf[i] == '\n')
				 break;
				 if (buf[i] == '\0')
				 break;
				 if (buf[i] == '\r')
				 break;
				 i++;
				 if (i>19)
				 i = 0;
			 }
		 }
	char* karakter_kontrol = strchr(buf,'1');
	if (karakter_kontrol != 0)
	{
		nextion_komut("t0.txt=\"1. Dugmeye Basildi\"");
	}
	
	
	karakter_kontrol = 0;
	karakter_kontrol = strchr(buf,'2');
	if (karakter_kontrol != 0)
	{
		nextion_komut("t0.txt=\"2. Dugmeye Basildi\"");
	}
	
	
	karakter_kontrol = 0;
	karakter_kontrol = strchr(buf,'3');
	if (karakter_kontrol != 0)
	{
		nextion_komut("t0.txt=\"3. Dugmeye Basildi\"");
	}
	
	
	karakter_kontrol = 0;
	karakter_kontrol = strchr(buf,'4');
	if (karakter_kontrol != 0)
	{
		nextion_komut("t0.txt=\"4. Dugmeye Basildi\"");
	}	 
	 
  }	
}
		
	
		




void nextion_komut(char* komut)
{
	uart_puts(komut);
	uart_putc(0xFF);
	uart_putc(0xFF);
	uart_putc(0xFF);
}

