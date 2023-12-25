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

void find(int a[], int n, int *min, int *max) {
   int i;
   *min = a[0];
   *max = a[0];
   for(i = 1; i < n; i++) {
      if(*min > a[i])
         *min = a[i];
      if(*max < a[i])
         *max = a[i];
   }
}

int main() {
   int a[100], n, x, y;
   scanf("%d", &n);
   
   read(a, n);
   print(a, n);
   find(a, n, &x, &y);

   printf("Hamgiin baga too: %d\n", x);
   printf("Hamgiin ih too: %d\n", y);

   return 0;
}