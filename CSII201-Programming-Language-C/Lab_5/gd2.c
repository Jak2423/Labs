#include <stdio.h>

int main() {
   int i, j, k, temp1, temp2;

   for(i = 1; i <= 100; i++){
      temp1 = i * i;

      for(j = 1; j <= i; j++){
         temp2 = temp1;
         temp2 -= j * j;

         for(k = 1; k <= j; k++) {
            if (temp2 == k * k)
               printf("%d %d %d\n", k, j, i);
         }
      }
   }

   return 0;
}