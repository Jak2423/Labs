#include <stdio.h>

int main(){
   int n, m, i, j, count, e, max;

   printf("Husnegtiin muriin hemjeeg oruulna uu?\n");
   scanf("%d", &n);
   printf("Husnegtiin baganiin hemjeeg oruulna uu?\n");
   scanf("%d", &m);
   
   int arr[n][m];
   count = 0;
   max = 0;
   e = 0;

   printf("Husnegtiin elementiig oruulna uu?\n");
   for(i = 0; i < n; i++) {
      for(j = 0; j < m; j++){
         printf("[%d][%d]:", i, j);
         scanf("%d", &arr[i][j]);
      }
   }

   
   for(i = 0; i < m; i++) {
      for(j = 0; j < n; j++){
         if(arr[j][i] % 2 == 0) {
            count++;
         }
      }
      if (count > max) {
         max = count;
         e = i + 1;
      }
      count = 0;
   }

   printf("%d-eer bagana hamgiin ih tegsh too aguulsan.\n", e);
   
}