#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void){
	while(1){
		system("cat /sys/class/thermal/thermal_zone0/temp");
		usleep(1000000);
	}
}
