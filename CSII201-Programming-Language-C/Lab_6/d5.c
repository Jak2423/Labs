#include <stdio.h>

int main() {
   int i, j, n, a, d;

   printf("Husnegtin hemjeeg oruulna uu?\n");
   scanf("%d", &n);

   int arr[n];

   printf("Husnegtin elementiig oruulna uu?\n");
   for(i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }
   i = 0;
   a = 1;
   d = 1;
   while((a == 1 || d == 1) && i < n - 1) {
      if(arr[i] < arr[i + 1])
         d = 0;
      else if(arr[i] > arr[i + 1])
         a = 0;
      i++;
   }

   if (a == 1){
      printf("Husnegt ushuur eremblegdsen.\n");
   }
   else if(d == 1){
      printf("Husnegt buurhaar eremblegdsen.\n");
   }
   else {
      printf("Husnegt eremblegdeegui.\n");
   }
   
   
   

   return 0;
}