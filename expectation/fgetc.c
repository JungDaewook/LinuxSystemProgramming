#include <stdio.h>  // C++ 에서는 <cstdio>

int fgetc(FILE* stream);/*

stdin 에서 문자를 입력받는다.

*/
#include <stdio.h>
int main() {
  int i = fgetc(stdin);

  printf("입력 값 : %c \n", i);
  return 0;
}
/*

myfile.txt 에서의 $ 의 개수를 센다
참고로, http://www.cplusplus.com/reference/clibrary/cstdio/fgetc/
에서 가져온 예제입니다.

*/
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
      c = fgetc(pFile);
      if (c == '$') n++;
    } while (c != EOF);
    fclose(pFile);
    printf("The file contains %d dollar sign characters ($).\n", n);
  }
  return 0;
}
