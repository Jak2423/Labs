#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
   char s1[100], s2[100];
   gets(s1);
   gets(s2);

   int len, i;
   len = strlen(s1);

   for (i = 0; s2[i] != '\0'; i++)
   {
      s1[len+i] = s2[i];
   }
   s1[len + i] = '\0';

   printf("%s", s1);
}