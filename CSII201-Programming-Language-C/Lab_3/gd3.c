#include <stdio.h>

int main() {

   int gend, m, h, d, r;
   printf("Eregtei bol 1, emegtai bol 0-g oruul.\n");
   scanf("%d", &gend);

   printf("Jingee oruul: (kg)\n");
   scanf("%d", &m);

   printf("Unduruu oruul: (cm)\n");
   scanf("%d", &h);

   if(gend == 1) {
      if (h > 150) {
         d = h - 150;
         r = d / 2.5 * 1.9 + 52;

         if (m > r) {
            printf("Iluudel jintei.\n");
         }
         if (m == r)
         {
            printf("Heviin jintei.\n");
         }
         else {
            printf("Heviin baih ystoi jingees baga bn.\n");
         }
      }
      else if(m > 52 && h < 150) {
         printf("Iluudel jintei.\n");
      }
      
   }
   else {
      if (h > 150) {
         d = h - 150;
         r = d / 2.5 * 1.9 + 49;

         if (m > r) {
            printf("Iluudel jintei.\n");
         }
         if (m == r)
         {
            printf("Heviin jintei.\n");
         }
         else {
         printf("Heviin baih ystoi jingees baga bn.\n");
         }
      }
      else if(m > 49 && h < 150) {
         printf("Iluudel jintei.\n");
      }
   }

   return 0;
}