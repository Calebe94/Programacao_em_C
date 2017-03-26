#include"pwm.h"

void PWM_Init(){
    //Initialize PB6 as PWM0
  SYSCTL_RCGCPWM_R |= PWM_ENABLE_PWM0EN; 
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGC2_GPIOB;
  while((SYSCTL_PRGPIO_R&SYSCTL_RCGC2_GPIOB) == 0){};
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
void PWM_Tone(uint16_t period, uint16_t duty){
  PWM0_0_LOAD_R = period - 1;
  PWM0_0_CMPA_R = duty - 1;  
}
