#include <stdio.h>

int main() {
   int n, i;
   double f, c;
   scanf("%d", &n);

   f = 0;
   i = 0;
   
   while(f < n){
      f = 0.0;
      c = 9.0 / 5.0 * i + 32.0;
      f += c;
      if (f > n) 
         break;
      printf("%.1lf\n", f);
      i++;
   }
   
   return 0;
}