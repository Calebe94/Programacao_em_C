#include<stdio.h>

int main(void){
	enum meses_do_ano{Janeiro=1,Fevereiro,Marco,Abril,Maio,Junho,Julho,Agosto,
	Setembro,Outubro,Novembro,Dezembro}meses;
	
	for(unsigned int count = Janeiro;count < Dezembro +1; count++){
		printf("Mês:%d\n",count);
	}
	printf("Outubro é o Mês:%d\n",Outubro);
}
