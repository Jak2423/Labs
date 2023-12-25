#include <stdio.h>

int main() {

   int a, b, i, num;
   scanf("%d %d", &a, &b);

   for(int i = 2; i <= a && i <= b; i++) {
      if(a % i == 0 && b % i == 0) 
         num = i;
   }

   printf("HIEH = %d\n", num);

   return 0;
}