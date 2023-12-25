#include <stdio.h>
#include <math.h>

int main(){
   int a, b, c;
   double d, x1, x2;

   scanf("%d", &a);
   scanf("%d", &b);
   scanf("%d", &c);
   
   d = b * b - 4 * a * c;
   x1 = (-b + sqrt(d)) / (2 * a);
   x2 = (-b - sqrt(d)) / (2 * a);

   printf("x1: %0.2lf; x2: %0.2lf\n", x1, x2);
   
   return 0;
}