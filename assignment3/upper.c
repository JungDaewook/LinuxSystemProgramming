#include <stdio.h>
#include <string.h>
#include <ctype.h>	//for using toupper(int)

int main() {
	FILE *fptr;
	char filename[30];
	int ch;
	
	strcpy(filename,"uppertest.txt");	//copy filename
	fptr = fopen(filename,"r");			//open file

	printf("Reading uppertest.txt and uppering it... \n");
	printf("------result------\n");
	
	while((ch = fgetc(fptr)) != EOF) {	//iteration while the file is end
		ch = toupper(ch);				//upper char in file
		printf("%c", (char)ch);			//print uppered char
	}
	fclose(fptr);						//close file

	return 0;
}
