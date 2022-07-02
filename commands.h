#include <stdio.h>


FILE* File_Command();
char OpenFile_Command();
void Command_Control();



FILE* File_Command(){
	char FileName[20];
	printf("Name File>");
	scanf("%s", &FileName);
	FILE *file_User = fopen(FileName, "w");
    fclose(file_User);
}	

char OpenFile_Command(){
	char Open_FileName[20];
	char Text[100];
	FILE* File_Open;
	printf("Open File:");
	scanf("%s", &Open_FileName);
	File_Open = fopen(Open_FileName,"w");
	printf("You Enter in Edit Mode:\n");
	scanf(" %[^\t\n]s", &Text);
	fprintf(File_Open, Text);
	if(Open_FileName == NULL)printf("File Not Found!");
	else fclose(File_Open);

}	



