/*
 * AVRADV13_DS1307Write.c
 *
 * Created: 1.11.2020 11:34:37
 * Author : PC
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "i2cmaster.h"
#include <avr/interrupt.h>
#define RTC_ADDR (0x68 << 1)
#include <stdint.h>

int main(void)
{
     sei();
     _delay_ms(100);
     i2c_init();
	 uint8_t secx10=0;
	 uint8_t sec = 0;
	 uint8_t minx10=3;
	 uint8_t min = -3;
	 uint8_t hour = 9;
	 uint8_t hourx10 = 1;
	 uint8_t weekDay = 0;
	 uint8_t date = 1;
	 uint8_t datex10=0;
	 uint8_t month = 1;
	 uint8_t monthx10 = 1;
	 uint8_t year = 0;
	 uint8_t yearx10 = 2;
	 
	 i2c_start(RTC_ADDR+I2C_WRITE);
	 i2c_write(0x07);
	 i2c_write(0x00);
	 i2c_stop();
	 
	 i2c_start(RTC_ADDR+I2C_WRITE);
	 i2c_write(0x00);
	 i2c_write(((secx10<<4) | sec));
	 i2c_write(((minx10<<4) | min));
	 i2c_write(((hourx10<<4) | hour));
	 i2c_write(weekDay);
	 i2c_write(((datex10<<4) | date));
	 i2c_write(((monthx10<<4) | month));
	 i2c_write(((yearx10<<4) | year));
	 i2c_stop();
	 
    while (1) 
    {
    }
}

