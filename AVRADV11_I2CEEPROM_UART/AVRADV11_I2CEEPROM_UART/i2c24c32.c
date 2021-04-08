/*
 * i2c24c32.c
 *
 * Created: 1.11.2020 03:19:37
 *  Author: PC
 */ 
#include "i2c24c32.h"
#include "i2cmaster.h"
#include "uart.h"
void eeprom_write_8bit(uint16_t address, uint8_t data)
{
	uint8_t high_byte = address >> 8;
	uint8_t low_byte = address & 0x00FF;
	i2c_start_wait(EEPROM_ADDR+I2C_WRITE);
	i2c_write(high_byte);
	i2c_write(low_byte);
	i2c_write(data);
	i2c_stop();
}

uint8_t eeprom_read_8bit(uint16_t address)
{
	uint8_t veri;
	uint8_t high_byte = address >> 8;
	uint8_t low_byte = address & 0x00FF;
	i2c_start_wait(EEPROM_ADDR+I2C_WRITE);
	i2c_write(high_byte);
	i2c_write(low_byte);
	i2c_rep_start(EEPROM_ADDR+I2C_READ);
	veri = i2c_readNak();
	i2c_stop();
	return veri;
}

void eeprom_write_16bit(uint16_t address, uint16_t data)
{
	uint8_t high_data = data >> 8;
	uint8_t low_data = data & 0x00FF;
	eeprom_write_8bit(address, high_data);
	address++;
	eeprom_write_8bit(address,low_data);
}

 uint16_t eeprom_read_16bit(uint16_t address)
 {
	 uint8_t high_data = eeprom_read_8bit(address);
	 address++;
	 uint8_t low_data = eeprom_read_8bit(address);
	 uint16_t data = high_data << 8;
	 data |= low_data;
	 return data;
 }
 
 void eeprom_write_32bit(uint16_t address, uint32_t data)
 {
	 uint8_t high_data_1 = data >> 24;
	 uint8_t high_data_2 = ((data >> 16) & 0x000000FF);
	 uint8_t low_data_2 = ((data >> 8) & 0x000000FF);
	 uint8_t low_data_1 = (data & 0x000000FF);
	 
	 eeprom_write_8bit(address,high_data_1);
	 address++;
	 eeprom_write_8bit(address,high_data_2);
	 address++;
	 eeprom_write_8bit(address,low_data_2);
	 address++;
	 eeprom_write_8bit(address,low_data_1);
	 
 }
 
 uint32_t eeprom_read_32bit(uint16_t address)
 {
	 uint32_t high_data_1 = eeprom_read_8bit(address);
	 address++;
	 uint32_t high_data_2 = eeprom_read_8bit(address);
	 address++;
	 uint32_t low_data_2 = eeprom_read_8bit(address);
	 address++;
	 uint32_t low_data_1 = eeprom_read_8bit(address);
	 
	 uint32_t data = 0;
	 data |= (high_data_1 << 24);
	 data |= (high_data_2 << 16);
	 data |= (low_data_2 << 8);
	 data |= (low_data_1);
	 return data;
 }