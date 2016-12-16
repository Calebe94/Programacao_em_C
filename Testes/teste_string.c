#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int strToNum(char *string_to_num){
	while (*string_to_num) {
    	if (isdigit(*string_to_num)){ 
    	    long val = strtol(string_to_num, &string_to_num, 10); 
			return val;
    	} else  string_to_num++;
	}
}
int main(void){
	char string[]={"Teste da Minha String 10"};
	int valor = 0;
	valor = strToNum(string);
	printf("Há Esse numero na minha string: %d \n",valor);
}
