#include <stdio.h>

int main() {
   int n, i, res;
   scanf("%d", &n);
   res = 0;

   for(i = 1; i <= n; i++){
      if (i % 2 == 0){
         res += i;
      }
   }
   printf("%d\n", res);
   return 0;
}