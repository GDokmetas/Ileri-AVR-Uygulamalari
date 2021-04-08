/***************** AVR182 : Zero Cross Detector (using AVR) *****************
Device      :   ATmega163

File name   :   zero_cross_detector.c

Ver nr.     :   2.0

Description :   Application note code for showing how to implement a zero 
                cross detector on AVR only with one external interrupt pin.
 
Compiler    :  IAR ICC90
 
****************************************************************************/
#include "Zero_cross_detector.h"

/****************************************************************************
	Function : char setup(void)									
	AVR setup routine
****************************************************************************/
void setup(void)
{	
	  DDRB |= 0x01;                       //Set up PORTB.0 to output 
    GIFR = GIFR;                        //Clear interrupt flags
    GIMSK |= (1<<INT0);                 //Enable external int0
    MCUCR |= (1<<ISC01);   		          //Set to falling edge interrupt

}		 

/****************************************************************************
	Function : void C_task main (void)
	Main function for the Zero cross detector
	Calls the setup function, enable globale interrutps and loops eternal
	while waiting for external interrupt 0
****************************************************************************/
void C_task main (void)
{
    setup();                            //Setup ports and Interrupt
    _SEI();                             //Enable global interrupt and 
                                        //wait for a zero cross

    for(;;);                            //Eternal loop
}    

/****************************************************************************
void interrupt[INT0_vect] INT0_interrupt(void)
External interrupt 0 handling routine. This is where the zero cross action is
placed. When a zero cross detection is needed the main program init a rising 
edge external interrupt 0. 
On the first falling edge this routine will be excecuted.
To make sure the falling edge sensing was correct and not caused by noise 
it will do five pin samples where it has to sense low pin level on 
all before it validate the level. If it don't get five in a row it will return 
to the main program and wait for the next falling edge interrupt.
After five in a row the AVR start a zero cross handling action.
The zero cross handeling here is only a example and will only apply a short 
puls on PORTB.0. 
After the puls is finished it will enable falling edge interrupt again to init 
the next zero cross, then return to the main program and wait for the next
interrupt.
****************************************************************************/
void interrupt[INT0_vect] INT0_interrupt(void)
{
    char i,temp;

    /*Filter it to makes sure it was not only noise*/
    for (temp= 0;temp< 5;)          //Five samples noise filter
    	{
	if(!(PIND & (1<<PD2)))
          temp++;
        else
          temp = RETURN;          
        }                           
        if(temp != RETURN)
          {
            
          /*Place your zero cross action here*/
    
          PORTB = (1<<PB0);           //At each zero cross from pos to neg
          for(i=0x2F;i>0;i--);        //PORTB.0 will be set high for a 
          PORTB &= ~(1<<PB0);         //short periode of time

            
          /*As this is a excample code for zero cross detection it is set to 
          give a PORTB.0 puls on every pos to neg zero cross. To make a 
          one-shot uncomment the line under which disables the ext int 0 
          interrupt. When you want a zero cross detection again you enable 
          external interrupt 0 on rising edge again*/
          //GIMSK = GIMSK & ~(1<<INT0); //Disable external int 0
          }
        
}
