#include "myinclude.h"

void read(int A[], int n)
{
   int i;
   for (i = 0; i < n; i++)
      scanf("%d", &A[i]);
}

void print(int A[], int n)
{
   int i;
   for (i = 0; i < n; i++)
      printf("%d ", A[i]);
   printf("\n");
}

int max(int A[], int n)
{
   int i, max = A[0];

   for (i = 1; i < n; i++)
   {
      if (max < A[i])
      {
         max = A[i];
      }
   }

   return max;
}

int min(int A[], int n)
{
   int i, min = A[0];

   for (i = 1; i < n; i++)
   {
      if (min > A[i])
      {
         min = A[i];
      }
   }

   return min;
}

void copy(int A[], int n, int B[])
{
   int i;

   for (i = 0; i < n; i++)
   {
      B[i] = A[i];
   }
}

int find(int A[], int n, int x)
{
   int i;
   for (i = 0; i < n; i++)
   {
      if (A[i] == x)
      {
         return i;
      }
   }

   return -1;
}

int make_set(int A[], int n, int B[])
{
   int i, j, check = 0, k = 0;

   for (i = 0; i < n; i++)
   {
      check = 0;
      for (j = 0; j < i; j++)
      {
         if (B[j] == A[i])
         {
            check = 1;
            break;
         }
      }
      if (check)
         continue;
      B[k] = A[i];
      k++;
   }

   return k;
}

int union_set(int A[], int n, int B[], int m)
{
   int i, j, k = n, check = 0;

   for (i = 0; i < m; i++)
   {
      check = 0;
      for (j = 0; j < k; j++)
      {
         if (A[j] == B[i])
         {
            check = 1;
            break;
         }
      }
      if (check == 1)
         continue;
      A[k] = B[i];
      k++;
   }

   return k;
}

int intersection_set(int A[], int n, int B[], int m, int C[])
{
   int i, j, k = 0, check = 0;

   for (i = 0; i < n; i++)
   {
      check = 0;
      for (j = 0; j < m; j++)
      {
         if (A[i] == B[j])
         {
            check = 1;
            break;
         }
      }
      if (check == 1)
      {
         C[k] = A[i];
         k++;
      }
   }

   return k;
}
