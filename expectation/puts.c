#include <stdio.h>  // C++ 에서는 <cstdio>

int puts(const char* str);

/* 화면에 str 의 내용을 출력한다 */
#include <stdio.h>

int main() {
  char str[] = "Hello, World!";
  puts(str);
  return 0;
}
