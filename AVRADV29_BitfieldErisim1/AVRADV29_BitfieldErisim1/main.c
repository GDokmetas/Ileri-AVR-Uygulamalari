
#include <avr/io.h>
#define  F_CPU 16000000UL
#include <util/delay.h>
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

#define bit_portd2_dir  ((volatile io_register*)_SFR_MEM_ADDR(DDRD))->bit2
#define bit_portd3_dir  ((volatile io_register*)_SFR_MEM_ADDR(DDRD))->bit3
#define bit_portd4_dir  ((volatile io_register*)_SFR_MEM_ADDR(DDRD))->bit4

#define bit_portd2_out  ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit2
#define bit_portd3_out  ((volatile io_register*)_SFR_MEM_ADDR(PORTD))->bit3
#define bit_portd4_out  ((volatile io_register *)_SFR_MEM_ADDR(PORTD))->bit4

#define kirmizi bit_portd2_out
#define yesil bit_portd3_out 
#define mavi bit_portd4_out
#define bekleme 300

int main(void)
{
    bit_portd2_dir = 1;
	bit_portd3_dir = 1;
	bit_portd4_dir = 1;
    while (1) 
    {
		/*
		kirmizi = 1;
		_delay_ms(bekleme);
		kirmizi = 0;
		yesil = 1;
		_delay_ms(bekleme);
		yesil = 0;
		mavi = 1;
		_delay_ms(bekleme);
		mavi = 0;
		*/
		
		// Performans Test
		kirmizi = 1;
		kirmizi = 0;
    }
}

