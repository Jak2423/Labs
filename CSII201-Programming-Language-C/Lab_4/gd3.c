#include <stdio.h>

int main() {

   int i, j;

   j = 1;
   
   for(int i = 1; i <= 31; i++) {
      printf("%d ", i);

      if(i == 8)
         printf("(Buh niitiin amralt) ");

      switch (j) {
      case 0:
         printf("Davaa\n");
         break;
      case 1:
         printf("Myagmar\n");
         break;
      case 2:
         printf("Lhagva\n");
         break;
      case 3:
         printf("Purev\n");
         break;
      case 4:
         printf("Baasan\n");
         break;
      case 5:
         printf("Byamba (Amralt)\n");
         break;
      case 6:
         printf("Nyam (Amralt)\n");
         break;
      }
      j++;

      if(j == 7)
         j = 0;
   }

   return 0;
}