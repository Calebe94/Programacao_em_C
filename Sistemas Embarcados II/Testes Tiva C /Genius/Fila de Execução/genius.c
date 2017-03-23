#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"genius.h"

unsigned int queue[100]={};
unsigned int index;
void re_do(){
    index = 0;
}
void print(){
    printf("%d\n",queue[6]);
}
unsigned int feed_random(unsigned int feed){
    srand((unsigned)feed);
    //queue[index] = randomic();
    //index++;
}
unsigned int randomic(){
    return (1<<rand()%4);
}
void execute(){
    queue[index] = randomic();
    index++;
    for(register unsigned int count=0 ;count < index; count++){
        //printf("%d\n",queue[count]);
    }
}
