#include<stdio.h>
void print_bin(int number){
    int valor = 0;
        for (int count_bin = 0 ;count_bin < 32 ; count_bin ++){
            valor=number&(1<<(count_bin));
            printf("%d",valor>0?1:0);
            //number=valor;
        }
}
int main(void){
    print_bin(32);
 /*   for (int count = 0 ; count < 32;count ++){
        int number = (1<<count);
        int valor = 0;
        printf("%d\t",number);
        for (int count_bin = 0 ;count_bin < 32 ; count_bin ++){
            valor=number&(1<<(31-count_bin));
            printf("%d",valor>0?1:0);
        }
        printf("\n");
    }
    */
}