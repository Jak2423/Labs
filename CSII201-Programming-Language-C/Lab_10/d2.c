#include <stdio.h>

int count(char n) {
   int i, count;
   count = 0;
   
   for(i = 1; i <= n; i++) {
      if(n % i == 0) {
         count++;
      }
   }

   return count;
}

int main() {
   int num;
   scanf("%d", &num);

   printf("%d huvaagchtai.\n", count(num));

   return 0;
}