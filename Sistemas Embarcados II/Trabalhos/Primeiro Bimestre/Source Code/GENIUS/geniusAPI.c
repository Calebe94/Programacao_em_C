#include"geniusAPI.h"

/*
 * Complexidade de Algorítmo total do arquivo geniusAPI.c = f(n) = 2n² + 92n + 76
 * */

/*
 * Complexidade de Algorítmo feed_random(): f(n) = 1
 * */
void feed_random(unsigned int feed){
    srand((unsigned)feed);
}

/*
 * Complexidade de Algorítmo randomic(): f(n) = 4
 * */
unsigned int randomic(){
    return (1<<rand()%4);
}

/*
 * Complexidade de Algorítmo wait_to_start(): f(n) = 33n + 10
 * */
unsigned int wait_to_start(GENIUS *this){
    volatile uint8_t togled = 0;
    volatile uint8_t led_to_blink = 0;

    unsigned long Start=NVIC_ST_CURRENT_R;

    while((GPIO_PORTE_DATA_R&0xF)==0x00){

        unsigned long Elapsed = (Start-NVIC_ST_CURRENT_R)&0x00FFFFFF;
        if ( Elapsed < 70000){
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
    register uint8_t iBlink=0;
    for(iBlink=0; iBlink < 4;iBlink++){
        leds|=0x0F;
        PWM_Tone(2272, 1136);
        delay(200);


        leds&=~0x0F;
        PWM_Tone(0, 0);
        delay(200);
    }
    this->start_control = 1;
    return 1;
}

/*
 * Complexidade de Algorítmo game_init(): f(n) = 4n + 7
 * */
void game_init(GENIUS *this){
    unsigned int count = 0;
    for(count = 0 ; count < 22; count++ )    this->queue[count] = 0;
    this->index = 0;
    this->level = 0;
    this->delay = 500;
}

/*
 * Complexidade de Algorítmo verify(): f(n) = 2n² + 23n + 5
 * */
void verify(GENIUS *this){
    volatile uint8_t iVerify = this->iVerify;
    volatile uint8_t iIndex  = this->index;
    do{
        volatile uint32_t pressed=(GPIO_PORTE_DATA_R&0xF);
        if(pressed!= 0x00){
            while(GPIO_PORTE_DATA_R&(pressed)){
                Tones(pressed);
            }
            Tones(0);
            if(this->queue[iVerify]!=pressed){
                leds|=pressed;
                delay(1000);
                this->start_control = 0;
                You_Lose(*this);
                pressed=(GPIO_PORTE_DATA_R&0xF);
                break;
            }else leds&=~pressed;
            iVerify++;
        }else leds=0;
    }while(iVerify!=iIndex);
    this->iVerify=0;
}

/*
 * Complexidade de Algorítmo execute(): f(n) = 10n + 21
 * */
void execute(GENIUS *this){
    uint8_t index = this->index;
    uint16_t delay_ms = this->delay;
    this->queue[index] = randomic();
    index++;
    if(index == 20){
        index = 0;
        this->level++;
        if(this->level == 3){
            this->level = 0;
            congratulations(this);
        }
        this->delay-=150;
    }

    delay(delay_ms);
    unsigned int count=0;
    for(count=0; count < index; count++){
        leds=this->queue[count];
        Tones(this->queue[count]);
        delay(300);
        leds=0x00;
        Tones(0);
        delay(100);
    }
    this->index = index;
}

/*
 * Complexidade de Algorítmo Tones(): f(n) = 20
 * */
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

/*
 * Complexidade de Algorítmo You_Lose(): f(n) = 11n + 3
 * */
void You_Lose(GENIUS this){
    uint8_t iCount;
    for (iCount = 0; iCount < this.index; iCount++) {
        leds|=0x0F;
        PWM_Tone(9090,4545);
        delay(500);

        leds&=~(0x0F);
        PWM_Tone(4545,2727);
        delay(500);
    }
    PWM_Tone(0,0);
}

/*
 * Complexidade de Algorítmo congratulations(): f(n) = 11n + 5
 * */
void congratulations(GENIUS *this){
    uint8_t iCount;
    for(iCount=0;iCount<10;iCount++){
        leds|=0x0F;
        PWM_Tone(9090,4545);
        delay(100);
        leds&=~0x0F;
        PWM_Tone(4545,2727);
        delay(100);
    }
    PWM_Tone(0,0);
    this->level = 0;
    this->start_control=0;
}
