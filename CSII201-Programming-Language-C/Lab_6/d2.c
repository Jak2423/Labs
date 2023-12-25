#include <stdio.h>

int main() {
   int i, size;
   scanf("%d", &size);

   int arr[size];

   for(i = 0; i < size; i++) {
      scanf("%d", &arr[i]);
   }

   for(i = size - 1; i >= 0; i--) {
      printf("%d ", arr[i]);
   }
   printf("\n");

   return 0;
}