#include <stdio.h>

typedef struct {
   int d, m, y;
} Date;

Date read() {
   Date c;
   printf("On / sar / udur: ");
   scanf("%d %d %d", &c.y, &c.m, &c.d);

   return c;
}

void print(Date dt) {
   if(dt.m < 10 && dt.d >= 10) {
      printf("%d/0%d/%d\n", dt.y, dt.m, dt.d);
   }
   else if(dt.d < 10 && dt.m >= 10) {
      printf("%d/%d/0%d\n", dt.y, dt.m, dt.d);
   }
   else if (dt.d < 10 && dt.m < 10) {
      printf("%d/0%d/0%d\n", dt.y, dt.m, dt.d);
   }
   else {
      printf("%d/%d/%d\n", dt.y, dt.m, dt.d);
   } 
}

int main() {
   Date dt;
   dt = read();
   print(dt);

   return 0;
}