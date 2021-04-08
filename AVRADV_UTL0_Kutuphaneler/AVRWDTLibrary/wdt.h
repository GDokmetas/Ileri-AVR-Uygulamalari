/*
 * wdt.h
 *
 * Created: 27.10.2020 04:14:00
 *  Author: PC
 */ 


#ifndef WDT_H_
#define WDT_H_

#define INTERRUPT 0
#define RESET 1
#define INTERRUPT_RESET 2
////////////////
#define  MS16 0b000
#define  MS32 0b0001
#define MS64 0b0010
#define MS125 0b0011
#define MS250 0b0100
#define MS500 0b0101
#define MS1000 0b0110
#define MS2000 0b0111
#define MS4000 0b100000
#define MS8000 0b100001
//////////////


extern void wdt_off(void);
extern void wdt_prescaler(int value);
extern void wdt_on(int mode);
#define wdt_reset() asm("WDR")


#endif /* WDT_H_ */