#include <stdio.h>

int main(){

   int a, b, c;
   scanf("%d %d  %d", &a, &b, &c);
   
   c < b && a < c && printf("bolj ");
   (a % 3 == 0 ||  c % 5 == 3) && printf("bna. \n");

   return 0;
}