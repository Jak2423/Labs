#include <stdio.h>

int main() {
   int n;
   scanf("%d", &n);

   switch (n % 2) {
      case 1:
         printf("Sondgoi too.\n");
         break;
      case 0:
         printf("Tegsh.\n");
         break;
      default:
         break;
   }

   return 0;
}