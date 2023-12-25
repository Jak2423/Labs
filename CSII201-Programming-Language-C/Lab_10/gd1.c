#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void read_2darray(int a[][100], int n, int m) {
   int i, j;
   for(i = 0; i < n; i++)
      for(j = 0; j < m; j++)
         scanf("%d", &a[i][j]);
} 

void print_2darray(int a[][100], int n, int m) {
   int i, j;
   for(i = 0; i < n; i++) {
      for(j = 0; j < m; j++)
         printf("%d ", a[i][j]);
      printf("\n");
   }
}

void min(int a[][100], int n, int m, int row[] , int col[]) {
   int i, j, r_min, c_min;

   for(i = 0; i < n; i++) {
      r_min = a[i][0];
      for(j = 0; j < m; j++) {
         if(r_min > a[i][j]) {
            r_min = a[i][j];
         }
      }
      row[i] = r_min;
   }

   for(i = 0; i < m; i++) {
       c_min = a[0][i];
      for(j = 0; j < n; j++) {
         if(c_min > a[j][i]) {
            c_min = a[j][i];
         }
      }
      col[i] = c_min;
   }
}

int main() {
   int c_row, c_col, i;
   int A[100], B[100];
   int C[100][100];

   printf("husnegtiin mur, baganiig toog oruul: ");
   scanf("%d%d", &c_row, &c_col);

   read_2darray(C, c_row, c_col);
   print_2darray(C, c_row, c_col);

   min(C, c_row, c_col, A, B);

   printf("Mur buriin hamgiin baga: \n");
   for(i = 0; i < c_row; i++) {
      printf("%d-r muriin hamgiin baga: %d\n", i, A[i]);
   }

   printf("Bagana buriin hamgiin baga: \n");
   for(i = 0; i < c_col; i++) {
      printf("%d-r baganii hamgiin baga: %d\n", i, B[i]);
   }

   return 0;
}