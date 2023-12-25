#include <stdio.h>
#include <stdlib.h>

int main()   {
   int i, j, n, p;
   scanf("%d", &n);

   if (n <= 1) {
      printf("Anhni too baihgui.\n");
      exit(0);
   }
   
   for (i = 2; i < n; i++) {
      p = 0;
      for (j = 2; j <= i; j++) {
         if(i % j ==0){
            p++;
         }
      }
      
      if(p == 1){
         printf("%d ", i);
      }
   }

   return 0;
}