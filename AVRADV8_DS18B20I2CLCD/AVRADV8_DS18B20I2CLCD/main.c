/*
 * AVRADV8_DS18B20I2CLCD.c
 *
 * Created: 30.10.2020 09:37:54
 * Author : PC
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "ds18S20.h"
#include "lcd1602.h"
#include <stdlib.h>
#include <util/delay.h>
char buffer[10];
int main(void)
{
     lcd1602_init();
	 
	 TSDS18x20 DS18x20;
	 TSDS18x20 *pDS18x20 = &DS18x20;
	 DS18x20_Init(pDS18x20,&PORTD,PORTD2);
	 DS18x20_SetResolution(pDS18x20,CONF_RES_11b);
	 DS18x20_WriteScratchpad(pDS18x20);
	lcd1602_clear();
    while (1) 
    {
		DS18x20_MeasureTemperature(pDS18x20);
		dtostrf(DS18x20_TemperatureValue(pDS18x20),7,4,buffer);
		
		lcd1602_goto_xy(0,0);
		lcd1602_send_string("SICAKLIK:");
		lcd1602_send_string(buffer);
		lcd1602_send_string("C");
		lcd1602_send_string("   ");
		
		_delay_ms(300);
    }
}

