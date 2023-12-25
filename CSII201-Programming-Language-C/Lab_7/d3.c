#include <stdio.h>

int main(){
   int n, i, e;

   printf("Husnegtiin hemjeeg oruulna uu?\n");
   scanf("%d", &n);
   
   int arr[n];

   printf("Hussnegtiin elementiig oruulna uu?\n");
   for(i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }
   e = 1;
   for(i = 0; i < n; i++) {
      n--;
      if(arr[i] != arr[n]) {
         e = 0;
         break;
      }
   }

   if(e == 1) {
      printf("Husnegt tegsh hemtei.\n");
   }
   else{
      printf("Husnegt tegsh hemtei bish.\n");
   }
}