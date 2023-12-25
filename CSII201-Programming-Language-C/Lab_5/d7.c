#include <stdio.h>

int main()   {
   int i, n, bool;

   bool = 1;
   scanf("%d", &n);

   if (n <= 1) {
      bool = 0;
   }
   
   for (i = 2; i <= n; i++) {
      if (n % i == 0)
         bool = 0;
         break;
   }

   if (bool == 1)
      printf("Anhni too mun.\n");
   else 
      printf("Anhni too bish.\n");

   return 0;
}