#include"geniusAPI.h"
#include"adc.h"
#include"system.h"
#include"pwm.h"

#define DEBOUNCE 10

/*I'll add one more button just to look like the simon says'pocket version*/

//unsigned int queue[100]={};
//unsigned int index=0,iVerify=0,start_control=0,debug=0;
//unsigned int led_t0o_blink=0;

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
    game_init(&game);
    wait_to_start(&game);

    leds&=~0x0F; // desliga todos os leds
    another_delay(1000);
    while(game.start_control){

        execute(&game);

        verify(&game);
    }

}
unsigned int togled = 0;
unsigned int wait_to_start(GENIUS *this){

    //uint8_t led_to_blink = this->led_to_blink;
    uint8_t led_to_blink = 0;

    unsigned long Start=NVIC_ST_CURRENT_R;

    while((GPIO_PORTE_DATA_R&0xF)==0x00){

        unsigned long Elapsed = (Start-NVIC_ST_CURRENT_R)&0x00FFFFFF;
        if ( Elapsed < 70000){
            /*Solução Técnica alternativa para ler apenas os 4 primeiros bits do menos significante para o mais significante.*/
            togled = leds&0xF;

            if(togled&&~(1<<led_to_blink)){
                unsigned long Start=NVIC_ST_CURRENT_R;
                leds&=~0x0F;
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
        PWM_Tone(2272, 1136);
        another_delay(200);


        leds&=~0x0F;
        PWM_Tone(0, 0);
        another_delay(200);
    }
    this->start_control = 1;
    return 1;
}
void game_init(GENIUS *this){
    unsigned int count = 0;
    uint8_t index = this->index;
    for(count = 0 ; count < index; count++ )    this->queue[count] = 0;
    this->index = 0;
}
void verify(GENIUS *this){
    volatile uint8_t iVerify = this->iVerify;
    volatile uint8_t  index = this->index;
    do{
        if(bt1){
            while(bt1){
                Tones(bt1);
            }
            Tones(0);
            another_delay(DEBOUNCE);

            if(this->queue[iVerify]!=led1){
                leds|=led1;
                another_delay(1000);
                this->start_control = 0;
                You_Lose(*this,1);
                break;
            }
            else leds&=~led1;
            iVerify++;
         }
         else if(bt2){
             while(bt2){
                 Tones(bt2);
             }
             Tones(0);
             another_delay(DEBOUNCE);

             if(this->queue[iVerify]!=led2){
                 leds|=led2;
                 another_delay(1000);
                 this->start_control = 0;
                 You_Lose(*this,1);
                 break;
             }
             else leds&=~led2;
             iVerify++;
         }
         else if(bt3){
             while(bt3){
                 Tones(bt3);
             }
             Tones(0);
             another_delay(DEBOUNCE);

             if(this->queue[iVerify]!=led3){
                 leds|=led3;
                 another_delay(1000);
                 this->start_control = 0;
                 You_Lose(*this,1);
                 break;
             }
             else leds&=~led3;
             iVerify++;
         }
         else if(bt4){
             while(bt4){
                 Tones(bt4);
             }
             Tones(0);
             another_delay(DEBOUNCE);

             if(this->queue[iVerify]!=led4){
                 leds|=led4;
                 another_delay(1000);
                 this->start_control = 0;
                 You_Lose(*this,1);
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

void execute(GENIUS *this){
    uint8_t index = this->index;
    this->queue[index] = randomic();
    index++;
    if(index == 99) index = 0;
    another_delay(500);
    unsigned int count=0;
    for(count=0; count < index; count++){
        leds=this->queue[count];
        Tones(this->queue[count]);
        another_delay(300);
        leds=0x00;
        Tones(0);
        another_delay(100);
    }
    this->index = index;
}

void Tones(uint8_t which){
  switch (which) {
    case 0x01:
      PWM_Tone(5681, 2840);
      leds|=0x01;
      break;
    case 0x02:
      PWM_Tone(2840, 1420);
      leds|=0x02;
      break;
    case 0x04:
      PWM_Tone(1702, 851);
      leds|=0x04;
      break;
    case 0x08:
      PWM_Tone(2551, 1275);
      leds|=0x08;
      break;
    default:
      PWM_Tone(0, 0);
      leds&=~0x00;
      break;
  }
}
void You_Lose(GENIUS this,uint8_t option){
    uint8_t iCount;
    if(option==0){
      for(iCount=0;iCount<10;iCount++){
          PWM_Tone(9090,4545);
          another_delay(100);
          PWM_Tone(4545,2727);
          another_delay(100);
        }
        PWM_Tone(0,0);
      }else if(option == 1){
        for (iCount = 0; iCount < this.index; iCount++) {
            leds|=0x0F;
            PWM_Tone(9090,4545);
            another_delay(500);

            leds&=~(0x0F);
            PWM_Tone(4545,2727);
            another_delay(500);
        }
        PWM_Tone(0,0);
      }
}
