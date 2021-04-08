/*
 * ds3231.h
 *
 * Created: 4.11.2020 12:24:13
 *  Author: GDokmetas
 */ 


#ifndef DS3231_H_
#define DS3231_H_

#include <stdint.h>
// Define DS3231_ADRESS in main.c
#ifndef DS3231_ADDRESS
#define DS3231_ADDRESS 0x68
#endif

#define DS3231_ADDR (DS3231_ADDRESS << 1)

////////// Functions //////
extern uint8_t read_sec();
extern uint8_t read_min();
extern uint8_t read_hour();
extern uint8_t read_date();
extern uint8_t read_month();
extern uint8_t read_year();

extern void write_sec(uint8_t sec);
extern void write_min(uint8_t min);
extern void write_hour(uint8_t hour);
extern void write_date(uint8_t date);
extern void write_month(uint8_t month);
extern void write_year(uint8_t year);

#endif /* DS3231_H_ */