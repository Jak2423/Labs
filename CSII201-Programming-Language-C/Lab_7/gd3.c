#include <stdio.h>

int main() {
   int n, m, k, i, j, l;

   printf("A matrixiin muriin hemjeeg oruulna uu?\n");
   scanf("%d", &n);
   printf("A matrixiin baganiin, B matrixiin muriin hemjeeg oruulna uu?\n");
   scanf("%d", &m);
   printf("B matrixiin baganiin hemjeeg oruulna uu?\n");
   scanf("%d", &k);
   

   int arr1[n][m];
   int arr2[m][k];
   int mul[n][k];

   printf("A matrixiin elementiig oruulna uu?\n");
   for(i = 0; i < n; i++) {
      for(j = 0; j < m; j++){
         printf("[%d][%d]:", i, j);
         scanf("%d", &arr1[i][j]);
      }
   }

   printf("B matrixiin elementiig oruulna uu?\n");
   for(i = 0; i < m; i++) {
      for(j = 0; j < k; j++){
         printf("[%d][%d]:", i, j);
         scanf("%d", &arr2[i][j]);
      }
   }


   for(i = 0; i < n; i++) {
      for(j = 0; j < k; j++){
         mul[i][j] = 0;
         for(l = 0; l < m; l++){
            mul[i][j] += arr1[i][l] * arr2[l][j];
         }      
      }
   }

   printf("A, B matrixiin urjever:");
   for(i = 0; i < n; i++) {
      printf("\n");
      for(j = 0; j < k; j++){
         printf("%d ", mul[i][j]);
      }
   }
   printf("\n");
}