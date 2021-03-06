
#include "adc.h"

void adc_init(void){
 ADCSRA |= (ADC_PRESCALER);  
 ADMUX |= ((ADC_REFERENCE) << 6);
 ADCSRA |= (1<<ADEN); // Enable ADC
 ADCSRA |= (1<<ADSC); // Make first conversation and ready adc 
}

void adc_deinit(){
   ADCSRA &= ~(1<<ADEN); // Shut-down ADC 
}

uint16_t adc_read(uint8_t channel)
{
	ADMUX &= 0xF0;
	ADMUX |= channel;
	ADCSRA |=(1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	return ADCW;
}

uint16_t adc_read_smooth(uint8_t channel)
{
	uint32_t adtotal = 0;
	for (int i=0; i<100; i++)
	{
		ADMUX &= 0xF0;
		ADMUX |= channel;
		ADCSRA |=(1<<ADSC);
		while(ADCSRA & (1<<ADSC));
		adtotal += ADCW;	
	}
	return adtotal / 100;
}

long adc_read_map(uint8_t channel, long out_min, long out_max)
{
	  ADMUX &= 0xF0;
	  ADMUX |= channel;
	  ADCSRA |=(1<<ADSC);
	  while(ADCSRA & (1<<ADSC));
	  long x = ADCW;
	  x = (x - 0) * (out_max - out_min) / (1023 - 0) + out_min;
	  return x;
}
uint16_t adc_read_data()
{
   return ADCW;
}

extern void adc_autotrig(uint8_t mode)
{
   ADCSRB |= (mode); // last 3 bits 
   ADCSRA |= (1<<ADATE);
   if (mode == FREE_RUN)
   ADCSRA |= (1<<ADSC); // Start in free running. 
   // If you dont want to auto start, comment this and use adc_read() 
}

void adc_interrupt(uint8_t status)
{
   if (status == 1) // ENABLE INTERRUPTS
   {
      ADCSRA |= (1<<ADIE);
   }
   else
   {
      ADCSRA &= ~(1<<ADIE);
   }
   
}

extern void adc_disable_digital(uint8_t pins)
{
   DIDR0 = pins; 
}

extern void adc_left_adjust()
{
   ADMUX |= (1<<ADLAR);
}
