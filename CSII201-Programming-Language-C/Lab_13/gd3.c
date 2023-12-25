#include <stdio.h>

typedef struct {
   int d, n;
}Rational;

int gcd(int a, int b) {
   if(a == 0)
      return b;
   return gcd(b % a, a);
}

Rational simplify(Rational *a) {
   int h = gcd(a->d, a->n);
   a->n /= h;
   a->d /= h;

   return *a;
}

Rational add(Rational *a,Rational *b) {
   Rational c;
   c.d = a->d * b->n + b->d * a->n;
   c.n = a->n * b->n;

   return simplify(&c);
}

Rational sub(Rational *a, Rational *b) {
   Rational c;
   c.d = a->d * b->n - b->d * a->n;
   c.n = a->n * b->n;
   
   return simplify(&c);
}

Rational mul(Rational *a, Rational *b) {
   Rational c;
   c.d = a->d * b->d;
   c.n = a->n * b->n;

   return simplify(&c);
}

Rational div(Rational *a, Rational *b) {
   Rational c;
   c.d = a->d * b->n;
   c.n = a->n * b->d;

   return simplify(&c);
}

void read(Rational *a) {
   scanf("%d %d", &a->d, &a->n);
}

void print(Rational *a) {
   printf("%d/%d\n", a->d, a->n);
}

int main() {
   Rational a, b, n, s, m, d;

   printf("Ehnii butarhai: ");
   read(&a);
   printf("Hoyrdah butarhai: ");
   read(&b);
   
   n = add(&a, &b);
   s = sub(&a, &b);
   m = mul(&a, &b);
   d = div(&a, &b);

   printf("Niilber: ");
   print(&n);
   printf("Yalgavar: ");
   print(&s);
   printf("Urjver: ");
   print(&m);
   printf("Noogdvor: ");
   print(&d);
   
   return 0;
}