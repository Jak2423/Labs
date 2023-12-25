#include <stdio.h>
#include <math.h>

int main() {

   int x1, y1, x2, y2, x3, y3;
   double z1, z2, z3;

   printf("1deh tseg: \n");
   scanf("%d %d", &x1, &y1);

   printf("2dah tseg: \n");
   scanf("%d %d", &x2, &y2);

   printf("3dah tseg: \n");
   scanf("%d %d", &x3, &y3);

   z1 = ((x1 - 0) * (x1 - 0) + (y1 + 0) * (y1 + 0));
   z2 = ((x2 - 0) * (x3 - 0) + (y2 + 0) * (y2 + 0));
   z3 = ((x3 - 0) * (x3 - 0) + (y3 + 0) * (y3 + 0));

   if(z1 > z2 && z1 > z3) {
      printf("x1, y1 bol hamgiin hol tseg. \n");
   }
   else if (z2 > z3) {
      printf("x2, y2 bol hamgiin hol tseg. \n");
   }
   else {
      printf("x3, y3 bol hamgiin hol tseg. \n");
   }

   if(z1 < z2 && z1 < z3) {
      printf("x1, y1 bol hamgiin oirhon tseg. \n");
   }
   else if (z2 < z3) {
      printf("x2, y2 bol hamgiin oirhon tseg. \n");
   }
   else {
      printf("x3, y3 bol hamgiin oirhon tseg. \n");
   }
   
   return 0;
}