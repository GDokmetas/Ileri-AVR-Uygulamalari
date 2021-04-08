/*
 * max7219.h
 *
 * Created: 8.11.2020 11:23:18
 *  Author: GDokmetas
 */ 


#ifndef MAX7219_H_
#define MAX7219_H_
#include <stdint.h>

extern void max_init();
extern void max_send_byte(uint8_t addr, uint8_t data);
extern void max_clear_display();
extern void max_digit(uint8_t digit, uint8_t value);
extern void max_show32bit(uint32_t number);
#endif /* MAX7219_H_ */