#include <stdio.h>

int main(){
   int a, b, add, sub, mul;
   float div;
   scanf("%d", &a);
   scanf("%d", &b);

   add = a + b;
   sub = a - b;
   mul = a * b;
   div = a % b;



   printf("a + b = %d\n", add);
   printf("a - b = %d\n", sub);
   printf("a * b = %d\n", mul);
   printf("a / b = %.2f\n", div);

   return 0;
}