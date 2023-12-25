#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char str[100];
   gets(str);

   int i, count, len;
   len = strlen(str);
   str[len] = ' ';
   count = 0;

   for (i = 0; i <= len; i++){
      if(str[i] == ' '  && str[i + 1] != ' ') {
         count++;
      }
   }
   
   printf("%d\n", count);
   return 0;
}

