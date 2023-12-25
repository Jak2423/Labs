#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char str[100], wrd[100];
   int i, j, len1, len2, e;

   printf("Oguulberee oruulna uu?\n");
   gets(str);
   printf("Haih ugee oruulna uu?\n");
   gets(wrd);

   len1 = strlen(str);
   len2 = strlen(wrd);

  for(i = 0; str[i] != '\0'; i++) {
     
     if(str[i] == wrd[0]) {
        e = 1;

        for (j = 0; wrd[j] != '\0'; j++) {
           if(str[i + j] != wrd[j]) {
              e = -1;
              break;
           }
        }
     }

     if(e == 1) {
        break;
     }
  }

  if(e == -1) {
     printf("%d\n", e);
  }
  else{
     printf("Haisan ug temdegtiin tsuvaanii %d-s %d hurtel baina.\n", i, j + i);
  }
}


