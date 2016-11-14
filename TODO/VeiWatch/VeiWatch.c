#include"VeiWatch.h"

char Temp_Report[4][15]={"Hypothermia","Normal","Fever","Hyperpyrexia"};

char *isNormal(float Temp){
	while(Temp < 35.0)	return Temp_Report[0];
	while(Temp > 36.2 && Temp < 37.6)	return Temp_Report[1];
	while(Temp > 37.6 && Temp < 38.3)	return Temp_Report[2];
	while(Temp > 40.0)	return Temp_Report[3];
}
int getnum(void){
	while(!kbhit()){}
	return getchar()-48;	
}
int getch(void){
	while(!kbhit()){}
	return getchar();
}
int kbhit(void){
  struct termios oldt, newt;
  int ch=0;
  int oldf;
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
