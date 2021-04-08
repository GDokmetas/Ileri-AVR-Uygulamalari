/*
 * AVRADV12_DS1307.c
 *
 * Created: 1.11.2020 06:59:09
 * Author : PC
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "i2cmaster.h"
#include "uart.h"
#include <avr/interrupt.h>
#define RTC_ADDR (0x68 << 1)
#include <stdint.h>
#include <stdio.h>
int main(void)
{
    sei();
    uart_init(UART_BAUD_SELECT(9600,F_CPU));
    _delay_ms(100);
    i2c_init();
	
	 uint8_t sec;
	 uint8_t min;
	 uint8_t hour;
	 uint8_t weekDay;
	 uint8_t date;
	 uint8_t month;
	 uint8_t year;
	 uart_puts("DS1307 RTC \n");
	 i2c_start(RTC_ADDR+I2C_WRITE);
	 i2c_write(0x07);
	 i2c_write(0x00);
	 i2c_stop();
	 
	 i2c_start(RTC_ADDR+I2C_WRITE);
	 i2c_write(0x00);
	 i2c_stop();
	 
	 i2c_start(RTC_ADDR+I2C_READ);
	 sec = i2c_readAck();
	 min = i2c_readAck();
	 hour = i2c_readAck();
	 weekDay = i2c_readAck();
	 date = i2c_readAck();
	 month = i2c_readAck();
	 year = i2c_readNak();
	 
	 i2c_stop();
	 
	 char buf[30];
	 sprintf(buf,"\n\rSaat:%2x:%2x:%2x  \nTarih:%2x/%2x/%2x",
	 (uint16_t)hour,(uint16_t)min,(uint16_t)sec,(uint16_t)date,(uint16_t)month,(uint16_t)year);
	 
	 uart_puts(buf);
	
    while (1) 
    {
    }
}

