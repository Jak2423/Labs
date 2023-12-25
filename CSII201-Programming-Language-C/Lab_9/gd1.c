#include <stdio.h> 
int palind(int a) {
   int temp, res = 0, uld;
   temp = a;

   while(a != 0) {
      uld = a % 10;
      res = res * 10 + uld;
      a /= 10;
   }

   if(res == temp)
      return 1;
   else 
      return 0;
}

int main() {
   int num;

   scanf("%d", &num);

   if(palind(num) == 1) 
      printf("Palindrom too mun.\n");
   else
      printf("Palindrom too bish.\n");
}