/*
 * sleep.h
 *
 * Created: 26.10.2020 23:20:26
 *  Author: PC
 */ 


#ifndef SLEEP_H_
#define SLEEP_H_

#define IDLE 0 
#define ADC_NOISE 0b10 
#define POWER_DOWN 0b100
#define POWER_SAVE 0b110 
#define STANDBY 0b1100
#define EXTENDED_STANDBY 0b1110
// SLEEP MODES
void sleep(int mode);
void bod_disable_sleep();
void sleep_mode(int mode);


#endif /* SLEEP_H_ */