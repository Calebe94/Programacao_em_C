#include"adc.h"

void ADC_Init(){

    SYSCTL_RCGCADC_R |= 0x00000001; // 1) activate ADC0
    while((SYSCTL_RCGCADC_R&0x00000001)!=0x00000001);
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGC2_GPIOE; // 1) activate clock for Port E
    while((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOE)!=SYSCTL_RCGC2_GPIOE);


    GPIO_PORTE_DIR_R &= ~0x20;      // 3) make PE4 PE5 input
    GPIO_PORTE_AFSEL_R |= 0x20;     // 4) enable alternate function on PE4 PE5
    GPIO_PORTE_DEN_R &= ~0x20;      // 5) disable digital I/O on PE4 PE5
                                    // 5a) configure PE4 as ?? (skip this line because PCTL is for digital only)
    GPIO_PORTE_PCTL_R = GPIO_PORTE_PCTL_R&0xFF00FFFF;
    GPIO_PORTE_AMSEL_R |= 0x20;     // 6) enable analog functionality on PE4 PE5
    ADC0_PC_R &= ~0xF;              // 8) clear max sample rate field
    ADC0_PC_R |= 0x1;               //    configure for 125K samples/sec
    ADC0_SSPRI_R = 0x3210;          // 9) Sequencer 3 is lowest priority
    ADC0_ACTSS_R &= ~0x0004;        // 10) disable sample sequencer 2
    ADC0_EMUX_R &= ~0x0F00;         // 11) seq2 is software trigger
    ADC0_SSMUX2_R = 0x0089;         // 12) set channels for SS2
    ADC0_SSCTL2_R = 0x0060;         // 13) no TS0 D0 IE0 END0 TS1 D1, yes IE1 END1
    ADC0_IM_R &= ~0x0004;           // 14) disable SS2 interrupts
    ADC0_ACTSS_R |= 0x0004;         // 15) enable sample sequencer 2
}

unsigned int ADC_Read(){
    volatile unsigned int result;

    ADC0_PSSI_R = 0x0004;            // 1) initiate SS2
    while((ADC0_RIS_R&0x04)==0){};   // 2) wait for conversion done
    result = ADC0_SSFIFO2_R&0xFFF;  // 3A) read first result
    ADC0_ISC_R = 0x0004;             // 4) acknowledge completion
    return result;
}

/* Tentativa N°2: 
 Dessa vez tentei me inspirar no Livro do Valvano, no capítulo 14 ele explica sobre a converção analógico digital,
 então eu tentei me inspirar em seus blocos de código.*/
void ADC0_Init(void){ 
    volatile unsigned long delay;
    SYSCTL_RCGC2_R |= 0x00000010;   // 1) activate clock for Port E
    //while((SYSCTL_RCGC2_R&0x00000010)!=0x00000010);
    delay = SYSCTL_RCGC2_R;         //    allow time for clock to stabilize
    GPIO_PORTE_DIR_R &= ~0x10;      // 2) make PE4 input
    GPIO_PORTE_AFSEL_R |= 0x10;     // 3) enable alternate function on PE2
    GPIO_PORTE_DEN_R &= ~0x10;      // 4) disable digital I/O on PE2
    GPIO_PORTE_AMSEL_R |= 0x10;     // 5) enable analog function on PE2
    SYSCTL_RCGC0_R |= 0x00010000;   // 6) activate ADC0
    //while((SYSCTL_RCGC2_R&0x00010000)!=0x00010000);
    delay = SYSCTL_RCGC0_R;
    SYSCTL_RCGC0_R &= ~0x00000300;  // 7) configure for 125K
    ADC0_SSPRI_R = 0x0123;          // 8) Sequencer 3 is highest priority
    ADC0_ACTSS_R &= ~0x0008;        // 9) disable sample sequencer 3
    ADC0_EMUX_R &= ~0xF000;         // 10) seq3 is software trigger
    ADC0_SSMUX3_R &= ~0x000F;       // 11) clear SS3 field
    ADC0_SSMUX3_R += 9;             //    set channel Ain9 (PE4)
    ADC0_SSCTL3_R = 0x0006;         // 12) no TS0 D0, yes IE0 END0
    ADC0_ACTSS_R |= 0x0008;         // 13) enable sample sequencer 3
}
unsigned long ADC0_Read(void){
    unsigned long result;
    ADC0_PSSI_R = 0x0008;            // 1) initiate SS3
    while((ADC0_RIS_R&0x08)==0){};   // 2) wait for conversion done
    result = ADC0_SSFIFO3_R&0xFFF;   // 3) read result
    ADC0_ISC_R = 0x0008;             // 4) acknowledge completion
    return result;
}
