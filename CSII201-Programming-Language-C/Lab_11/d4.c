#include <stdio.h>

struct Rational {
   int d, n;
};



typedef struct Rational Rational;

Rational simplify(struct Rational a);

Rational add(struct Rational a, struct Rational b) {
   struct Rational c, x;
   c.d = a.d * b.n + b.d * a.n;
   c.n = a.n * b.n;

   

   return simplify(c);
}

Rational sub(struct Rational a, struct Rational b) {
   struct Rational c;
   c.d = a.d * b.n - b.d * a.n;
   c.n = a.n * b.n;
   
   return c;
}

Rational mul(struct Rational a, struct Rational b) {
   struct Rational c;
   c.d = a.d * b.d;
   c.n = a.n * b.n;

   return c;
}

Rational div(struct Rational a, struct Rational b) {
   struct Rational c;

   c.d = a.d * b.n;
   c.n = a.n * b.d;

   return c;
}

Rational simplify(struct Rational a) {
   int i, gcd;

   for(i = 1; i <= a.n && i <= a.d; i++){
      
      if(a.n % i == 0 && a.d % i == 0) {
         gcd = i;
      }
   }

   a.n /= gcd;
   a.d /= gcd;

   return a;
}

void print(struct Rational a) {
   printf("%d/%d\n", a.d, a.n);
}

int main() {
   Rational a, b;

   printf("Ehnii butarhai: ");
   scanf("%d %d", &a.d, &a.n);
   printf("Hoyrdah butarhai: ");
   scanf("%d %d", &b.d, &b.n);
   
   printf("Niilber: ");
   print(simplify(add(a, b)));
   printf("Yalgavar: ");
   print(simplify(sub(a, b)));
   printf("Urjver: ");
   print(simplify(mul(a, b)));
   printf("Noogdvor: ");
   print(simplify(div(a, b)));
   
   return 0;
}