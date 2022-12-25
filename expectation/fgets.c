#include <stdio.h>  // C++ 의 경우 <cstdio>
char* fgets(char* str, int num, FILE* stream);

/* 화면에서 문자열을 읽어들인다. */

#include <stdio.h>
#define MAX_STR_SIZE 100
int main() {
  char str_read[MAX_STR_SIZE];
  fgets(str_read, MAX_STR_SIZE, stdin);
  printf("읽어들인 문자열 : %s \n", str_read);
  return 0;
}

/*

myfile.txt 에서 읽어들인 문자열을 출력한다.

*/
#include <stdio.h>
int main() {
  FILE* pFile;
  char mystring[100];

  pFile = fopen("myfile.txt", "r");
  if (pFile == NULL)
    perror("Error opening file");
  else {
    fgets(mystring, 100, pFile);
    puts(mystring);
    fclose(pFile);
  }
  return 0;
}
