/*
 * ds3231.c
 *
 * Created: 4.11.2020 12:24:24
 *  Author: GDokmetas
 */ 
#include "ds3231.h"
#include "i2cmaster.h"
#include <avr/io.h>
uint8_t read_sec()
{
	i2c_start(DS3231_ADDR+I2C_WRITE);
	i2c_write(0x00);
	i2c_stop();
	i2c_start(DS3231_ADDR+I2C_READ);
	unsigned char data = i2c_readNak();
	i2c_stop();
	unsigned char sec = data & 0b00001111;
	unsigned char secx10 = ((data & 0b01110000) >> 4);
	sec += secx10 * 10;
	return sec;
}

uint8_t read_min()
{
	i2c_start(DS3231_ADDR+I2C_WRITE);
	i2c_write(0x01);
	i2c_stop();
	i2c_start(DS3231_ADDR+I2C_READ);
	unsigned char data = i2c_readNak();
	i2c_stop();
	unsigned char min = data & 0b00001111;
	unsigned char minx10 = ((data & 0b01110000) >> 4);
	min += minx10 * 10;
	return min;
}

uint8_t read_hour()
{
	i2c_start(DS3231_ADDR+I2C_WRITE);
	i2c_write(0x02);
	i2c_stop();
	i2c_start(DS3231_ADDR+I2C_READ);
	unsigned char data = i2c_readNak();
	i2c_stop();
	unsigned char hour = data & 0b00001111;
	unsigned char hourx10 = ((data & 0b00010000) >> 4);
	unsigned char hourx20 = ((data & 0b00100000) >> 5);
	hour += (hourx10 * 10) + (hourx20 * 20);
	return hour;
}

void write_sec(uint8_t sec)
{
	uint8_t secx1 = sec % 10; 
	uint8_t secx10 = sec / 10;
	uint8_t data = (secx10 << 4) | (secx1);
	i2c_start(DS3231_ADDR+I2C_WRITE);
	i2c_write(0x00);
	i2c_write(data);
	i2c_stop();
}

void write_min(uint8_t min)
{
	uint8_t minx1 = min % 10;
	uint8_t minx10 = min / 10;
	uint8_t data = (minx10 << 4) | (minx1);
	i2c_start(DS3231_ADDR+I2C_WRITE);
	i2c_write(0x01);
	i2c_write(data);
	i2c_stop();
}

void write_hour(uint8_t hour)
{

	uint8_t hourx1 = hour % 10;
	uint8_t hourx10 = hour / 10;
	uint8_t data;
	if (hourx10 == 2)
	{
    data = (1<<5);
	}
	if(hourx10 == 1)
	{
    data = (1<<4);
	}
	data |= hourx1;
	i2c_start(DS3231_ADDR+I2C_WRITE);
	i2c_write(0x02);
	i2c_write(data);
	i2c_stop();
}

uint8_t read_date()
{
	i2c_start(DS3231_ADDR+I2C_WRITE);
	i2c_write(0x04);
	i2c_stop();
	i2c_start(DS3231_ADDR+I2C_READ);
	unsigned char data = i2c_readNak();
	i2c_stop();
	unsigned char date = data & 0b00001111;
	unsigned char datex10 = ((data & 0b01110000) >> 4);
	date += datex10 * 10;
	return date;
}

uint8_t read_month()
{
	i2c_start(DS3231_ADDR+I2C_WRITE);
	i2c_write(0x05);
	i2c_stop();
	i2c_start(DS3231_ADDR+I2C_READ);
	unsigned char data = i2c_readNak();
	i2c_stop();
	unsigned char month = data & 0b00001111;
	unsigned char monthx10 = ((data & 0b01110000) >> 4);
	month += monthx10 * 10;
	return month;
}

uint8_t read_year()
{
	i2c_start(DS3231_ADDR+I2C_WRITE);
	i2c_write(0x06);
	i2c_stop();
	i2c_start(DS3231_ADDR+I2C_READ);
	unsigned char data = i2c_readNak();
	i2c_stop();
	unsigned char year = data & 0b00001111;
	unsigned char yearx10 = ((data & 0b01110000) >> 4);
	year += yearx10 * 10;
	return year;
}

void write_date(uint8_t date)
{
	uint8_t datex1 = date % 10;
	uint8_t datex10 = date / 10;
	uint8_t data = (datex10 << 4) | (datex1);
	i2c_start(DS3231_ADDR+I2C_WRITE);
	i2c_write(0x04);
	i2c_write(data);
	i2c_stop();
}

void write_month(uint8_t month)
{
	uint8_t monthx1 = month % 10;
	uint8_t monthx10 = month / 10;
	uint8_t data = (monthx10 << 4) | (monthx1);
	i2c_start(DS3231_ADDR+I2C_WRITE);
	i2c_write(0x05);
	i2c_write(data);
	i2c_stop();
}

void write_year(uint8_t year)
{
	uint8_t yearx1 = year % 10;
	uint8_t yearx10 = year / 10;
	uint8_t data = (yearx10 << 4) | (yearx1);
	i2c_start(DS3231_ADDR+I2C_WRITE);
	i2c_write(0x06);
	i2c_write(data);
	i2c_stop();
}

