/*
 * rgbled.h
 *
 * Created: 12.10.2020 03:42:23
 *  Author: GDokmetas
 */ 

#ifndef RGBLED_H_
#define RGBLED_H_
#include <avr/io.h>
////////////////////////////
#define RGBDATADIRECTION DDRE 
#define RGBPORT PORTE 
#define KIRMIZIPIN PORTE0
#define YESILPIN PORTE1
#define MAVIPIN PORTE2

/////////////////////////////
#define KIRMIZI 0
#define YESIL   1
#define MAVI    2
#define CAMGOBEGI    3
#define SARI    4
#define MOR     5
#define BEYAZ   6
/////////////
extern void led_init();
extern void led_yak(int renk);
extern void led_sondur();





#endif /* RGBLED_H_ */
