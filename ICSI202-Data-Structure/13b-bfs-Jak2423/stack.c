#include "DS.h"
/*
  p-ийн зааж буй Stack-т x утгыг оруулна
 */
void s_push(Stack *p, int x)
{
   Elm *temp = (struct Elm *)malloc(sizeof(struct Elm));
   temp->x = x;
   temp->next = p->top;
   p->top = temp;
   p->len++;
}
/*
  p-ийн зааж буй Stack-аас гарах функц
 */
void s_pop(Stack *p)
{
   if (p->len > 0)
   {
      Elm *temp;
      temp = p->top;
      p->top = p->top->next;
      free(temp);
      p->len--;
   }
}
/*
    p-ийн зааж буй Stack-д байгаа элементүүдийг хэвлэх функц.
    Хамгийн сүүлд орсон элементээс эхлэн дарааллаар, нэг мөрөнд
    нэг л элемент хэвлэнэ.
 */
void s_print(Stack *p)
{
   Elm *ptr = p->top;
   int i;

   for (i = 0; i < p->len; i++)
   {
      printf("%d\n", ptr->x);
      ptr = ptr->next;
   }
}
