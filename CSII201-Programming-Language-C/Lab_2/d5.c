#include <stdio.h>

int main(){

   int a, b, c, max, min, mid;
   scanf("%d %d %d", &a, &b, &c);
   
   max = (a > b && a > c) * a + (b > a && b > c) * b + (c > a && c > b) * c;
   
   min = (a < b && a < c) * a + (b < a && b < c) * b + (c < a && c < b) * c;
   
    mid = (a > b && b > c) * b + (a < b && b < c) * b + (b > a &&  a > c) * a + (b < a &&  a < c) * a + (a > c && c > b) * c + (a < c && c < b) * c;

   printf("Max: %d, Mid: %d, Min: %d \n", max, mid, min);

   return 0;
}