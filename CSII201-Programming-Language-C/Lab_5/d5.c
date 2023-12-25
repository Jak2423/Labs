#include <stdio.h>

int main() {
   int i, j, n;
   scanf("%d", &n);

   for(i = 1; i <= n; i++) {

      for(j = i; j < n + i; j++){
         if(j % 2 == 1)
            printf("x");
         else 
            printf("o");
      }
      printf("\n");  
   }

   return 0;
}