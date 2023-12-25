#include "DS.h"

/*
  Оюутны мэдээлэл оруулах функц: `p_hash`-ын зааж байгаа хайш хүснэгтэд
  `x`-д хадгалсан оюутны мэдээллийг оруулна.
 */

void ht_insert(HashTable *p_hash, const Student x)
{
   int h = ht_hash(x.id);
   Elm *p_elm = l_search(&p_hash->h[h], x.id);
   if (p_elm == NULL)
      l_push_back(&p_hash->h[h], x);
}

/*
  Хайш тооцоолох функц: `s` тэмдэгтэн цувааны хайшыг тооцоолоод,
  тооцоолсон хайшыг буцаах функц.
 */
int ht_hash(const char s[])
{
   unsigned int i, hash = 0;
   for (i = 0; i < strlen(s); i++)
   {
      hash = s[i] + (31 * hash);
   }

   return hash % HASH_TABLE_SIZE;
}

/*
  Хайш хүснэгтийн утгуудыг эхлүүлэх функц:  Хайш хүснэгтийн бүх элементийн `head`, `tail` утгуудад
  `NULL` оноох ёстой.
 */
void ht_init(HashTable *p_hash)
{
   int i;
   p_hash->h = (List *)malloc(sizeof(List) * HASH_TABLE_SIZE);
   for (i = 0; i < HASH_TABLE_SIZE; i++)
      p_hash->h[i].head = p_hash->h[i].tail = NULL;
}

/*
  Хайх функц: `p_hash`-ыг зааж буй хайш хүснэгтээс `id`-тай оюутныг хайж,
  олдсон оюутны хаягийг буцаах функц. Олдохгүй бол `NULL` хаяг буцаана.
 */
Student *ht_search(HashTable *p_hash, const char id[])
{
   int hash = ht_hash(id);
   List *l = &p_hash->h[hash];

   if (l != NULL)
   {
      Elm *res = l_search(l, id);
      return &res->x;
   }

   return NULL;
}

/*
  Мэдээлэл өөрчлөх функц: `p_hash`-ыг зааж буй хайш хүснэгтээс `x.id`-аар
  оюутныг хайж олоод, овог нэрийг `x.ner`, `x.ovog`-оор солино.
  Олдохгүй бол `x` оюутныг шинээр оруулна.
 */
void ht_update(HashTable *p_hash, const Student x)
{
   int hash = ht_hash(x.id);
   Elm *e = l_search(&p_hash->h[hash], x.id);

   if (e == NULL)
   {
      l_push_back(&p_hash->h[hash], x);
   }
   else
   {
      strcpy(e->x.ner, x.ner);
      strcpy(e->x.ovog, x.ovog);
   }
   p_hash->len++;
}

/*
  Устгах функц: `p_hash`-ыг зааж буй хайш хүснэгтээс `id`-тай оюутныг хайж
  олж устгана. Олдохгүй бол юу ч хийхгүй.
 */
void ht_del(HashTable *p_hash, const char id[])
{
   List *l = &(p_hash->h[ht_hash(id)]);
   Elm *e = l->head;
   Elm *prev = NULL;
   while (e != NULL)
   {
      if (strcmp(e->x.id, id) == 0)
      {
         if (prev == NULL)
         {
            l->head = e->next;
         }
         else
         {
            prev->next = e->next;
         }
         if (l->tail == e)
         {
            l->tail = prev;
         }
         free(e);
         l->len--;
         p_hash->len--;
         return;
      }
      prev = e;
      e = e->next;
   }
}

/*
  Хайш хүснэгтийг чөлөөлөх: Ойн цоорхой үүсгэлгүй, бүх элементийг устган, хаягийг чөлөөлнө.
 */
void ht_release(HashTable *p_hash)
{
   int i;
   for (i = 0; i < HASH_TABLE_SIZE; i++)
   {
      while (p_hash->h[i].head != NULL)
         l_pop_front(&p_hash->h[i]);
   }
   free(p_hash->h);
}

/*
  Оюутны мэдээллийг хэвлэх функц: `p`-ын зааж буй оюутны овог, нэр, ID-г хэвлэнэ.
 */
void student_print(FILE *fout, const Student *p)
{
   if (p == NULL)
      fprintf(fout, "xooson\n");
   else
      fprintf(fout, "%s %s %s\n", p->ovog, p->ner, p->id);
}
