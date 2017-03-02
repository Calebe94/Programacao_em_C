#include<stdio.h>

int main(void){
    char command[100];
    char file[] = "pluma";
    char get_data[1024];
    int status = 0 ;
    snprintf(command,100,"pgrep %s",file);
    FILE *pgrep = popen(command,"r");
    if(pgrep == NULL)   printf("Não Pode abrir o processo!\n");
    else{
        while(fgets(get_data,1024,pgrep)!=NULL){
            printf("%s",get_data);
        }
        status = pclose(pgrep);
        if(status == -1)    printf("Não fechou o progresso!\n");
        else return 0;
    }
    return 0;
}
