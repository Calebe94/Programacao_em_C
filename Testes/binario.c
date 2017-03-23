#include<stdio.h>
#include<stdlib.h>
int main(void){
    int dec = 1;
    while(1){
        int in=0;
        scanf("%d",&in);
        system("clear");
        int bin = (1<<in);
        printf("%d\n",bin);
    }
    //int bin = dec&(1<<1);
    
}