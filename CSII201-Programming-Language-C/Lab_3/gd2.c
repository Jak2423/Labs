#include <stdio.h>

int main() {

   int y, m, d;
   printf("On, sar uduruu oruulna uu:\n");
   scanf("%d %d %d", &y, &m, &d);

   if(y > 2022 || (y == 2022 && m > 3) ||(y == 2022 && m == 3 && d > 3)) {
      printf("Ireedui\n");
   }
   else if(y < 2022 || (y == 2022 && m < 3) ||(y == 2022 && m == 3 && d < 3)) {
      printf("Ungursun\n");
   }
   else {
      printf("Odoo\n");
   }

   return 0;
}