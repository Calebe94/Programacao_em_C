#include<stdio.h>
#include<stdlib.h>
char *getString(){
    char * my_string;
    int lenght;
    size_t my_lenght; 
    
    lenght = getline(&my_string,&my_lenght,stdin);
    return my_string;
}
int main(void){
    char *minha_string = getString();
    if(minha_string)    printf("%s\n",minha_string);
}