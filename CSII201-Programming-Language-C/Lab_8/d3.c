#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char str1[100], str2[100];
   gets(str1);
   gets(str2);

   int i, len1, len2, e = 1;

   len1 = strlen(str1);
   len2 = strlen(str2);

   if(len1 == len2) {
      for (i = 0; i < len1 + 1; i++) {
         str1[i] = tolower(str1[i]);
         str2[i] = tolower(str2[i]);

         if(str1[i] != str2[i]){
            e = 0;
            printf("Adilhan ug bish.\n");
            break;
         }
      }
      if(e) {
         printf("Adhilhan ug.\n");
      }
   }
   else {
      printf("Adilhan ug bish.\n");
   }

}
