/*
 * AVRADV11_I2CEEPROM_UART.c
 *
 * Created: 1.11.2020 03:03:38
 * Author : PC
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include "i2cmaster.h"
#include "uart.h"
#include "i2c24c32.h"
#include <util/delay.h>
#include <stdio.h>

int main(void)
{
     sei();
     uart_init(UART_BAUD_SELECT(9600,F_CPU));
     _delay_ms(100);
     i2c_init();
	 eeprom_write_16bit(0, 65535);
	 uint16_t okunan_deger = eeprom_read_16bit(0);
	 char buf[15];
	 sprintf(buf,"16-BIT DEGER:%u \n",okunan_deger);
	 uart_puts(buf);
	 eeprom_write_32bit(0, 4294967295);
	 uint32_t okunan_deger2 = eeprom_read_32bit(0);
	 char buf2[15];
	 sprintf(buf2,"32-BIT DEGER:%lu \n",okunan_deger2);
	 uart_puts(buf2);
	 
    while (1) 
    {
    }
}

