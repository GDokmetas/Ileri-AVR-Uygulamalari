/*
 * bitfieldarduino.h
 *
 * Created: 20.3.2021 07:52:39
 *  Author: GDokmetas
 */ 


#ifndef BITFIELDARDUINO_H_
#define BITFIELDARDUINO_H_

#include <avr/io.h>
/////////// Değer tanımlamaları /////////
#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define INPUT 0
#define PULL_UP 1
#define NO_PULLUP 0
typedef struct
{
	unsigned char bit0:1;
	unsigned char bit1:1;
	unsigned char bit2:1;
	unsigned char bit3:1;
	unsigned char bit4:1;
	unsigned char bit5:1;
	unsigned char bit6:1;
	unsigned char bit7:1;
}io_register;

#define D0_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRD))->bit0
#define D1_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRD))->bit1
#define D2_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRD))->bit2
#define D3_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRD))->bit3
#define D4_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRD))->bit4
#define D5_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRD))->bit5
#define D6_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRD))->bit6
#define D7_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRD))->bit7
#define D8_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRB))->bit0
#define D9_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRB))->bit1
#define D10_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRB))->bit2
#define D11_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRB))->bit3
#define D12_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRB))->bit4
#define D13_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRB))->bit5
#define A0_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRC))->bit0
#define A1_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRC))->bit1
#define A2_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRC))->bit2
#define A3_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRC))->bit3
#define A4_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRC))->bit4
#define A5_pinMode  ((volatile io_register*)_SFR_MEM_ADDR(DDRC))->bit5


#define D0_digitalWrite ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit0
#define D1_digitalWrite ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit1
#define D2_digitalWrite ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit2
#define D3_digitalWrite ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit3
#define D4_digitalWrite ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit4
#define D5_digitalWrite ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit5
#define D6_digitalWrite ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit6
#define D7_digitalWrite ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit7
#define D8_digitalWrite  ((volatile io_register*)_SFR_MEM_ADDR(PORTB))->bit0
#define D9_digitalWrite  ((volatile io_register*)_SFR_MEM_ADDR(PORTB))->bit1
#define D10_digitalWrite  ((volatile io_register*)_SFR_MEM_ADDR(PORTB))->bit2
#define D11_digitalWrite  ((volatile io_register*)_SFR_MEM_ADDR(PORTB))->bit3
#define D12_digitalWrite  ((volatile io_register*)_SFR_MEM_ADDR(PORTB))->bit4
#define D13_digitalWrite  ((volatile io_register*)_SFR_MEM_ADDR(PORTB))->bit5
#define A0_digitalWrite ((volatile io_register*)_SFR_MEM_ADDR(PORTC))->bit0
#define A1_digitalWrite ((volatile io_register*)_SFR_MEM_ADDR(PORTC))->bit1
#define A2_digitalWrite ((volatile io_register*)_SFR_MEM_ADDR(PORTC))->bit2
#define A3_digitalWrite ((volatile io_register*)_SFR_MEM_ADDR(PORTC))->bit3
#define A4_digitalWrite ((volatile io_register*)_SFR_MEM_ADDR(PORTC))->bit4
#define A5_digitalWrite ((volatile io_register*)_SFR_MEM_ADDR(PORTC))->bit5

#define D0_pullUp ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit0
#define D1_pullUp ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit1
#define D2_pullUp ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit2
#define D3_pullUp ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit3
#define D4_pullUp ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit4
#define D5_pullUp ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit5
#define D6_pullUp ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit6
#define D7_pullUp ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit7
#define D8_pullUp  ((volatile io_register*)_SFR_MEM_ADDR(PORTB))->bit0
#define D9_pullUp  ((volatile io_register*)_SFR_MEM_ADDR(PORTB))->bit1
#define D10_pullUp  ((volatile io_register*)_SFR_MEM_ADDR(PORTB))->bit2
#define D11_pullUp  ((volatile io_register*)_SFR_MEM_ADDR(PORTB))->bit3
#define D12_pullUp ((volatile io_register*)_SFR_MEM_ADDR(PORTB))->bit4
#define D13_pullUp  ((volatile io_register*)_SFR_MEM_ADDR(PORTB))->bit5
#define A0_pullUp ((volatile io_register*)_SFR_MEM_ADDR(PORTC))->bit0
#define A1_pullUp ((volatile io_register*)_SFR_MEM_ADDR(PORTC))->bit1
#define A2_pullUp ((volatile io_register*)_SFR_MEM_ADDR(PORTC))->bit2
#define A3_pullUp ((volatile io_register*)_SFR_MEM_ADDR(PORTC))->bit3
#define A4_pullUp ((volatile io_register*)_SFR_MEM_ADDR(PORTC))->bit4
#define A5_pullUp ((volatile io_register*)_SFR_MEM_ADDR(PORTC))->bit5

#define D0_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PIND))->bit0
#define D1_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PIND))->bit1
#define D2_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PIND))->bit2
#define D3_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PIND))->bit3
#define D4_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PIND))->bit4
#define D5_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PIND))->bit5
#define D6_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PIND))->bit6
#define D7_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PIND))->bit7
#define D8_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PINB))->bit0
#define D9_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PINB))->bit1
#define D10_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PINB))->bit2
#define D11_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PINB))->bit3
#define D12_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PINB))->bit4
#define D13_digitalRead  ((volatile io_register*)_SFR_MEM_ADDR(PINB))->bit5
#define A0_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PINC))->bit0
#define A1_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PINC))->bit1
#define A2_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PINC))->bit2
#define A3_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PINC))->bit3
#define A4_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PINC))->bit4
#define A5_digitalRead ((volatile io_register*)_SFR_MEM_ADDR(PINC))->bit5
// Arduino'nun fonksiyon adlarını sevmeyenler için, daha pratik bir yol
#define D0_dir D0_pinMode 
#define D1_dir D1_pinMode 
#define D2_dir D2_pinMode 
#define D3_dir D3_pinMode 
#define D4_dir D4_pinMode 
#define D5_dir D5_pinMode 
#define D6_dir D6_pinMode 
#define D7_dir D7_pinMode 
#define D8_dir D8_pinMode 
#define D9_dir D9_pinMode 
#define D11_dir D10_pinMode 
#define D12_dir D12_pinMode 
#define D13_dir D13_pinMode 
#define A0_dir A0_pinMode 
#define A1_dir A1_pinMode 
#define A2_dir A2_pinMode 
#define A3_dir A3_pinMode 
#define A4_dir A4_pinMode 
#define A5_dir A5_pinMode 

#define D0_out D0_digitalWrite 
#define D1_out D1_digitalWrite 
#define D2_out D2_digitalWrite 
#define D3_out D3_digitalWrite 
#define D4_out D4_digitalWrite 
#define D5_out D5_digitalWrite 
#define D6_out D6_digitalWrite 
#define D7_out D7_digitalWrite 
#define D8_out D8_digitalWrite 
#define D9_out D9_digitalWrite 
#define D10_out D10_digitalWrite 
#define D11_out D11_digitalWrite 
#define D12_out D12_digitalWrite 
#define D13_out D13_digitalWrite 
#define A0_out A0_digitalWrite 
#define A1_out A1_digitalWrite 
#define A2_out A2_digitalWrite 
#define A3_out A3_digitalWrite 
#define A4_out A4_digitalWrite 
#define A5_out A5_digitalWrite 

#define D0_in D0_digitalRead 
#define D1_in D1_digitalRead 
#define D2_in D2_digitalRead 
#define D3_in D3_digitalRead 
#define D4_in D4_digitalRead 
#define D5_in D5_digitalRead 
#define D6_in D6_digitalRead 
#define D7_in D7_digitalRead 
#define D8_in D8_digitalRead 
#define D9_in D9_digitalRead 
#define D10_in D10_digitalRead 
#define D11_in D11_digitalRead 
#define D12_in D12_digitalRead 
#define D13_in D13_digitalRead 
#define A0_in A0_digitalRead 
#define A1_in A1_digitalRead 
#define A2_in A2_digitalRead 
#define A3_in A3_digitalRead 
#define A4_in A4_digitalRead 
#define A5_in A5_digitalRead 

#endif /* BİTFİELDARDUİNO_H_ */