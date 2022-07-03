#include <stdio.h>

#include <windows.h>

#include <string.h>

#include <conio.h>

#include "commands.h"

#define DELAY 500
void gotoxy(short x, short y);

void Start_OS();

void Prompt_Command();

void Command_Control(char * cmd);

int String_To_Asci(char * cmd);

void Login_User();

void main() {
  Start_OS();
  Prompt_Command();
}

void gotoxy(short x, short y) {
  COORD pos = {
    x,
    y
  };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Start_OS() {
  int i, dot_count;
  dot_count = 14;
  printf("Starting MS-DOS");
  for (i = 0; i < 5; i++) {
    printf(".");
    dot_count = dot_count + 1;
    gotoxy(dot_count, 0);
    Sleep(DELAY);
  }
  system("cls");
}



void Prompt_Command() {
  char command;
  while (1) {
    printf("\nC:>");
    scanf("%s",&command);
    Command_Control( &command);
  }
}

int String_To_Ascii(char* cmd) {
  int Ascii_Command, i;
  for (i = 1; i <4;i++) Ascii_Command = cmd[i];
  //printf("%d", Ascii_Command);
  return Ascii_Command;
}

void Command_Control(char* cmd) {
	FILE* fun_FileCommand;
  switch (String_To_Ascii(cmd)) {
  case 'p':
    printf("\nhelp		View All Commands\nping		send ICMP Packet to Another Pc\ndir 		View All Direcotry\nfile		make file\nopen		open and modify a file");
    break;
  case 101:
		fun_FileCommand = File_Command();
		break;
  case 110:
   OpenFile_Command(fun_FileCommand);
  	break;
   }
}
