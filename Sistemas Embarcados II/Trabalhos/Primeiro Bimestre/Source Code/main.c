#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(void){
    time_t t;
    srand((unsigned) time(&t));
    int index = 0;
    int game[30];
    for(int count = 0; count < 10 ; count ++){
        game[index] = rand() % 4;
        index ++;
        for(int counter = 0 ; counter < index ; counter ++)
            printf("%d,");
        printf("\n");
    }
}
