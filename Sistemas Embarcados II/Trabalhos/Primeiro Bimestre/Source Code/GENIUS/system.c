#include"system.h"

#define XTAL 16000000
#define XTAL_ST 16000
#define ST_MAX_VALUE 0x00FFFFFF

void PortB(void){
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB;
    while((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOB)!=SYSCTL_RCGC2_GPIOB);
    GPIO_PORTB_CR_R = 0xF;
    GPIO_PORTB_DIR_R |=0xF;
    GPIO_PORTB_AFSEL_R&=~0xF;
    GPIO_PORTB_DEN_R |=0xF;
}
void PortE(void){
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOE;
    while((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOE)!=SYSCTL_RCGC2_GPIOE);
    GPIO_PORTE_CR_R |=0xF;
    GPIO_PORTE_DIR_R|=0x00;
    GPIO_PORTE_DEN_R|=0xF;
}
void SysTick_Init(void){
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = 0x00FFFFFF;
    NVIC_ST_CURRENT_R = 0;
    NVIC_ST_CTRL_R = 0x00000005;
}
void delay(unsigned long delay_ms){
    unsigned long Now=0;
    unsigned long Last=0;
    unsigned long Elapsed=0;
    NVIC_ST_RELOAD_R = 0x00FFFFFF;
    NVIC_ST_CURRENT_R = 0;
    delay_ms = (delay_ms*16777)-1;
    if(delay_ms < 16777216){
        Last = NVIC_ST_CURRENT_R;
        while(Elapsed<delay_ms){
            Now = NVIC_ST_CURRENT_R;
            Elapsed = (Last-Now)&0x00FFFFFF;
        }
    }
}
void another_delay(unsigned int delay){
    register unsigned int i;
    SYSCTL_RCGCTIMER_R |= 1;

    TIMER0_CTL_R = 0;
    TIMER0_CFG_R = 0x04;
    TIMER0_TAMR_R = 0x02;
    TIMER0_TAILR_R = 16000 - 1;
    TIMER0_ICR_R = 0x1;
    TIMER0_CTL_R |= 0x01;

    for(i = 0; i < delay; i++) {
        while ((TIMER0_RIS_R & 0x1) == 0) ;
        TIMER0_ICR_R = 0x1;
    }

}
