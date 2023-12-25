#include<stdio.h>

void read(int a[], int n) {
   int i;
   for(i = 0; i < n; i++) {
      scanf("%d", &a[i]); 
   }

}

void print(int a[], int n) {
   int i;
   for (i = 0; i < n; i++) {
      printf("%d ", a[i]);
   }
   printf("\n");
   
}

int main(){
   int size1, size2;
   size1 = 5;
   size2 = 3;
   int a[size1], b[size2];

   printf("A husnegtiin elementiig oruulan uu: \n");
   read(a, size1);
   printf("B husnegtiin elementiig oruulan uu: \n");
   read(b, size2);
   printf("A husnegtiin element: \n");
   print(a, size1);
   printf("B husnegtiin element: \n");
   print(b, size2);

   return 0;
}  

