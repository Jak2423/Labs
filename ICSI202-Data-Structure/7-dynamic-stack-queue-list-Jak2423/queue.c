#include "DS.h"

/* p-ийн зааж буй Queue-д x утгыг хийнэ */
void q_push(Queue *p, int x)
{
   Elm *temp = (struct Elm *)malloc(sizeof(struct Elm));
   temp->x = x;
   temp->next = NULL;

   if (p->head == NULL)
      p->head = p->tail = temp;
   else
   {
      p->tail->next = temp;
      p->tail = temp;
   }

   p->len++;
}

/* p-ийн зааж буй Queue-с гаргана */
void q_pop(Queue *p)
{
   if (p->len > 0)
   {
      Elm *temp;
      temp = p->head;
      p->head = p->head->next;
      free(temp);
      p->len--;
   }
}

/*
  p-ийн зааж буй Queue-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void q_print(Queue *p)
{
   Elm *ptr = p->head;
   int i;

   for (i = 0; i < p->len; i++)
   {
      printf("%d\n", ptr->x);
      ptr = ptr->next;
   }
}
