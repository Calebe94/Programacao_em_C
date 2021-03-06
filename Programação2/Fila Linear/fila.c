#include"fila.h"
bool iniciar(unsigned int tamanho,fila *qual){
	qual->tamanho = tamanho;
	qual->elementos = (int*)malloc(sizeof(int)*tamanho);
	qual->fim = qual ->inicio =0;
	return qual->elementos!=0;
}
bool push(int info,fila *qual){ // Para fila Linear 
	if(cheia(*qual))	return false;
		qual->elementos[qual->fim] = info;
		qual->fim++;
		return true;
	/*if(cheia(qual)!=false){
		qual->elementos[quem->fim] = (int*)malloc(sizeof(int));
		qual->elementos[quem->fim] = (int)info;
		qual->fim++;
		return true;
	}else return false;*/
}
bool pop(fila *qual){
	if(vazia(*qual))	return false;
	qual->inicio++;
	return true;
}
int	*listar(fila qual){
	if(vazia(qual))	return false;
	int *retorno = (int*)malloc(sizeof(int)*(qual.fim-qual.inicio));
	for(int elem=qual.inicio;elem<qual.fim;elem++)		retorno[elem - qual.inicio] = qual.elementos[elem];
	return retorno;
}
bool cheia(fila qual){
	return qual.fim == qual.tamanho;
}
bool vazia(fila qual){
	return qual.fim == qual.inicio;
}
