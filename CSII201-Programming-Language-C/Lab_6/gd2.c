#include <stdio.h>

int main() {
   int i, j, n, rdiag, ldiag;

   printf("Husnegtin mur, baganii hemjeeg oruulna uu?\n");
   scanf("%d", &n);

   
   int arr[n][n], row[n], col[n];
   ldiag = 0;
   rdiag = 0;
   printf("Husnegtin elementiig oruulna uu?\n");
   for(i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         printf("[%d][%d]:", i, j);
         scanf("%d", &arr[i][j]);
      }
   }

   printf("Mur buriin niilber:\n");
   for(i = 0; i < n; i++) {
      row[i] = 0;
      for (j = 0; j < n; j++) {
         row[i] = row[i] + arr[i][j];
      }
   }

   for(i = 0; i < n; i++) {
      printf("%d ", row[i]);
   }
   printf("\n");
 
   printf("Bagana buriin niilber:\n");
   for(i = 0; i < n; i++) {
      col[i] = 0;
      for (j = 0; j < n; j++) {
         col[i] = col[i] + arr[j][i];
      }
   }

   for(i = 0; i < n; i++) {
      printf("%d ", col[i]);
   }
   printf("\n");

   printf("Zuun diagnoliin niilber:\n");
   for(i = 0; i < n; i++) {
      ldiag += arr[i][i];
   }
   printf("%d\n", ldiag);

   printf("Baruun diagnoliin niilber:\n");
   for(i = 0; i < n; i++) {
      for(j = 0; j < n; j++){
         if((i + j) == (n - 1)){
            rdiag += arr[i][j];
         }
      }
   }
   printf("%d\n", rdiag);

   return 0;
}