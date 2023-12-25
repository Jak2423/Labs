#include <stdio.h>

int main() {
   int n, i, sum, dig;
   scanf("%d", &n);

   sum = 0;

   while(n != 0){
      dig = n % 10;
      sum += dig;
      n /= 10;
   }
   printf("%d\n", sum);

   return 0;
}