#include <stdio.h>
#include <math.h>

int main(){
   double a, b, angle, c, arg;
   
   scanf("%lf", &a);
   scanf("%lf", &b);
   scanf("%lf", &angle);
  
   arg = (angle * 3.14) / 180;
   c =  sqrt(b * b + a * a - 2 * a * b * cos(arg));

   printf("Гурвалжны талын урт: %0.2lf\n", c);
   
   return 0;
}