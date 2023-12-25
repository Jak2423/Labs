#include "DS.h"

/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void l_push_back(List *p, Student x)
{
   Elm *temp = (Elm *)malloc(sizeof(Elm));
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

/* p-ийн зааж буй List-д x утгыг эхэнд хийнэ
   Бүх элементүүд нэг нэг байрлал хойшилно.
 */
void l_push_front(List *p, Student x)
{
   Elm *temp = (struct Elm *)malloc(sizeof(struct Elm));
   temp->x = x;
   temp->next = p->head;
   p->head = temp;
   p->len++;
}

/*
  p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
  pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
  Тухайн байрлал List-ийн сүүлийн индексээс их бол төгсгөлд орно.
 */
void l_insert(List *p, Student x, int pos)
{
   if (pos <= 0)
   {
      l_push_front(p, x);
   }
   else if (pos >= p->len)
   {
      l_push_back(p, x);
   }
   else
   {
      Elm *ptr = (struct Elm *)malloc(sizeof(struct Elm));
      Elm *temp = p->head;
      int i;
      ptr->x = x;
      for (i = 0; i < pos - 1; i++)
      {
         temp = temp->next;
      }
      ptr->next = temp->next;
      temp->next = ptr;
      p->len++;
   }
}

/*
  p-ийн зааж буй List-н эхлэлээс гаргана.
  List-ийн бүх элементүүд нэг нэг байрлал урагшилна
 */
void l_pop_front(List *p)
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

/* p-ийн зааж буй List-н төгсгөлөөс гаргана */
void l_pop_back(List *p)
{
   if (p->len > 0)
   {
      Elm *temp = p->head;

      while (temp != NULL && temp->next != p->tail)
         temp = temp->next;

      if (temp == NULL)
      {
         free(p->head);
         p->head = p->tail = NULL;
      }
      else
      {
         temp->next = NULL;
         free(p->tail);
         p->tail = temp;
      }
      p->len--;
   }
}

/* p-ийн зааж буй List-н pos байрлалаас гаргана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
   pos байрлалаас гарах боломжгүй бол юу ч хийхгүй.
 */
void l_erase(List *p, int pos)
{
   if (pos == 0)
   {
      l_pop_front(p);
   }
   else if (pos == p->len - 1)
   {
      l_pop_back(p);
   }
   else if (pos >= p->len)
   {
      return;
   }
   else
   {
      Elm *ptr = p->head;
      Elm *temp;
      int i;
      for (i = 0; i < pos - 1; i++)
      {
         ptr = ptr->next;
      }
      temp = ptr->next->next;
      free(ptr->next);
      ptr->next = temp;
      p->len--;
   }
}

/*
  p-ийн зааж буй List-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void l_print(List *p)
{
   Elm *ptr;

   for (ptr = p->head; ptr != NULL; ptr = ptr->next)
   {
      printf("%s\n", ptr->x.id);
   }
}

/*
  p-ийн зааж буй List-с id-тай оюутныг хайн олдсон хаягийг буцаана.
  Олдохгүй бол NULL хаяг буцаана.
 */
Elm *l_search(List *p, const char id[])
{
   Elm *ptr = p->head;
   int i;

   for (i = 0; i < p->len; i++)
   {
      if (strcmp(ptr->x.id, id) == 0)
         return ptr;
      ptr = ptr->next;
   }

   return NULL;
}
