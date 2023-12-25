#include "sort.h"
void read(int a[], int n)
{
   int i;
   for (i = 0; i < n; i++)
      scanf("%d", &a[i]);
}

void print(int a[], int n)
{
   int i;
   for (i = 0; i < n; i++)
      printf("%d ", a[i]);
   printf("\n");
}

void insertion_sort(int a[], int n)
{
   int i, j, k;

   for (i = 1; i < n; i++)
   {
      k = a[i];
      j = i - 1;

      while (j >= 0 && k < a[j])
      {
         a[j + 1] = a[j];
         j--;
      }
      a[j + 1] = k;
   }
}

void selection_sort(int a[], int n)
{
   int i, j, min, temp;

   for (i = 0; i < n - 1; i++)
   {
      min = i;
      for (j = i + 1; j < n; j++)
      {
         if (a[j] < a[min])
         {
            min = j;
         }
      }
      if (min != i)
      {
         temp = a[min];
         a[min] = a[i];
         a[i] = temp;
      }
   }
}

void bubble_sort(int a[], int n)
{
   int i, j, temp;

   for (i = 0; i < n - 1; i++)
   {
      for (j = 0; j < n - i - 1; j++)
      {
         if (a[j + 1] < a[j])
         {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
         }
      }
   }
}
