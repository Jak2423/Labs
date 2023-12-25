#include <stdio.h>

int main() {
   int i, j, n, m, x, e;
   e = -1;
   printf("Husnegtin muriin hemjeeg oruulna uu?\n");
   scanf("%d", &n);
   printf("Husnegtin baganii hemjeeg oruulna uu?\n");
   scanf("%d", &m);
   
   int arr[n][m];

   printf("Husnegtin elementiig oruulna uu?\n");
   for(i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
         printf("[%d][%d]:", i, j);
         scanf("%d", &arr[i][j]);
      }
   }

   printf("Haih elementee oruulna uu?\n");
   scanf("%d", &x);

   for(i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
         if(arr[i][j] == x){
            printf("Mur: %d, Bagana: %d\n", i, j);
            e = 1;
         }
      }
   }

   if(e == -1) {
      printf("%d\n", e);
   }

   return 0;
}