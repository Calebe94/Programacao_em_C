#include"adc.h"

/*
 * Complexidade de Algorítmo total do arquivo adc.c = f(n) = 2n + 42
 * */

/*
 * Complexidade de Algorítmo ADC_Init(): f(n) = 36
 * */
void ADC_Init(void){
    volatile unsigned long delay;
    SYSCTL_RCGC2_R |= 0x00000010;
    delay = SYSCTL_RCGC2_R;
    GPIO_PORTE_DIR_R &= ~0x10;
    GPIO_PORTE_AFSEL_R |= 0x10;
    GPIO_PORTE_DEN_R &= ~0x10;
    GPIO_PORTE_AMSEL_R |= 0x10;
    SYSCTL_RCGC0_R |= 0x00010000;
    delay = SYSCTL_RCGC0_R;
    SYSCTL_RCGC0_R &= ~0x00000300;
    ADC0_SSPRI_R = 0x0123;
    ADC0_ACTSS_R &= ~0x0008;
    ADC0_EMUX_R &= ~0xF000;
    ADC0_SSMUX3_R &= ~0x000F;
    ADC0_SSMUX3_R += 9;
    ADC0_SSCTL3_R = 0x0006;
    ADC0_ACTSS_R |= 0x0008;
}

/*
 * Complexidade de Algorítmo ADC_Read(): f(n) = 2n+6
 * */
unsigned long ADC_Read(void){
    unsigned long result;
    ADC0_PSSI_R = 0x0008;
    while((ADC0_RIS_R&0x08)==0){};
    result = ADC0_SSFIFO3_R&0xFFF;
    ADC0_ISC_R = 0x0008;
    return result;
}
