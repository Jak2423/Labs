#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char str[100];
   gets(str);

   int i, count, len;

   len = strlen(str);

   count = 0;

   for (i = 0; i < len + 1; i++)
   {
      str[i] = tolower( str[i]);

      if(str[i] != ' '){
         if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            count++;
         }
      }
   }
   printf("%d egshig baina.\n", count);
}
