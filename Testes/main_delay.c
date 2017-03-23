//Author : cortex-m.com
//Function : Periodic mode milliseconds delay
                // Device header
#include"tm4c123gh6pm.h"
void timer0A_delayMs(int ttime);
 
int main (void)
{
    /* enable clock to GPIOF at clock gating control register */
    SYSCTL->RCGCGPIO |= 0x20;
    /* enable the GPIO pins for the LED (PF3, 2 1) as output */
    GPIOF->DIR = 0x0E;
    /* enable the GPIO pins for digital function */
    GPIOF->DEN = 0x0E;
 
    while(1)
    {
        GPIOF->DATA = 2;        /* turn on red LED */
        timer0A_delayMs(500);   /* TimerA 500 msec delay */
        GPIOF->DATA = 0;        /* turn off red LED */
        timer0A_delayMs(500);   /* TimerA 500 msec delay */
    }
 
}
 
/* multiple of millisecond delay using periodic mode */
void timer0A_delayMs(int ttime)
{
    int i;
    SYSCTL->RCGCTIMER |= 1;     /* enable clock to Timer Block 0 */
 
    TIMER0->CTL = 0;            /* disable Timer before initialization */
    TIMER0->CFG = 0x04;         /* 16-bit option */
    TIMER0->TAMR = 0x02;        /* periodic mode and down-counter */
    TIMER0->TAILR = 16000 - 1;  /* Timer A interval load value register */
    TIMER0->ICR = 0x1;          /* clear the TimerA timeout flag*/
    TIMER0->CTL |= 0x01;        /* enable Timer A after initialization */
 
    for(i = 0; i < ttime; i++) { while ((TIMER0->RIS & 0x1) == 0) ;      /* wait for TimerA timeout flag */
        TIMER0->ICR = 0x1;      /* clear the TimerA timeout flag */
    }
}
