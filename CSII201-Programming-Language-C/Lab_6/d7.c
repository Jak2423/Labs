#include <stdio.h>

int main() {
   int i, n, m, j;

   printf("A husnegtin hemjeeg oruulna uu?\n");
   scanf("%d", &n);
   printf("B husnegtin hemjeeg oruulna uu?\n");
   scanf("%d", &m);
   
   int arr1[n];
   int arr2[m];

   printf("A husnegtin elementiig oruulna uu?\n");
   for(i = 0; i < n; i++) {
      scanf("%d", &arr1[i]);
   }

   printf("B husnegtin elementiig oruulna uu?\n");
   for(i = 0; i < m; i++) {
      scanf("%d", &arr2[i]);
   }

   printf("B husnegtend baigaa A husnegtiin element: \n");
   for(i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
         if(arr1[i] == arr2[j]){
            printf("%d\n", arr1[i]);
            break;
         }
      }
   }

   return 0;
}