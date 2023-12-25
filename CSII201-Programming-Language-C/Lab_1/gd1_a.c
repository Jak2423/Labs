#include <stdio.h>

int main(){
   double a, h, s;

   printf("Гурвалжны суурь:\n");
   scanf("%lf", &a);
   printf("Гурвалжны өндөр:\n");
   scanf("%lf", &h);
   
   s = (a * h) / 2;

   printf("Гурвалжны суурь: %0.2f\n", s);
   
   return 0;
}