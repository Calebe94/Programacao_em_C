// hello_launchpad.c
#include <stdint.h>
#include "tm4c123gh6pm.h"

/* It is always best practice to define some macros for the signals*/
#define  SW1  (GPIOF->DATA&(1<<4))
#define	 SW2  (GPIOF->DATA&(1<<0))
#define	 red  (GPIOF->DATA=0x02)
#define	 blue  (GPIOF->DATA=0x04)
#define	 green (GPIOF->DATA=0x08)
#define	 white (GPIOF->DATA=0x0E)
#define	 Dark  (GPIOF->DATA=0x00)
#define	 Yellow (GPIOF->DATA=0x0A)
#define	 Sky_blue (GPIOF->DATA=0x0C)

// This function initializes the Switches and led connected to PORTF
void PORTF_ini(void){
    volatile uint32_t delay=0; //Declaring  dummy bit for waiting after enabling clock  
    SYSCTL->RCGC2=0x00000020; //Clock for the PORTF
    delay=SYSCTL->RCGC2;	  //waiting after enabling the clock
    GPIOF->LOCK=0x4C4F434B;	  //writing the magic number to LOCK register	
    GPIOF->CR=0x1F;	         //Allowing changes for bits PF0 to PF4 
		GPIOF->DIR=0x0E;	 //Setting the direction IO pins
		GPIOF->PUR=0x11;	 //Enabling the pull-up register for PF0 and PF4
		GPIOF->DEN=0x1F;	 //Enabling digital pins from 0 to 4
}
int main(){
		 PORTF_ini();		 //Initializing port 
		while(1){
			if((!SW1)&&(SW2)){  //when switch 1 pressed 
			blue;		    // Blue led
			}	
		else	if((SW1)&&(!SW2)){  //when switch 2 pressed 
			green;		    //green led	
			}				
		else 	if((!SW1)&&(!SW2)){ //when switch both pressed 
			white;		    //	white led
			}
			else red;	    //none of them pressed then red
}
}
