#include <stdio.h>

int A[100];
int prime_range(int a, int b){
   int count, i, j, e;
   count = 0;

   for(i = a + 1; i < b ;i++) {
      e = 0;
      for(j = 2; j <= i / 2; j++) {
         if(i % j ==0) {
            e = 1;
            break;
         }
      }
      if(e == 0) {
         A[count] = i;
         count++;
      }
   }

   return count;
}

int main() {
   int num1, num2, l, i;
   scanf("%d %d", &num1, &num2);

   l = prime_range(num1, num2);

   for(i = 0; i < l; i++) {
      printf("%d ", A[i]);
   }

   return 0;
}