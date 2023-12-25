#include <stdio.h>

int main(){
   int n, i, avg, sum, count;

   printf("Huuhduudiin toog oruulna uu?\n");
   scanf("%d", &n);
   
   int arr[n];
   sum = 0;
   count = 0;

   printf("Huuhduudiin unduriig oruulna uu?\n");
   for(i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
      sum += arr[i];
   }
   avg = sum / n;
   
   for(i = 0; i < n; i++) {
      if(arr[i] > avg) {
         count++;
      }
   }
   printf("Dundjaas deesh undertei %d huuhed baina.\n", count);
}