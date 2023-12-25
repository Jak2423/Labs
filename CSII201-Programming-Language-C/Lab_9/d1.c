#include <stdio.h>

int is_even(int a) {
   if (a % 2 == 0) 
      return 1;
   else
      return 0;
}

int main() {
   int num, i;
   scanf("%d", &num);

   for(i = 0; i <= num; i++) {
      if(is_even(i) == 0) {
         printf("%d ", i);
      }
   }
   
   return 0;
}

