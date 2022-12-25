/*
Text file을 입력으로 하여 단어의 수를 출력하는 프로그램 count를 작성할 것.
source file은 'count.c'로 할 것
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	FILE *fptr;
	char ch;
	int count = 0;
	if (argc != 2) {
		printf("not enough arguements\n");
		exit(1);
	}
	fptr = fopen(argv[1],"r");
	while((ch = fgetc(fptr)) != EOF) {
		if (ch == ' ' || ch == '\t' || ch == '\n') {
			count++;
		}
	}
	fclose(fptr);

	printf("%d\n",count);
	return 0;
}
