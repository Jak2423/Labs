#include "DS.h"
#include <math.h>

/*
  p-ийн зааж буй CBTree-д x утгыг оруулна
*/
void cb_push(CBTree *p, int x)
{
   p->tree.a[p->tree.len] = x;
   p->tree.len++;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны зүүн хүүгийн индексийг буцаана.
  Зүүн хүү байхгүй бол -1 буцаана.
*/
int cb_left(const CBTree *p, int idx)
{
   int lIdx = idx * 2 + 1;
   if (p->tree.len > lIdx)
      return lIdx;

   return -1;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны баруун хүүгийн индексийг буцаана.
  Баруун хүү байхгүй бол -1 буцаана.
*/
int cb_right(const CBTree *p, int idx)
{
   int rIdx = idx * 2 + 2;
   if (p->tree.len > rIdx)
      return rIdx;

   return -1;
}

/*
  p-ийн зааж буй CBTree-с x тоог хайн
  хамгийн эхэнд олдсон индексийг буцаана.
  Олдохгүй бол -1 утгыг буцаана.
*/
int cb_search(const CBTree *p, int x)
{
   for (int i = 0; i < p->tree.len; i++)
   {
      if (p->tree.a[i] == x)
         return i;
   }

   return -1;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй зангилаанаас дээшхи бүх өвөг эцэгийг олох үйлдлийг хийнэ.
  Тухайн орой өөрөө өвөг эцэгт орохгүй.
  Өвөг эцэг бүрийг нэг шинэ мөрөнд хэвлэнэ. Өвөг эцэгийг доороос дээшхи дарааллаар хэвлэнэ.
*/
void cb_ancestors(const CBTree *p, int idx)
{
   if (idx > 0)
   {
      printf("%d\n", p->tree.a[(idx - 1) / 2]);
      cb_ancestors(p, (idx - 1) / 2);
   }
}

/*
  p-ийн зааж буй CBTree-ийн өндрийг буцаана
*/
int cb_height(const CBTree *p)
{
   return ceil(log2(p->tree.len + 1));
}

/*
  p-ийн зааж буй CBTree-д idx оройны ах, дүү оройн дугаарыг буцаана.
  Тухайн оройн эцэгтэй адил эцэгтэй орой.
  Ах, дүү нь байхгүй бол -1-г буцаана.
*/
int cb_sibling(const CBTree *p, int idx)
{
   int pIdx = (idx - 1) / 2;

   if (idx == 2 * pIdx + 1)
      return cb_right(p, pIdx);

   if (idx == 2 * pIdx + 2)
      return cb_left(p, pIdx);

   return -1;
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн preorder-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_preorder(const CBTree *p, int idx)
{
   if (idx < p->tree.len)
   {
      printf("%d\n", p->tree.a[idx]);
      cb_preorder(p, 2 * idx + 1);
      cb_preorder(p, 2 * idx + 2);
   }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн in-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_inorder(const CBTree *p, int idx)
{
   if (idx < p->tree.len)
   {
      cb_inorder(p, 2 * idx + 1);
      printf("%d\n", p->tree.a[idx]);
      cb_inorder(p, 2 * idx + 2);
   }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн post-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
 */
void cb_postorder(const CBTree *p, int idx)
{
   if (idx < p->tree.len)
   {
      cb_postorder(p, 2 * idx + 1);
      cb_postorder(p, 2 * idx + 2);
      printf("%d\n", p->tree.a[idx]);
   }
}

/*
  p-ийн зааж буй CBTree-с idx дугаартай зангилаанаас доошхи бүх навчийг олно.
  Навч тус бүрийн утгыг шинэ мөрөнд хэвлэнэ.
  Навчыг зүүнээс баруун тийш олдох дарааллаар хэвлэнэ.
*/
void cb_leaves(const CBTree *p, int idx)
{
   if (p->tree.len > idx)
   {
      int leave;
      cb_leaves(p, 2 * idx + 1);
      leave = cb_left(p, idx);
      leave = cb_right(p, idx);

      if (leave == -1)
         printf("%d\n", p->tree.a[idx]);

      cb_leaves(p, 2 * idx + 2);
   }
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройноос доошхи бүх үр садыг хэвлэнэ.
  Тухайн орой өөрөө үр сад болохгүй.
  Үр, сад бүрийг нэг шинэ мөрөнд хэвлэнэ. Үр садыг pre-order дарааллаар хэлэх ёстой.
*/
void cb_descendants(const CBTree *p, int idx)
{
   if (p->tree.len > idx)
   {
      cb_preorder(p, 2 * idx + 1);
      cb_preorder(p, 2 * idx + 2);
   }
}

/*
  p-ийн зааж буй Tree-д хэдэн элемент байгааг буцаана.
  CBTree-д өөрчлөлт оруулахгүй.
*/
int cb_size(const CBTree *p)
{
   return p->tree.len;
}

/*
  p-ийн зааж буй CBTree-д x утгаас үндэс хүртэлх оройнуудын тоог буцаана.
  x тоо олдохгүй бол -1-г буцаана.
*/
int cb_level(const CBTree *p, int x)
{
   int count = 0, idx = cb_search(p, x);

   if (idx == -1)
      return -1;

   while (idx > 0)
   {
      idx = (idx - 1) / 2;
      count++;
   }

   return count;
}
