/***************** AVR182 : Zero Cross Detector (using AVR) *****************
Device      :   ATmega163

File name   :   zero_cross_detector.h

Ver nr.     :   2.0

Description :   Header file for zero_cross_detector.c
                Inludes the IO files for the code and define functions.

Compiler    :  IAR ICC90
 
****************************************************************************/
/****************************************************************************
	Include files
****************************************************************************/
#include "iom163.h"				        //IO file for ATmega163
#include "ina90.h"

/****************************************************************************
	Function definitions
****************************************************************************/
void Setup(void);				//General setup for the AVR

/****************************************************************************
	Interrupt definitions
****************************************************************************/
void interrupt[INT0_vect] INT0_interrupt(void); //External interrupt 0

/****************************************************************************
	Definitions
****************************************************************************/
#define RETURN 100

