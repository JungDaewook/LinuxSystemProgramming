/*
String의 문자를 모두 대문자로 바꾸는 void strupper(char str[]) 함수를 작성하고
그 예를 보이는 프로그램 'upper'를 작성할 것. Source file은 upper.c로 할 것.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void strupper(char str[]){
	int i=0;
	while(str[i] != '\0') {
		if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
		printf("%c",str[i]);
		i++;
	}
	printf("\n");
}

int main () {
	char str[] = "hello, world!";
	strupper(str);
	return 0;
}
