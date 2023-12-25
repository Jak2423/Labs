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

int udriin_zoruu(Date a, Date b) {
   int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   int i, n1, n2;

   n1 = a.y * 365 + a.d;
   for(i = 0; i < a.m - 1; i++)
      n1 += mdays[i];

   n2 = b.y * 365 + b.d;
   for(i = 0; i < b.m - 1; i++)
      n2 += mdays[i];

   return (n1 - n2);
}

int main() {
   Date a, b;

   a.y = 2022;
   a.m = 7;
   a.d = 11;
   b = read();
   printf("Udriin zoruu: %d\n", udriin_zoruu(a, b));

   return 0;
}