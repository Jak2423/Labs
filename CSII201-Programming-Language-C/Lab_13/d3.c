#include <stdio.h>

void read(int a[], int n) {
   int i;
   for(i = 0; i < n; i++) {
      scanf("%d", &a[i]); 
   }
}

void print(int a[], int n) {
   int i;
   for (i = 0; i < n; i++) {
      printf("%d ", a[i]);
   }
   printf("\n");
}

void find(int a[], int n, int *addr, int *addr1) {
   int i, t, s;
   t = 0;
   s = 0;
   for(i = 0; i < n; i++) {
      if(a[i] % 2 == 0)
         t++;
      else 
         s++;
   }
   *addr = t;
   *addr1 = s;
}

int main() {
   int a[100];
   read(a, 5);
   print(a, 5);
   int x, y;
   find(a, 5, &x, &y);
   printf("Tegsh toonuudiin too: %d\n", x);
   printf("Sondgoi toonuudiin too: %d\n", y);

   return 0;
}