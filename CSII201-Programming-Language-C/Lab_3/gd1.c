#include <stdio.h>
#include <stdlib.h>

int main() {

   int n, ch, r, sum;
   printf("n toog oruulna uu:\n");
   scanf("%d", &n);
   
   if(n >= 100000){
      exit(0);
   }

   if(n % 2 != 0) {

      for (int n; n != 0; n = n / 10) {
         r = n % 10;
         sum += r;
      }

      if (sum % 3 == 0) {
         printf("3-t huvaagdana.\n");
      }
      else {
         printf("3-t huvaagdahgui.\n");
      }
   }
   else { 
      r = n % 100;
      if (r % 4 == 0) {
         printf("4-t huvaagdana.\n");
      }
      else {
         printf("4-t huvaagdahgui.\n");
      }
      
   }
   
   return 0;
}