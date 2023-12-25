#include <stdio.h>

int main() {
   int i, n, x, e;

   e = -1;
   printf("Husnegtin hemjeeg oruulna uu?\n");
   scanf("%d", &n);

   int arr[n];

   printf("Husnegtin elementiig oruulna uu?\n");
   for(i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   printf("Haih elementee oruulna uu?\n");
   scanf("%d", &x);

   for(i = 0; i < n; i++) {
      if (arr[i] == x){
         printf("%d ", i);
         e = 1;
      }
   }

   if(e == -1) {
      printf("%d\n", e);
   }


   return 0;
}