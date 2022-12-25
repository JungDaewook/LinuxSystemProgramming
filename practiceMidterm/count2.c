#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
   if (argc != 2) {
      printf("argc != 2");
      exit(1);
   }

   FILE *src;
   if ((src = fopen(argv[1], "rt")) == NULL) {
      perror("fopen");
      exit(1);
   }

   int ch;
   int was_space = 1;
   int is_space;
   int result = 0;
   while ((ch = getc(src)) != EOF) {
      is_space = isspace(ch) ? 1 : 0;
      if (was_space == is_space) {// 두 번 연속 글자거나 둘 다 빈칸
         continue;
      }
      else if (is_space) { // 현재 빈 칸이면
         was_space = 1;
         result++;
      }
      else { // 현재 빈 칸이 아니면
         was_space = 0;
      }
   }
   printf("%d\n", result);

   fclose(src);

   return 0;
}
