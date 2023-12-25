#include <stdio.h>

void read(int a[], int n) {
   int i;
   for (i = 0; i < n; i++) {
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

int modul(int x) {
   if(x < 0) {
      return -x;
   }
   else {
      return x;
   }
}

int sum(int a[], int n) {
   int total, i;
   total = 0;

   for(i = 0; i < n; i++) {
      total += a[i];
   }

   return total;
}

int avg(int a[], int n) {
   int s, average;
   s = sum(a, n);

   average = s / n;

   return average;
}

int product(int a[], int n) {
   int i, result;
   result = 1;

   for(i = 0; i < n; i++) {
      result *= a[i];
   }

   return result;
}

int main() {
   int a[100], n, b[100];
   printf("n toonii utgiig oruul: ");
   scanf("%d", &n);
   read(a, n);
   printf("Tanii oruulsan utga: ");
   print(a, n);

   int mu, i;
   mu = avg(a, n);
   printf("mu-iin utga: %d\n", mu);

   for(i = 0; i < n; i++) {
      b[i] = modul(a[i] - mu);
   }

   int alpha;
   alpha = product(b, n);
   printf("alpha-iin utga: %d\n", alpha);

   return 0;
}