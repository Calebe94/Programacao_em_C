#include"pwm.h"

/*
 * Complexidade de Algorítmo total do arquivo pwm.c = f(n) = 33
 * */

/*
 * Complexidade de Algorítmo PWM_Init(): f(n) = 29
 * */
void PWM_Init(){
    volatile uint32_t delay;
    SYSCTL_RCGCPWM_R |= PWM_ENABLE_PWM0EN;
    delay = SYSCTL_RCGCPWM_R;
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGC2_GPIOB;
    delay = SYSCTL_RCGCGPIO_R;
    GPIO_PORTB_AFSEL_R |= 0x40;
    GPIO_PORTB_PCTL_R &= ~0x0F000000;
    GPIO_PORTB_PCTL_R |= 0x04000000;
    GPIO_PORTB_AMSEL_R &= ~0x40;
    GPIO_PORTB_DEN_R |= 0x40;
    SYSCTL_RCC_R = 0x00100000 | (SYSCTL_RCC_R & (~0x000E0000));
    PWM0_0_CTL_R = 0;
    PWM0_0_GENA_R = 0xC8;
    PWM0_0_CTL_R |= PWM_ENABLE_PWM0EN;
    PWM0_ENABLE_R |= PWM_ENABLE_PWM0EN;
}

/*
 * Complexidade de Algorítmo PWM_Tone(): f(n) = 4
 * */
void PWM_Tone(uint16_t period, uint16_t duty){
    PWM0_0_LOAD_R = period - 1;
    PWM0_0_CMPA_R = duty - 1;
}
