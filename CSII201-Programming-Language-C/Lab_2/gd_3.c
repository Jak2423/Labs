#include <stdio.h>

int main(){

   int grade, ch;
   scanf("%d", &grade);

   ch = grade >= 0 && grade <= 100;

   ((ch && grade < 60) && printf("F\n")) ||
   ((grade < 70 )) && printf("D\n") ||
   ((grade < 80) && printf("C\n")) ||
   ((grade < 90) && printf("B\n")) ||
   ((grade <= 100) && printf("A\n"));
}