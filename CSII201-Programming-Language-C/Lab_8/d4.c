#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char s[] = "hello";
   char s2[20] = "MUIS-inhan";
   int i;

   for (i = 0; i < 20; i++) {
      s2[i] = s[i];
   }

   printf("%s\n", s2);

   return 0;
}
