#include <stdio.h>

int power(int a, int b) {
   int i, t;
   t = 1;
   for (i = 1; i <= b; i++) {
      t *= a;
   }

   return t;
}

int main() {
   int n, a;

   scanf("%d%d", &a, &n);
   printf("%d\n", power(a, n));

   scanf("%d%d", &a, &n);
   printf("%d\n", power(a, n));

   return 0;
}

