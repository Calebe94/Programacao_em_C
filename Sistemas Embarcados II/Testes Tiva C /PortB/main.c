#include<stdint.h>
#include"tm4c123gh6pm.h"

/************************************
 * Nesse Registrador sera utilizado as funcoes alternativas PWM e Analog.
 *
 * PortB- DIR = 0x1
 * PB0 - PWM - BUZZER(Out)
 * PB1 - GPIO - BT3(In)
 * PB2 - GPIO - BT4(In)
 * PB4 - A10 - RANDOM(In)
 *------------------------
 * Nesse Registrador pode ser desligado as funcoes alternativas.
 * PortE- DIR = 0xF
 * PE0 - GPIO - LED1(Out)
 * PE1 - GPIO - LED2(Out)
 * PE2 - GPIO - LED3(Out)
 * PE3 - GPIO - LED4(Out)
 * PE4 - GPIO - BT1(In)
 * PE5 - GPIO - BT2(In)
 *
 *
The following are defines for the bit fields in the SYSCTL_RCGC2 register.

#define SYSCTL_RCGC2_USB0       0x00010000  // USB0 Clock Gating Control
#define SYSCTL_RCGC2_UDMA       0x00002000  // Micro-DMA Clock Gating Control
#define SYSCTL_RCGC2_GPIOF      0x00000020  // Port F Clock Gating Control
#define SYSCTL_RCGC2_GPIOE      0x00000010  // Port E Clock Gating Control
#define SYSCTL_RCGC2_GPIOD      0x00000008  // Port D Clock Gating Control
#define SYSCTL_RCGC2_GPIOC      0x00000004  // Port C Clock Gating Control
#define SYSCTL_RCGC2_GPIOB      0x00000002  // Port B Clock Gating Control
#define SYSCTL_RCGC2_GPIOA      0x00000001  // Port A Clock Gating Control
*/
#define led1    (GPIO_PORTE_DATA_R&(1<<0))
#define led2    (GPIO_PORTE_DATA_R&(1<<1))
#define led3    (GPIO_PORTE_DATA_R&(1<<2))
#define led4    (GPIO_PORTE_DATA_R&(1<<3))
#define bt1     (GPIO_PORTE_DATA_R&(1<<4))
#define bt2     (GPIO_PORTE_DATA_R&(1<<5))
#define bt3     (GPIO_PORTB_DATA_R&(1<<1))
#define bt4     (GPIO_PORTB_DATA_R&(1<<2))
//#define buzzer  (GPIOF->DATA=0x0C)
//#define random 12

int delay = 0;
void PortB(void){
    SYSCTL_RCGC2_R = 0x00000002;
    delay = SYSCTL_RCGC2_R;
    GPIO_PORTB_PCTL_R &=~(0x00);
    GPIO_PORTB_DIR_R |=0x06;
    GPIO_PORTB_AFSEL_R &=~(0x06);
    GPIO_PORTB_DEN_R |=0x06;

}
void PortE(void){
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOE;
    delay = SYSCTL_RCGC2_R;
    GPIO_PORTE_AMSEL_R &= ~(0x3F);
    //GPIO_PORTE_PCTL_R &=~(0x00);
    GPIO_PORTE_DIR_R |=0xF;
    GPIO_PORTE_AFSEL_R &= ~(0x3F);
    GPIO_PORTE_DEN_R |=0xF;
}
void setup(void);
void loop(void);
int main(void){
    setup();
    do{

        loop();

    }while(1);
}
void setup(void){
    PortB();
    PortE();
}
void loop(void){
    if(bt1) led1;
    if(bt2) led2;
    if(bt3) led3;
    if(bt4) led4;
}
