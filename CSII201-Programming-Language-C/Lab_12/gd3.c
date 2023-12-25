#include <stdio.h>
#include <math.h>

typedef struct{
   int dim;
   float dat[100];
} Vector;

int dot_product(Vector a, Vector b){
   int dot, i;
   dot = 0;

   for (i = 0; i < a.dim; i++) {
      dot += a.dat[i] * b.dat[i];
   }
   
   return dot;
}

Vector scalar_multi(Vector a, int t) {
   int i; 
   Vector m;

   for(i = 0; i < a.dim; i++)
      m.dat[i] = a.dat[i] * t; 

   return m;
}

int len(Vector a) {
   int i, l;
   l = 0;
   for(i = 0; i < a.dim; i++) 
      l += a.dat[i] * a.dat[i];
   
   return sqrt(l);
}




int main() {
   Vector a, b, s;
   int i, k;
   printf("Vectoriin dimension: ");
   scanf("%d", &a.dim);
   printf("Scalar: ");
   scanf("%d", &k);

   for(i = 0; i < a.dim; i++) 
      scanf("%f", &a.dat[i]);

   for(i = 0; i < a.dim; i++) 
      scanf("%f", &b.dat[i]);
   
   printf("2 vectoriin dot urjver: %d\n", dot_product(a, b));
   printf("Vectoriin urt: %d\n", len(a));
   s = scalar_multi(a, k);

   return 0;
}