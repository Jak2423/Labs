#include <stdio.h>
#include <math.h>

int main(){
   double a, b, c, d, res;

   scanf("%lf", &a);
   scanf("%lf", &b);
   scanf("%lf", &c);
   scanf("%lf", &d);
   
   res = (sqrt((a * a * a + b / c) * (a * a * a + b / c) + d) / (d * d - (a * b / c))) * d;

   printf("Хариу: %0.2lf\n", res);
   
   return 0;
}