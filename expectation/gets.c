#include <stdio.h>  // C++ 에서는 <cstdio>

char* gets(char* str);

/* 사용자로 부터 문자열을 입력받는다.  */
#include <stdio.h>
int main() {
  char str[100];
  printf("당신의 이름은 무엇인가요? ");
  gets(str);
  printf("만나서 반가워요 %s 님 \n", str);
  return 0;
}


