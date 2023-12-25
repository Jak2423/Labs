#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char str[100];
   gets(str);

   int i, len, end, start = 0;

   len = strlen(str);

   for (i = 0; i <= len; i++){
      printf("%c", str[i]);
      if (str[i] == ' ')
      {
         printf("\n");
      }
   }

   return 0;
}

