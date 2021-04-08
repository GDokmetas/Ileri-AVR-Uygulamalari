/*
 * i2c24c32.h
 *
 * Created: 1.11.2020 03:18:51
 *  Author: PC
 */ 


#ifndef I2C24C32_H_
#define I2C24C32_H_
#include <stdint.h>
/////////
#define EEPROM_ADDRESS 0x50
/////////
#define EEPROM_ADDR (EEPROM_ADDRESS << 1)

extern void eeprom_write_8bit(uint16_t address, uint8_t data);
extern void eeprom_write_16bit(uint16_t address, uint16_t data);
extern void eeprom_write_32bit(uint16_t address, uint32_t data);
///////////////////////////
extern uint8_t eeprom_read_8bit(uint16_t address);
extern uint16_t eeprom_read_16bit(uint16_t address);
extern uint32_t eeprom_read_32bit(uint16_t address);
///////////////////////////


#endif /* I2C24C32_H_ */