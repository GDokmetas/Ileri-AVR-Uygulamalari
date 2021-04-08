/*
 * AVRADV10_24C32EEPROM.c
 *
 * Created: 31.10.2020 11:53:38
 * Author : PC
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include "i2cmaster.h"
#include "uart.h"
#include <util/delay.h>
#define EEPROM_ADDR (0x50 << 1)
int main(void)
{
	 unsigned char veri;
     sei();
     uart_init(UART_BAUD_SELECT(9600,F_CPU));
     _delay_ms(100);
	 i2c_init();
	 i2c_start_wait(EEPROM_ADDR+I2C_WRITE);
	 i2c_write(0x00);
	 i2c_write(0x00);
	 i2c_write('A');
	 i2c_stop();
	 i2c_start_wait(EEPROM_ADDR+I2C_WRITE);
	 i2c_write(0x00);
	 i2c_write(0x00);
	 i2c_rep_start(EEPROM_ADDR+I2C_READ); 
	 veri = i2c_readNak(); 
	 i2c_stop();
	 uart_puts("OKUNAN VERI:");
	 uart_putc(veri);
	 uart_putc('\n');
	 
    while (1) 
    {
    }
}

