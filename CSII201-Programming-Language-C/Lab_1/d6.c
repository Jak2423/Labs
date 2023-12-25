#include <stdio.h>
#include <math.h>

int main(){
   int a, b, c, d;
   float res;

   scanf("%d", &a);
   scanf("%d", &b);
   scanf("%d", &c);
   scanf("%d", &d);

   res = sqrt((a + b) * (a + b) + d) / c;
   printf("Хариу: %f\n", res );

   return 0;
}