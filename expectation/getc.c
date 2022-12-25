/*

한 문자를 입력받은 후 이를 출력한다.

*/
#include <stdio.h>
int main() {
  int c;

  c = getc(stdin);

  printf("입력한 문자 : %c", c);

  return 0;
}

/*
#include <stdio.h>
int main() {
  FILE* pFile;
  int c;
  int n = 0;
  pFile = fopen("myfile.txt", "r");
  if (pFile == NULL)
    perror("Error opening file");
  else {
    do {
      c = getc(pFile);
      if (c == '$') n++;
    } while (c != EOF);
    fclose(pFile);
    printf("File contains %d$.\n", n);
  }
  return 0;
}
*/
