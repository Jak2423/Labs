#include "DS.h"

static void swim(Heap *p, int);
static void sink(Heap *p, int);
static void swap(Msg *a, Msg *b);

/*
  Хоёр зурвасын чухлыг харьцуулах функц.
  b нь илүү чухал бол 1, бусад үед 0-ыг буцаах функц.
  Өөрөөр хэлбэл a < b үйлдэл юм.
*/
int less(const Msg *a, const Msg *b)
{
   if (a->priority < b->priority)
      return 1;

   if (a->priority == b->priority)
      if (a->time < b->time)
         return 1;

   return 0;
}

static void swap(Msg *a, Msg *b)
{
   Msg temp = *a;
   *a = *b;
   *b = temp;
}

/*
  Оруулах функц. heap зарчмаар чухлын дарааллыг баримтлан оруулна.
  Ингэхдээ хамгийн чухал зурвас heap-ын оройд хадгалагдана.
  x зурвасыг p-ын зааж буй heap бүтцэд оруулна.
 */
void insert(Heap *p, const Msg x)
{
   if (p->heap.len > 0)
   {
      p->heap.a[p->heap.len] = x;
      p->heap.len++;
      swim(p, p->heap.len - 1);
   }
   else
   {
      p->heap.a[0] = x;
      p->heap.len++;
   }
}

/*
  Heap бүтцийн swim үйлдэл.
  k нь swim үйлдлийг p-ын зааж буй heap дээр эхлүүлэх индекс.
 */
static void swim(Heap *p, int k)
{
   while ((k > 0) && less(&p->heap.a[k], &p->heap.a[(k - 1) / 2]))
   {
      swap(&p->heap.a[k], &p->heap.a[(k - 1) / 2]);
      k = (k - 1) / 2;
   }
}

/*
  Heap бүтцийн sink үйлдэл.
  k нь sink үйлдлийг p-ын зааж буй heap дээр эхлүүлэх индекс.
 */
static void sink(Heap *p, int k)
{
   while (2 * k + 1 < p->heap.len)
   {
      int j = 2 * k + 1;

      if ((j < p->heap.len - 1) && less(&p->heap.a[j + 1], &p->heap.a[j]))
         j++;

      if (less(&p->heap.a[k], &p->heap.a[j]))
         break;

      swap(&p->heap.a[k], &p->heap.a[j]);
      k = j;
   }
}

/*
  p-ын зааж буй heap бүтцээс оройн элементийг гаргаад буцаах функц.
  Гаргасны дараа орой бүрийн хувьд heap зарчим хадгалах ёстой.
 */
Msg delMin(Heap *p)
{
   swap(&p->heap.a[0], &p->heap.a[p->heap.len - 1]);
   p->heap.len--;
   sink(p, 0);

   return p->heap.a[p->heap.len];
}
