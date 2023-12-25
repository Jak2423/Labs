#include <stdio.h>

int main(){

   int num, temp1, temp2, r;
   scanf("%d", &num);

   temp1 = num / 100;
   temp2 = num  % 10 * 10;
   r = num % 100 / 10;
   temp2 = temp2 + r;

   (temp1 == temp2) && printf("1\n") || printf("0\n");
}