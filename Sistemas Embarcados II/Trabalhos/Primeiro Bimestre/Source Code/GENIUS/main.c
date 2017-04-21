#include"geniusAPI.h"

/*
 * Complexidade de Algorítmo total do Projeto: f(n) = 6n² + 106n + 210
 * */

/*
 * Complexidade de Algorítmo total do arquivo main.c: f(n) = 3n² + 7n + 8
 * */

/*
 * Complexidade de Algorítmo setup(): f(n) = 6
 * */
void setup(){
    PortB();
    PortE();
    SysTick_Init();
    ADC_Init();
    feed_random(ADC_Read());
    PWM_Init();
}
/*
 * Complexidade de Algorítmo main(): 3n²+ 7n + 2
 * */
int main(void){

    GENIUS game;

    setup();
    
    do{
        
        game_init(&game);
        wait_to_start(&game);

        leds&=~0x0F;
        delay(1000);
        while(game.start_control){

            execute(&game);

            verify(&game);
        }
        
    }while(1);
    
}
