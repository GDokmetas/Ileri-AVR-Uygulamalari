/*
 * AVRADV33_StepMotor.c
 *
 * Created: 21.3.2021 04:22:28
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "bitfieldarduino.h"
#define IN1 D2_out
#define IN2 D3_out
#define IN3 D4_out
#define IN4 D5_out
#define step_delay 2
void step_ileri(unsigned int adim);
void step_geri(unsigned int adim);
//////////////////
void set1();
void set2();
void set3();
void set4();
void set5();
void set6();
void set7();
void set8();

int main(void)
{
    D2_dir = OUTPUT;
	D3_dir = OUTPUT;
	D4_dir = OUTPUT;
	D5_dir = OUTPUT;
	step_ileri(50);
    while (1) 
    {
	
    }
}

void step_ileri(unsigned int adim)
{
	while (adim > 0)
	{
		set1();
		set2();
		set3();
		set4();
		set5();
		set6();
		set7();
		set8();
	adim--;
    }
	
}

void step_geri(unsigned int adim)
{
	while (adim > 0)
	{
		set8();
		set7();
		set6();
		set5();
		set4();
		set3();
		set2();
		set1();
	adim--;
	}
}

void set1()
{
	IN1 = HIGH;
	IN2 = LOW;
	IN3 = LOW;
	IN4 = LOW;
	_delay_ms(step_delay);
}

void set2()
{
	IN1 = HIGH;
	IN2 = LOW; 
	IN3 = LOW;
	IN4 = HIGH;
	_delay_ms(step_delay);
}

void set3()
{
	IN1 = LOW;
	IN2 = LOW;
	IN3 = LOW;
	IN4 = HIGH;
	_delay_ms(step_delay);
}

void set4()
{
	IN1 = LOW;
	IN2 = LOW;
	IN3 = HIGH;
	IN4 = HIGH;
	_delay_ms(step_delay);
}

void set5()
{
	IN1 = LOW;
	IN2 = LOW;
	IN3 = HIGH;
	IN4 = LOW;
	_delay_ms(step_delay);
}

void set6()
{
	IN1 = LOW;
	IN2 = HIGH;
	IN3 = HIGH;
	IN4 = LOW;
	_delay_ms(step_delay);
}

void set7()
{
	IN1 = LOW;
	IN2 = HIGH;
	IN3 = LOW;
	IN4 = HIGH;
	_delay_ms(step_delay);
}

void set8()
{
	IN1 = HIGH;
	IN2 = HIGH;
	IN3 = LOW;
	IN4 = LOW;
	_delay_ms(step_delay);
}