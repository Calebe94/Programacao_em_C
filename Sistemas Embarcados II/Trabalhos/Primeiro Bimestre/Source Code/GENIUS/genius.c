#include"geniusAPI.h"
#include"adc.h"
#include"system.h"
#include"pwm.h"

#define DEBOUNCE 10

/*I'll add one more button just to look like the simon says'pocket version*/

unsigned int queue[100]={};
unsigned int index=0,iVerify=0,start_control=0,debug=0;
unsigned int led_to_blink=0;

GENIUS game;

void setup(){
    PortB();
    PortE();
    SysTick_Init();
    ADC0_Init();
    feed_random(ADC0_Read());
    PWM_Init();
}
void loop(){
    game_init();
    start_control = wait_to_start();

    leds&=~0x0F; // desliga todos os leds
    another_delay(1000);
    while(start_control){

        execute();

        verify();
    }

}
unsigned int togled = 0;
unsigned int wait_to_start(){

    unsigned long Start=NVIC_ST_CURRENT_R;

    while((GPIO_PORTE_DATA_R&0xF)==0x00){

        unsigned long Elapsed = (Start-NVIC_ST_CURRENT_R)&0x00FFFFFF;
        if ( Elapsed < 70000){
            togled = leds&0xF;

            if(togled&&~(1<<led_to_blink)){
                unsigned long Start=NVIC_ST_CURRENT_R;
                leds&=~0x0F;
                //leds&=~(1<<led_to_blink);
                led_to_blink++;
            }
            else if(togled||(1<<led_to_blink)){
                leds|=(1<<led_to_blink);
                unsigned long Start=NVIC_ST_CURRENT_R;
            }
            if(led_to_blink>3)  led_to_blink=0;
        }

    }
    //Will blink the 4 LEDs for 1600 milli Seconds
    register uint8_t iBlink=0;
    for(iBlink=0; iBlink < 4;iBlink++){
        leds|=0x0F;
        another_delay(200);

        leds&=~0x0F;
        another_delay(200);
    }

    return 1;
}
void game_init(){
    unsigned int count = 0;
    for(count = 0 ; count < index; count++ )    queue[count] = 0;
    index = 0;
}
void verify(){
    do{
        if(bt1){
            while(bt1){
                leds|=bt1;
                //Toca Ton
            }
            another_delay(DEBOUNCE);

            if(queue[iVerify]!=led1){
                start_control = 0;
                //toca Som de derrota
                another_delay(1000);
                break;
            }
            else leds&=~led1;
            iVerify++;
         }
         else if(bt2){
             while(bt2){
                 leds|=bt2;
                 //Toca Ton
            }
             another_delay(DEBOUNCE);

             if(queue[iVerify]!=led2){
                 //toca som de derrota
                 another_delay(1000);
                 start_control = 0;
                 break;
             }
             else leds&=~led2;
             iVerify++;
         }
         else if(bt3){
             while(bt3){
                 leds|=bt3;
                 //Toca Ton
            }
             another_delay(DEBOUNCE);

             if(queue[iVerify]!=led3){
                 start_control = 0;
                 // toca som de derrota
                 another_delay(1000);
                 break;
             }
             else leds&=~led3;
             iVerify++;
         }
         else if(bt4){
             while(bt4){
                 leds|=bt4;
                 //Toca Ton

            }
             another_delay(DEBOUNCE);

             if(queue[iVerify]!=led4){
                 start_control = 0;
                 //Toca som de derrota
                 another_delay(1000);
                 break;
             }
             else leds&=~led4;
             iVerify++;
         }
         else leds=0;
    }while(iVerify != index);
    iVerify=0;
    another_delay(200);
}

void execute(){
    queue[index] = randomic();
    if(index == 99) index = 0;
    index++;
    another_delay(500);
    unsigned int count=0;
    for(count=0; count < index; count++){
        leds=queue[count];
        //Toca Ton
        another_delay(300);
        leds=0x00;
        another_delay(100);
    }
}
