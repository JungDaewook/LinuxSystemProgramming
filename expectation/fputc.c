#include <stdio.h>  //C++ 의 경우 <cstdio>
int fputc(int character, FILE* stream);

/* 표준출력(stdout) 에 문자열을 출력한다 */
#include <stdio.h>

int main() {
  char str[20] = "hello every1";
  int i = 0;

  while (str[i]) {
    fputc(str[i], stdout);
    i++;
  }

  return 0;
}

/*
alphabet.txt 라는 파일을 (없으면) 생성하고 A 부터 Z 까지 쓴다.
참고로 이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/fputc/
에서 가져왔습니다.
*/
#include <stdio.h>
int main() {
  FILE* pFile;
  char c;

  pFile = fopen("alphabet.txt", "w");
  if (pFile != NULL) {
    for (c = 'A'; c <= 'Z'; c++) {
      fputc((int)c, pFile);
    }
    fclose(pFile);
  }
  return 0;
}
