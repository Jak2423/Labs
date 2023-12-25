#include <stdio.h>

int main() {
   int i, n, m, size, k;

   printf("A husnegtin hemjeeg oruulna uu?\n");
   scanf("%d", &n);
   printf("B husnegtin hemjeeg oruulna uu?\n");
   scanf("%d", &m);
   
   size = n + m;
   int arr1[n];
   int arr2[m];
   int arr3[size];

   printf("A husnegtin elementiig oruulna uu?\n");
   for(i = 0; i < n; i++) {
      scanf("%d", &arr1[i]);
      arr3[i] = arr1[i];
   }

   k = i;

   printf("B husnegtin elementiig oruulna uu?\n");
   for(i = 0; i < m; i++) {
      scanf("%d", &arr2[i]);
      arr3[k] = arr2[i];
      k++;
   }

   printf("C husnegt:\n");
   for(i = 0; i < size; i++) {
      printf("%d ", arr3[i]);
   }
   printf("\n");

   return 0;
}