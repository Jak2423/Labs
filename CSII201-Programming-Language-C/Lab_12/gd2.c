#include <stdio.h>
#include <math.h>

typedef struct  {
   int x, y;
}Point;

typedef struct {
   double A, B, C;
} Triangle_P;

double distance(Point a, Point b){
   double d;
   d = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
   return d;
}

double find_Area(Triangle_P g) {
   double p, s;
   p = (g.A + g.B + g.C) / 2;
   s = sqrt(p * (p - g.A) * (p - g.B) * (p - g.C));

   return s;
}

int main() {
   Point a, b, c;
   Triangle_P t;

   printf("A tseg: ");
   scanf("%d %d", &a.x, &a.y);
   printf("B tseg: ");
   scanf("%d %d", &b.x, &b.y);
   printf("C tseg: ");
   scanf("%d %d", &c.x, &c.y);

   t.A = distance(b, c);
   t.B = distance(c, a);
   t.C = distance(a, b);

   printf("Gurvaljnii talbai: %.2lf\n", find_Area(t));

}  