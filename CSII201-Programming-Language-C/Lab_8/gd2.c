#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char str[100];
   gets(str);
   
   int i, count, max, word, v, len;

   len = strlen(str);
   str[len] = ' ';

   max = 0;
   word = 0;
   
   for (i = 0; i <  len + 1; i++){
      str[i] = tolower( str[i]);
      
      if(str[i] != ' '){ 
         if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            count++;
         }
      }
      else {
         word += 1;
         if(max < count) {
            max = count;
            count = 0;
            v = word;
         }
      }
      
   }

   printf("%d-r ug hamgiin olon egshigtei.\n", v);
   return 0;
}
