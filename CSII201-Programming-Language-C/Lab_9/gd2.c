#include <stdio.h>

int digit_sum(int n) {
   int uld, sum;
   sum = 0;

   while(n != 0) {
      uld = n % 10;
      sum += uld;
      n /= 10;
   }

   return sum;
}

int main() {
   int i, num, dig;

   scanf("%d", &num);

   for (i = 2; i < num; i++) {
      dig = digit_sum(i);

      if(i % dig == 0)
         printf("%d ", i);
   }
   
   return 0;
}