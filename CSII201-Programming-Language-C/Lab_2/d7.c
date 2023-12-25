#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
   int num, count;
   scanf("%d", &num);
   count = num  > 0;

   ((count && abs(num) < 10) && printf("1 orontoi.\n")) || ((abs(num) < 100) && printf("2 orontoi.\n")) || ((abs(num) < 1000) && printf("3 orontoi.\n")) || ((abs(num) < 10000) && printf("4 orontoi.\n")) || ((abs(num) < 100000) && printf("5 orontoi.\n")) || ((abs(num) < 1000000) && printf("6 orontoi.\n")) || ((abs(num) < 10000000) && printf("7 orontoi.\n")) || ((abs(num) < 100000000) && printf("8 orontoi.\n")) || ((abs(num) < 1000000000) && printf("9 orontoi.\n")) ||((abs(num) < 2147483647) && printf("10 orontoi.\n"));
   
   return 0;
}