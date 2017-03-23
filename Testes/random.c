#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    int feed = 30;
    srand((unsigned)feed);
    for(register unsigned int count =0 ;count < 10 ;count ++){
        printf("%d\n",(1<<rand()%4));
    }
}