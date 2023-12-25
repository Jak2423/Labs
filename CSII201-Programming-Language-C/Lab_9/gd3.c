#include <stdio.h>

void read(int A[], int n) {
   int i;
   printf("Husnegtiin elementiig oruul: ");
   for(i = 0; i < n; i++) {
      scanf("%d", &A[i]); 
   }
}

void print(int A[], int n) {
   int i;
   printf("Husnegtiin elementuud: ");
   for(i = 0; i < n; i++) {
      printf("%d ", A[i]);
   }
   printf("\n");
}

int join(int A[], int B[], int n, int m) {
   int size, i, j;
   size = n + m;
   j = 0;

   for(i = n; n < size; n++) {
      A[n] = B[j];
      j++;
   }

   return size;
}

int main() {
   int a[100], b[100], n, m;

   scanf("%d", &n);
   read(a, n);
   print(a, n);
   scanf("%d", &m);
   read(b, m);
   print(b, m);

   int k = join(a, b, n ,m);
   print(a, k);

   return 0;
}