#include <stdio.h>

int main()   {
   int i, n, x, y, temp;
   scanf("%d", &n);

   
   for(y = 0; y * y <= n; y++){
      temp = n;
      temp += y * y;
      
      for(x = 0; x * x <= temp; x++){
         if(n / x * x == 0) {
            printf("x = %d, y = %d\n", x, y);
         }
      }
   }

   return 0;
}