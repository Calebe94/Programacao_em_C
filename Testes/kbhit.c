#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <termios.h>
int kbhit(void);
int main(void){
	while(1){
		while(!kbhit()){}
		printf("Você pressionou '%c'!\n",getchar());	
	}	
}
int kbhit(void){
  struct termios oldt, newt;
  int ch=0;
  int oldf;
  static int chamada;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF){
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}
