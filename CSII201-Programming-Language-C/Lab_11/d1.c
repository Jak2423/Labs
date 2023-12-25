#include <stdio.h>
#include <math.h>

struct  Triangle {
   int a, b, c;
};

int main() {
   float p, res, s1, s2;
   struct Triangle t1, t2;

   scanf("%d %d %d", &t1.a, &t1.b, &t1.c);
   scanf("%d %d %d", &t2.a, &t2.b, &t2.c);

   p = (t1.a + t1.b + t1.c) / 2;
   s1 = sqrt(p * (p - t1.a) * (p - t1.b) * (p - t1.c));

   p = (t2.a + t2.b + t2.c) / 2;
   s2 = sqrt(p * (p - t2.a) * (p - t2.b) * (p - t2.c));

   
   if(s1 > s2)
      printf("Ehnii gurvaljin ih talbaitai baina. Talbai: %.2lf\n", s1);
   else 
      printf("Hoyrdah Gurvaljin ih talbaitai baina. Talbai: %.2lf\n", s2);
   

   return 0;
}