/*
 * rgbled.c
 *
 * Created: 12.10.2020 03:44:53
 *  Author: GDokmetas
 */ 
#include "rgbled.h"

extern void led_init()
{
	RGBDATADIRECTION |= ((1<<KIRMIZIPIN) | (1<<YESILPIN) | (1<<MAVIPIN));
}

extern void led_yak(int renk)
{
	RGBPORT &= ~((1<<KIRMIZIPIN) | (1<<YESILPIN) | (1<<MAVIPIN));
	switch (renk)
	{
		case KIRMIZI:
		RGBPORT |= (1<<KIRMIZIPIN);
		break;
		case YESIL:
		RGBPORT |= (1<<YESILPIN);
		break;
		case MAVI: 
		RGBPORT |= (1<<MAVIPIN);
		break;
		case CAMGOBEGI: 
		RGBPORT |= (1<<MAVIPIN);
		RGBPORT |= (1<<YESILPIN);
		break;
		case SARI:
		RGBPORT |= (1<<KIRMIZIPIN);
		RGBPORT |= (1<<YESILPIN);
		break;
		case MOR: 
		RGBPORT |= (1<<KIRMIZIPIN);
		RGBPORT |= (1<<MAVIPIN);
		break;
		case BEYAZ: 
		RGBPORT |= (1<<KIRMIZIPIN);
		RGBPORT |= (1<<MAVIPIN);
		RGBPORT |= (1<<YESILPIN);
		break;
		default:
		break;
	}
}

extern void led_sondur()
{
	RGBPORT &= ~((1<<KIRMIZIPIN) | (1<<YESILPIN) | (1<<MAVIPIN));
}
