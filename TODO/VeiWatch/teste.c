#include"HeartBeat.h"
#include"VeiWatch.h"
#include"PCD8544.h"
#include"SystemClock.h"
#include<string.h>
struct Data{
	unsigned int BPM;
	float Temp;
	char *BPMState,*TempState;
	
}Sensors;
#define RST 7
#define CE 8
#define DC 25
#define DIN 24
#define CLK 23
#define contrast 50 	
void lcdDisplayMain(){
	/* Inicialização do Relógio do Sistema	*/
	char	Nokia_Temp[10],Nokia_BPM[10],INFO[]={"INFORMACOES"};
	int lenght = strlen(INFO);
	snprintf(Nokia_Temp,10,"%.1f*C",Sensors.Temp);
	snprintf(Nokia_BPM,10,"%dBPM",Sensors.BPM);	

	LCDclear();

	getClockInformation(&info);

	printf("Data:%s\n",info.date);
	printf("Hora:%s\n",info.time);
	printf("Temp:%.1f\n",Sensors.Temp);
	printf("BPM:%d\n",Sensors.BPM);

	LCDdrawstring(20,0,"PRINCIPAL");
	LCDdrawstring(0,13,Nokia_Temp);
	LCDdrawstring(50,13,Nokia_BPM);
	LCDdrawstring(0,26,info.date);
	LCDdrawstring(50,26,info.time);
	
	LCDdrawline(0, 35, 83, 35, BLACK);
	LCDsetCursor(0, 39);
	//LCDSet(WHITE,1);
	// Text Scroll 
	for(unsigned int cont = 0 ; cont < lenght ; cont ++){
		LCDwrite(INFO[cont]);		
		LCDdisplay();
		usleep(10000);
	}

	LCDdisplay();
}
int main(void){
	LCDInit(CLK, DIN, DC, CE,RST, contrast);
	struct sGENERAL patient;
	healthInit(MALE,2,&patient);
/*	printf("Excelente:%d\n",patient.Excellent);
	printf("%s\n",patient.Sex);
	unsigned int num = 1;
	char *string = healthState(patient,num);
	while(num!=0){
		scanf("%d",&num); 
		string = healthState(patient,num);
		printf("%s\n",string);
	}
*/
	Sensors.BPM = 90;
	Sensors.Temp = 37.8;
	Sensors.BPMState = healthState(patient,Sensors.BPM);
	Sensors.TempState = isNormal(Sensors.Temp);
	
//	printf("BPM:%s\n",Sensors.BPMState);
//	printf("Temp:%s\n",Sensors.TempState);
	lcdDisplayMain();
}