#include <stdio.h>

int main() {
   int i, n, m, j = 0, k, size;

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
   }
   printf("B husnegtin elementiig oruulna uu?\n");
   for(i = 0; i < m; i++) {
      scanf("%d", &arr2[i]);
   }

   for(i = 0; i < n; i++) {
      arr3[j] = arr1[i];
      j++;
   }
   for(i = 0; i < m; i++) {
      arr3[j] = arr2[i];
      j++;
   }

   for(i = 0; i < size; i++) {
      for(j = i + 1; j < size;) {
         if(arr3[i] == arr3[j]) {
            for(k = j; k < size; k++) {
               arr3[k] = arr3[k+1];
            }
            size--;
         } else {
            j++;
         }
      }
   }
   
   printf("\nA bolon B husnegtiin negdel: ");
   for(i=0; i < size; i++){
      printf("%d ", arr3[i]);
   }
   printf("\n");
   return 0;
}