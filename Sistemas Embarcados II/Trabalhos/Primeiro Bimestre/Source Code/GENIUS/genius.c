#include"geniusAPI.h"
#include"adc.h"
#include"system.h"

#define DEBOUNCE 10

unsigned int queue[100]={};
unsigned int index=0,iVerify=0,start_control=0,debug=0;
unsigned int led_to_blink=0;


void setup(){
    PortB();
    PortE();
    SysTick_Init();
    ADC0_Init();
    feed_random(ADC0_Read());
}
void loop(){
    game_init();
    start_control = wait_to_start();

    leds = 0; // desliga todos os leds
    delay(1000);
    while(start_control){

        execute();

        verify();
    }

}
unsigned int wait_to_start(){

    unsigned long Now=0;      // 24-bit time at this call (12.5ns)
    unsigned long Last=0;     // 24-bit time at previous call (12.5ns)
    unsigned long Elapsed=0;  // 24-bit time between calls (12.5ns)
    NVIC_ST_RELOAD_R = 0x00FFFFFF;
    NVIC_ST_CURRENT_R = 0;


    while((GPIO_PORTE_DATA_R&0xF)==0x00){
        Now = NVIC_ST_CURRENT_R;
        Elapsed = (Last-Now)&0x00FFFFFF;
        if ( Elapsed > 8388499){
            Last = Now;

            if(leds&(1<<led_to_blink) == (1<<led_to_blink))
                leds&=~(1<<led_to_blink);
            else
                leds|=(1<<led_to_blink);

            led_to_blink++;
            if(led_to_blink>3)  led_to_blink=0;
        }

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
            while(bt1){leds=bt1;}
            delay(DEBOUNCE);

            if(queue[iVerify]!=led1){
                start_control = 0;
                delay(1000);
                break;
            }
            //else leds=0;
            else leds&=~led1;
            iVerify++;
         }
         else if(bt2){
             while(bt2){leds=bt2;}
             delay(DEBOUNCE);

             if(queue[iVerify]!=led2){
                 delay(1000);
                 start_control = 0;
                 break;
             }
             //else leds=0;
             else leds&=~led2;
             iVerify++;
         }
         else if(bt3){
             while(bt3){leds=bt3;}
             delay(DEBOUNCE);

             if(queue[iVerify]!=led3){
                 start_control = 0;
                 delay(1000);
                 break;
             }
             //else leds=0;
             else leds&=~led3;
             iVerify++;
         }
         else if(bt4){
             while(bt4){leds=bt4;}
             delay(DEBOUNCE);

             if(queue[iVerify]!=led4){
                 start_control = 0;
                 delay(1000);
                 break;
             }
             //else leds=0;
             else leds&=~led4;
             iVerify++;
         }
         else leds=0;
    }while(iVerify != index);
    iVerify=0;
    delay(200);
}

void execute(){
    queue[index] = randomic();
    if(index == 99) index = 0;
    index++;
    delay(500);
    unsigned int count=0;
    for(count=0; count < index; count++){
        leds=queue[count];
        delay(300);
        leds=0;
        delay(100);
    }
}
