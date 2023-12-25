#include <stdio.h>

int count(char n, int A[]) {
   int i, j, count;
   count = 0;
   j = 0;
   for(i = 1; i <= n; i++) {
      if(n % i == 0) {
         A[j] = i; 
         count++;
         j++;
      }
   }

   return count;
}

int main() {
   int num, arr[100], size, i;
   scanf("%d", &num);
   
   size = count(num, arr);

   for(i = 0; i < size; i++) {
      printf("%d ", arr[i]);
   }   

   return 0;
}