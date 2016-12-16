#include<stdio.h>
#include<string.h>
/*
[Desktop Entry]
Version=1.0
Name=Mega Man 8
Comment=Mega Man
#Lembrar de Alterar o Diretório
Exec=bash -c 'retroarch -L ~/.config/retroarch/cores/pcsx_rearmed_libretro.so /home/calebe94/JOGOS/PSX/"Mega Man 8"/"Mega Man 8.cue" $SHELL'
Terminal=false
Type=Application
Categories=Application;
#Lembrar de dar permissão "sudo chmod +x MIDI.desktop"
Icon=/home/calebe94/Imagens/mega-man8.jpg
*/

char Desktop_Entry[10][200] = {"[Desktop Entry]","Type=Application","Version=1.0","Name=","Comment=","Exec=","Terminal=","Type=","Categories=","Icon="};
int desktop_entry(char *game){
	unsigned int count = 0;
	game[strlen(game)-2] = '\0';
	snprintf(Desktop_Entry[3],30,"Name=%s",game); //Name
	snprintf(Desktop_Entry[4],30,"Comment=PSOne Game"); //Comment
	snprintf(Desktop_Entry[5],200,"Exec=bash -c 'retroarch -L ~/.config/retroarch/cores/pcsx_rearmed_libretro.so /home/calebe94/JOGOS/PSX/\"%s\"/\"%s.cue\" &SHELL'",game,game);
	snprintf(Desktop_Entry[6],30,"Terminal=false");
	snprintf(Desktop_Entry[7],30,"Type=Application");
	snprintf(Desktop_Entry[8],30,"Categories=Application");
	snprintf(Desktop_Entry[9],30,"Icon=");
	char desk_entry[200];
	snprintf(desk_entry,200,"%s.desktop",game);
	printf("Entrada:%s\n",desk_entry);
	FILE *games = fopen(desk_entry,"w+");
	if(games == NULL)	printf("Sem Entrada!\n");
	else{
		for(unsigned int count = 0 ; count < 10; count ++){
			fprintf(games,"%s\n",Desktop_Entry[count]);
		}
		fclose(games);
	}
}
int main(int argc,char *argv[]){
	FILE *arquivo = fopen("/home/calebe94/JOGOS/PSX/psx.bin","r");
	if(arquivo == NULL) printf("Sem Arquivo!\n");
	char *line;
	size_t len = 0;
	int read;
	while ((read = getline(&line, &len, arquivo)) != -1) {
		//printf("%s",line);
		desktop_entry(line);
	}
	
	fclose(arquivo);
}
