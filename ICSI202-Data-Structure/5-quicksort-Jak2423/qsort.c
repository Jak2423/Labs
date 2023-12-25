#include "my_qsort.h"

/*
  quicksort эрэмбэлэх аргын цааш хуваагдах ёсгүй хэмжээ
*/
#ifndef CUTOFF
#define CUTOFF 10
#endif

static int init_seed = 0; // Random seed 1 удаа эхлүүлнэ

/*
  Оруулан эрэмбэлэх функц.
  [lo, hi] завсрах тоонуудыг оруулан эрэмбэлэх аргаар эрэмбэлнэ.
*/
static void insertion_sort(int a[], int lo, int hi)
{
   int i, j, temp;
   for (i = lo; i <= hi; i++)
   {
      temp = a[i];
      j = i;

      while (j > lo && temp < a[j - 1])
      {
         a[j] = a[j - 1];
         j--;
      }
      a[j] = temp;
   }
}

/*
  Хоёр утгыг хооронд солих функц
*/
static void swap(int *a, int *b)
{
   int tmp = *a;
   *a = *b;
   *b = tmp;
}

/*
  [lo, hi] завсрыг санамсаргүйгээр холих функц.
*/
static void random_shuffle(int a[], int lo, int hi)
{
   if (init_seed == 0)
   {
      srand(time(NULL));
      init_seed = 1;
   }
   int i, j;
   for (i = lo; i <= hi; i++)
   {
      j = rand() % (hi - lo) + lo;
      swap(&a[i], &a[j]);
   }
}

static int single_partition(int a[], int lo, int hi)
{
   int pivot = lo;
   int i = lo;
   int j = hi;

   while (i < j)
   {
      while (a[i] <= a[pivot] && i <= hi)
         i++;
      while (a[j] > a[pivot] && j >= lo)
         j--;

      if (i < j)
         swap(&a[i], &a[j]);
   }

   swap(&a[j], &a[pivot]);

   return j;
}

static int dual_partition(int a[], int lo, int hi, int *lp)
{
   if (a[lo] > a[hi])
      swap(&a[lo], &a[hi]);

   int j = lo + 1;
   int g = hi - 1, k = lo + 1, p = a[lo], q = a[hi];

   while (k <= g)
   {
      if (a[k] < p)
      {
         swap(&a[j], &a[k]);
         j++;
      }
      else if (a[k] >= q)
      {
         while (a[g] > q && k < g)
            g--;
         swap(&a[k], &a[g]);
         g--;
         if (a[k] < p)
         {
            swap(&a[k], &a[j]);
            j++;
         }
      }
      k++;
   }
   j--;
   g++;

   swap(&a[lo], &a[j]);
   swap(&a[hi], &a[g]);

   *lp = j;

   return g;
}

/*
  1-pivot хурдан эрэмбэлэх функц.
*/
static void _single_pivot_qsort(int a[], int lo, int hi)
{
   if (hi - lo <= CUTOFF)
      insertion_sort(a, lo, hi);

   if (hi > lo)
   {
      int pi;
      pi = single_partition(a, lo, hi);
      _single_pivot_qsort(a, lo, pi - 1);
      _single_pivot_qsort(a, pi + 1, hi);
   }
}

/*
  wrapper function for _single_pivot_qsort
  _single_pivot_qsort-ыг дуудахад ашиглах функц
 */
void single_pivot_qsort(int a[], int lo, int hi)
{
   random_shuffle(a, lo, hi);
   _single_pivot_qsort(a, lo, hi);
}

/*
  Dual-pivot хурдан эрэмбэлэх функц
*/
static void _dual_pivot_qsort(int a[], int lo, int hi)
{
   if (hi - lo <= CUTOFF)
      insertion_sort(a, lo, hi);

   if (hi > lo)
   {
      int lpi, rpi;

      rpi = dual_partition(a, lo, hi, &lpi);
      _dual_pivot_qsort(a, lo, lpi - 1);
      _dual_pivot_qsort(a, lpi + 1, rpi - 1);
      _dual_pivot_qsort(a, rpi + 1, hi);
   }
}
/*
  wrapper function for _dual_pivot_qsort
  _dual_pivot_qsort-ыг дуудахад ашиглах функц
*/
void dual_pivot_qsort(int a[], int lo, int hi)
{
   random_shuffle(a, lo, hi);
   _dual_pivot_qsort(a, lo, hi);
}
