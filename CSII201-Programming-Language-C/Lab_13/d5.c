#include <stdio.h>

typedef struct{
   int a, b, c;
} Triangle;

void read(Triangle *p) {
   scanf("%d %d %d", &p->a, &p->b, &p->c );
}

int main() {
   Triangle g;
   read(&g);

   printf("%d %d %d\n", g.a, g.b, g.c);
   return 0;
}