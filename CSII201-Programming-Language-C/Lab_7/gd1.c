#include <stdio.h>

int main() {
   int n, m, i, j;

   printf("Husnegtiin muriin hemjeeg oruulna uu?\n");
   scanf("%d", &n);
   printf("Husnegtiin baganii hemjeeg oruulna uu?\n");
   scanf("%d", &m);
      
   int arr[n][m];

   for(i = 0; i < n; i++) {
      for(j = 0; j < m; j++){
         arr[i][j] = i + 1;
         printf("%d ", arr[i][j]);
      }
      printf("\n");
   }

   
  
   
}