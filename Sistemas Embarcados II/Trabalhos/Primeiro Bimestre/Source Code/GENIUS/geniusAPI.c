#include"geniusAPI.h"

void test(){
  if(bt1)       leds=bt1;

  else if(bt2)  leds=bt2;

  else if(bt3)  leds=bt3;

  else if(bt4)  leds=bt4;

  else          leds = 0;
}
void demonstration(){
    led1_On;  delay(100);
    led1_Off; delay(100);

    led2_On;  delay(100);
    led2_Off; delay(100);

    led3_On;  delay(100);
    led3_Off; delay(100);

    led4_On;  delay(100);
    led4_Off; delay(100);
}
void feed_random(unsigned int feed){
    srand((unsigned)feed);
}
unsigned int randomic(){
    return (1<<rand()%4);
}
