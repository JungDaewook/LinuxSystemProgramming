#include <stdio.h>
#include <string.h>
#include <ctype.h>

void strupper(char str[]) {
	FILE *fptr;
	char filename[30];
	int ch;

	strcpy(filename, str);
	fptr =  fopen(filename,"r");

	while((ch = fgetc(fptr)) != EOF) {
		ch = toupper(ch);
		printf("%c", (char)ch);
	}
	fclose(fptr);
}

int main() {
	strupper("uppertest.txt");
	return 0; 
}
