#include <stdio.h>

int main(){
   int a, b, c;
   scanf("%d %d %d", &a, &b, &c);

   (a == b && b == c && a == c) && printf("Zuv gurvaljin.\n");
   (a != b && b != c && a != c) && printf("Eldev talt gurvaljin.\n");
   ((a == b && b != c) || (a == c && c != b) || (b == c && b != a)) && printf("Adil hajuut gurvaljin.\n");
   
   return 0;
}