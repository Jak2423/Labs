#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count(char s[]) {
   int i, count, len;
   count = 0;
   len = strlen(s);

   for (i = 0; i <  len; i++){
      s[i] = tolower(s[i]);
         if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y'){
            count++;
      }
   }  

   return count;
}

int main() {
   char str[100];
   gets(str);

   printf("Temdegtiin tsuvaa %d egshigtei baina.\n", count(str));

   return 0;
}