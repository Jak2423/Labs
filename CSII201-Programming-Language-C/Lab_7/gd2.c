#include <stdio.h>

int main(){
   int n, m, i, j, k;

   printf("Husnegtiin mur, baganii hemjeeg oruulna uu?\n");
   scanf("%d", &n);   
   
   int arr[n][n];

   for(i = 0; i < n; i++) {
      k = i + 1;
      for(j = 0; j < n; j++){
         arr[i][j] = k;
         if(k == n){
            while(j < n){
               arr[i][j] = k;
               k--;
               printf("%d ", arr[i][j]);
               j++;
            }
            break;
         }
         k++;
         printf("%d ", arr[i][j]);
      }
      printf("\n");
   }
   
}