#include <stdio.h>

int main() {

   int i, n, j, a[10], k, tmp;
   scanf("%d", &n);

   for(i = 0; i < n; i++) {
      scanf("%d", &a[i]);
   }

   for(i = 0; i < n; i++) {
      k = i;
      for(j = i + 1; j < n; j++) {
         if(a[k]  > a[j]) {
            k = j;
         }
      }
      tmp = a[k];
      a[k] = a[i];
      a[i] = tmp;
   }

   for(i = 0; i < n; i++) {
      printf("%d ", a[i]);
   }

   return 0;
}


/*
i: 0
j: 0
k: 
tmp: 
n: 5
a[0]: 2
a[1]: 4
a[2]: 1
a[3]: 3
a[4]: 5
*/
