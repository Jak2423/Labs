#include <stdio.h>

int main() {
   int i, j, l, m, n, k, toot;

   printf("Bairnii ortsnii toog oruulna uu?\n");
   scanf("%d", &k);
   printf("Davhriin toog oruulna uu?\n");
   scanf("%d", &n);
   printf("Davhar buriin ailiin toog oruulna uu?\n");
   scanf("%d", &m);
   
   
   int arr[k][n][m];
   
   for(i = 0; i < k; i++) {
      toot = 1;
      for (j = 0; j < n; j++) {
         for(l = 0; l < m; l++) {
            arr[i][j][l] = toot;
            toot++;
         }
      }
   }

   for(i = 0; i < k; i++) {
      for (j = 0; j < n; j++) {
         for(l = 0; l < m; l++) {   
             printf("[Orts: %d][Davhar: %d][Toot: %d]\n", i + 1, j + 1, arr[i][j][l]);

         }
      }
   }

   return 0;
}