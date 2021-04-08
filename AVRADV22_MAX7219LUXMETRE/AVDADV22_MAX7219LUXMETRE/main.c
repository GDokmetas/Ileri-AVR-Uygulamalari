/*
 * AVDADV22_MAX7219LUXMETRE.c
 *
 * Created: 8.11.2020 13:16:29
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "max7219.h"
#include "i2cmaster.h"
#include <inttypes.h>
#include <util/delay.h>
uint32_t bh1750_oku();
int main(void)
{
    i2c_init();
	max_init();
    while (1) 
    {
		max_show32bit(bh1750_oku());
		_delay_ms(200);
    }
}

uint32_t bh1750_oku()
{
	uint8_t bh1750_addr = (0x23 << 1);
	i2c_rep_start(bh1750_addr+I2C_WRITE);
	i2c_write(0x10);
	i2c_stop();
	_delay_ms(10);
	i2c_rep_start(bh1750_addr+I2C_WRITE);
	i2c_write(0x10);
	i2c_stop();
	_delay_ms(200);
	i2c_start_wait(bh1750_addr+I2C_READ);
	uint16_t okuma = 0;
	okuma = i2c_readAck();
	okuma <<= 8;
	okuma |= i2c_readNak();
	float lux  = okuma / 1.2F;
	return (uint32_t)lux;
}