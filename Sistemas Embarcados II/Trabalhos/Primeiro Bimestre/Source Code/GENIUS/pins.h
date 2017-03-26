/************************************
  Há alterações Pendentes nesse Arquivo!
  18/03/17
  TO_DO:
    -Adicionar Variáveis globais
    -Atualizar os terminais utilizados por Registrador
 * PortB- DIR = 0x1
 * Nesse Registrador sera utilizado as funcoes alternativas PWM e Analog.
 *
 * PB0 - GPIO - LED1(Out)
 * PB1 - GPIO - LED2(Out)
 * PB2 - GPIO - LED3(Out)
 * PB3 - GPIO - LED4(Out)
 * PB4 - PWM  - buzzer(Out)
 *------------------------
 * PortE- DIR = 0xF
 * Nesse Registrador pode ser desligado as funcoes alternativas.
 * PE0 - GPIO - BT1(In)
 * PE1 - GPIO - BT2(In)
 * PE2 - GPIO - BT3(In)
 * PE3 - GPIO - BT4(In)
 * PE4 - ALin - Random(In)
 * PE5 - GPIO - Start(In)
 
The following are defines for the bit fields in the SYSCTL_RCGC2 register.
#define SYSCTL_RCGC2_GPIOE      0x00000010  // Port E Clock Gating Control
#define SYSCTL_RCGC2_GPIOB      0x00000002  // Port B Clock Gating Control
*/
#define leds GPIO_PORTB_DATA_R
#define buttons GPIO_PORTE_DATA_R


#define delay_1s 15999999


#define led1_On     (GPIO_PORTB_DATA_R|=0x01)
#define led1_Off    (GPIO_PORTB_DATA_R&=~0x01)

#define led2_On     (GPIO_PORTB_DATA_R|=0x02)
#define led2_Off    (GPIO_PORTB_DATA_R&=~0x02)

#define led3_On     (GPIO_PORTB_DATA_R|=0x04)
#define led3_Off    (GPIO_PORTB_DATA_R&=~0x04)

#define led4_On     (GPIO_PORTB_DATA_R|=0x08)
#define led4_Off    (GPIO_PORTB_DATA_R&=~0x08)


#define bt1         (GPIO_PORTE_DATA_R&0x01)
#define bt2         (GPIO_PORTE_DATA_R&0x02)
#define bt3         (GPIO_PORTE_DATA_R&0x04)
#define bt4         (GPIO_PORTE_DATA_R&0x08)

#define led1        1
#define led2        2
#define led3        4
#define led4        8

//#define buzzer  (GPIOF->DATA=0x0C)
//#define random PE4
