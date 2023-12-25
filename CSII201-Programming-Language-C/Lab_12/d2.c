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

void print(Date dt[], int n) {
   int i;
   for(i = 0; i < n; i++){
      if(dt[i].m < 10 && dt[i].d >= 10) {
         printf("%d/0%d/%d\n", dt[i].y, dt[i].m, dt[i].d);
      }
      else if(dt[i].d < 10 && dt[i].m >= 10) {
         printf("%d/%d/0%d\n", dt[i].y, dt[i].m, dt[i].d);
      }
      else if (dt[i].d < 10 && dt[i].m < 10) {
         printf("%d/0%d/0%d\n", dt[i].y, dt[i].m, dt[i].d);
      }
      else {
         printf("%d/%d/%d\n", dt[i].y, dt[i].m, dt[i].d);
      } 
   }
}

int main() {
   Date a[100];
   int n, i;
   scanf("%d", &n);
   for(i = 0; i < n; i++) 
      a[i] = read();

   print(a, n);

   return 0;
}