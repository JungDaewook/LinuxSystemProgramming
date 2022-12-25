/* stdout (표준 출력) 에 p 를 쓴다.*/
#include <stdio.h>
int main() {
  char ch = 'p';

  putc(ch, stdout);

  return 0;
}

/*

alphabet.txt 에 (없다면 파일을 생성해서) A 부터 Z 까지 쓴다.
 
#include <stdio.h>
int main() {
  FILE* pFile;
  char c;

  pFile = fopen("alphabet.txt", "wt");
  for (c = 'A'; c <= 'Z'; c++) {
    putc(c, pFile);
  }
  fclose(pFile);
  return 0;
}
*/
