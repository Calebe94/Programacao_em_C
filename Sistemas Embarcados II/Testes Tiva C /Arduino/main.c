#include"tiva_c.h"
int main(void){
    setup();
    do{
        loop();
        break;
    }while(1);
}