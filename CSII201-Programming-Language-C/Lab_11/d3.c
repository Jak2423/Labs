#include <stdio.h>
#include <math.h>

struct  Triangle {
   int a, b, c;
};

double find_Area(struct Triangle g) {
   double p, s;
   p = (g.a + g.b + g.c) / 2;
   s = sqrt(p * (p - g.a) * (p - g.b) * (p - g.c));

   return s;
}

int main() {
   double x, y;
   struct Triangle t1, t2;

   printf("Ehnii gurvaljin: ");
   scanf("%d %d %d", &t1.a, &t1.b, &t1.c);
   printf("Hoyrdah gurvaljin: ");
   scanf("%d %d %d", &t2.a, &t2.b, &t2.c);
   
   x = find_Area(t1);
   y = find_Area(t2);

   if(x > y)
      printf("Ehnii gurvaljin ih talbaitai baina. Talbai: %.2lf\n", x);
   else 
      printf("Hoyrdah Gurvaljin ih talbaitai baina. Talbai: %.2lf\n", y);
   
   return 0;
}