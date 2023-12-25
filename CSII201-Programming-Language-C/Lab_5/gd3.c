#include <stdio.h>

int main(){

   int n, i, j, k;
   scanf("%d", &n);

   for(i = 1; i <= n; i++){
      k = 0;
      for(j = 1; j <= n - i; j++){
         printf(" ");
      }

      while(k != 2 * i - 1){
         printf("x");
         k++;
      }
      printf("\n");
   }
   return 0;
}
 
 4 1
 4 % i


 5