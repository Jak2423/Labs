#include <stdio.h>

int main(){

   int a, b, c, d, f;
   scanf("%d %d %d %d %d", &a, &b, &c, &d, &f);
   
   a || printf("o") && c;        // a 0 ued
   c && d || printf("x");        // c, d ali neg esvel hoyul 0 baih ued
   (d || b) && f || printf("x"); // f 0 ued esvel d, b hoyul 0 ued
   a + b == 1 && printf("x");    // a, b niilber 1 ued
   f && printf("o");             // f 0-s ylgaatai ued 
   b && d || printf("o");        // b, d ali neg esvel hoyul 0 ued 
   b + d == 3 && printf("o");    // b, d niilber 3 baih ued

   return 0;
}
// 0 2 1 1 1
