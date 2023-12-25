#include <stdio.h>


int min5(int a, int b, int c) {
   if(a < b && a < c){
      return a;
   }
   else if(b < c) {
      return b;
   }
   else {
      return c;
   }
}


int main() {
   int num1, num2, num3;

   scanf("%d %d %d", &num1, &num2, &num3);
   printf("Hamgiin baga ni: %d\n", min5(num1, num2, num3));

   return 0;
}

