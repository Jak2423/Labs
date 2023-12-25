#include<stdio.h>

int max(int a[], int n) {
   int max, i;
   max = a[0];

   for(i = 1; i < n; i++) {
      if(max < a[i]) {
         max = a[i];
      }
   }

   return max;
}

int main(){
   int n1, n2, i, amax, bmax;

   printf("A husnegtiin hemjee: \n");
   scanf("%d", &n1);
   printf("B husnegtiin hemjee: \n");
   scanf("%d", &n2);

   int a[n1], b[n2];

   printf("A husnegtiin element oruul: \n");
   for (i = 0; i < n1; i++) {
      scanf("%d", &a[i]);
   }
   printf("B husnegtiin element oruul: \n");
   for (i = 0; i < n2; i++) {
      scanf("%d", &b[i]);
   }

   amax = max(a, n1);
   bmax = max(b, n2);

   if(amax > bmax)
      printf("A husnegtend hamgiin tom toog aguulj bn. \n");
   else 
      printf("B husnegtend hamgiin tom toog aguulj bn. \n");
   
   return 0;
}  

