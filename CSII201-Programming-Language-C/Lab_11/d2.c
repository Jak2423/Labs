#include <stdio.h>
#include <math.h>

struct  Point {
   int x, y;
};

double distance(struct Point a,  struct Point b){

   double d;
   d = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
   return d;

}


int main() {
   struct Point a, b;

   printf("A tseg: ");
   scanf("%d %d", &a.x, &a.y);
   printf("B tseg: ");
   scanf("%d %d", &b.x, &b.y);
   
   printf("Hoorondoh zai: %.2lf\n", distance(a, b));

   return 0;
}