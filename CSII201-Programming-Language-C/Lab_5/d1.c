#include <stdio.h>

int main(){

   int m;
   scanf("%d", &m);

   switch (m) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
         printf("31n udurtei\n");
         break;
      case 2:
         printf("28n udurtei\n");
         break;
      case 4:
      case 6:
      case 9:
      case 11:
         printf("30n udurtei\n");
         break;
         
      default:
         break;
   }
}

