#include <stdio.h>  // C++ 에서는 <cstdio>
int fputs(const char* str, FILE* stream);

/* 화면에 str 의 내용을 출력한다. */
#include <stdio.h>
int main() {
  char str[] = "string to print \n";

  fputs(str, stdout);

  return 0;
}

/*

mylog.txt 에 (없으면 파일을 생성한다) 사용자로 부터 입력받은 문자열을 추가한다.
(기존의 파일 내용은 삭제되지 않고 끝에 덧붙인다)

*/

#include <stdio.h>
int main() {
  FILE* pFile;
  char sentence[256];

  printf("mylog.txt 에 추가할 문자열을 입력하세요: ");
  fgets(sentence, 255, stdin);
  pFile = fopen("mylog.txt", "a");
  fputs(sentence, pFile);
  fclose(pFile);
  return 0;
}
