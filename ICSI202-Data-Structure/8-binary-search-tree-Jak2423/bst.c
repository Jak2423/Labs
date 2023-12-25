#include "DS.h"

/*
  `ptree`-ийн зааж байгаа модонд `x` утгыг оруулна.
  Оруулахдаа хоёртын хайлтын модны зарчмаар оруулах бөгөөд оруулсан
  байрлалаас дээшхи өвөг эцгийн `len`, `height` утгууд өөрчлөгдөнө.
  Мод хоосон байсан бол `ptree->root` хаяг өөрчлөгдөж шинээр орсон оройг заана.
 */

Elm *bs_insert(Elm *root, int x)
{
   if (root == NULL)
   {
      Elm *root = (Elm *)malloc(sizeof(Elm));
      root->x = x;
      root->L = root->R = NULL;
      root->height = root->len = 1;
      return root;
   }
   else if (root->x < x)
      root->R = bs_insert(root->R, x);

   else
      root->L = bs_insert(root->L, x);

   root->len++;

   if (root->R != NULL && root->L != NULL)
      root->height = (root->L->height > root->R->height) ? root->L->height + 1
                                                         : root->R->height + 1;
   else if (root->L)
      root->height = root->L->height + 1;
   else if (root->R)
      root->height = root->R->height + 1;

   return root;
}

void bs_put(BST *ptree, int x)
{
   ptree->root = bs_insert(ptree->root, x);
}

/*
  `ptree`-ийн зааж байгаа модноос `x` утгыг хайн олдсон оройн `Elm*` хаягийг буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
  Мод дандаа ялгаатай элементүүд хадгална гэж үзэж болно.
 */
Elm *bs_get(const BST *ptree, int x)
{
   Elm *root = ptree->root;
   while (root != NULL)
   {
      if (root->x == x)
         return root;
      else if (root->x < x)
         root = root->R;
      else
         root = root->L;
   }

   return NULL;
}

Elm *min(Elm *root)
{
   Elm *temp = root;

   while (temp && temp->L != NULL)
      temp = temp->L;

   return temp;
}

int size(Elm *p)
{
   if (p == NULL)
   {
      return 0;
   }
   else
   {
      return p->len;
   }
}

int height(Elm *p)
{
   if (p == NULL)
   {
      return 0;
   }
   else
   {
      return p->height;
   }
}

int max_height(int a, int b)
{
   if (a > b)
   {
      return a;
   }
   else
   {
      return b;
   }
}

Elm *del(Elm *root, int x)
{
   if (root == NULL)
      return NULL;

   if (root->x < x)
   {
      root->R = del(root->R, x);
   }
   else if (root->x > x)
   {
      root->L = del(root->L, x);
   }
   else if (root->x == x)
   {
      if (root->L == NULL)
         return root->R;
      else if (root->R == NULL)
         return root->L;

      Elm *temp = root;
      root = min(temp->R);
      root->R = del(temp->R, root->x);
      root->L = temp->L;
   }
   root->len = 1 + size(root->L) + size(root->R);
   root->height = 1 + max_height(height(root->L), height(root->R));

   return root;
}
/*
  Устгах функц: ХХМноос `x` утгыг хайж олоод устгана.
  Олдохгүй бол юу ч хийхгүй.
 */
void bs_del(BST *ptree, int x)
{
   ptree->root = del(ptree->root, x);
}

/*
  Хамгийн багыг устгах функц: ХХМноос хамгийг бага утгыг нь устгах функц.
  Устгасан утгыг буцаана.
 */
int bs_delMin(BST *ptree)
{
   Elm *temp = min(ptree->root);
   int i = temp->x;
   bs_del(ptree, i);

   return i;
}

void inorder(const Elm *root)
{
   if (root != NULL)
   {
      inorder(root->L);
      printf("%d %d %d\n", root->x, root->len, root->height);
      inorder(root->R);
   }
}
/*
  ХХМыг inorder дарааллаар, нэг мөрөнд нэг утга хэвлэнэ.
 */
void bs_inorder(const BST *ptree)
{
   inorder(ptree->root);
}

/*
  ХХМноос `x` утгаас эрс бага буюу тэнцүү байх хэдэн орой байгааг олж буцаана.
  Өөрөөр хэлбэл хоёртын хайлтын модны утгуудыг өсөх дарааллаар байрлуулбал
  `x`-ийг оролцуулаад өмнө хэдэн тоо байх вэ? гэсэн үг.
  `x` утга заавал модонд байх албагүй.
 */
int bs_rank(const BST *ptree, int x)
{
   Elm *root = ptree->root;
   int rank = 0;

   if (root == NULL)
      return 0;

   while (root != NULL)
   {

      if (root->x > x)
      {
         root = root->L;
      }
      else if (root->x < x)
      {
         if (root->L != NULL)
            rank += 1 + root->L->len;
         else
            rank += 1;

         root = root->R;
      }
      else
      {
         if (root->L != NULL)
            rank += root->L->len + 1;
         else
            rank += 1;

         return rank;
      }
   }

   return rank;
}

/*
  ХХМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
  дэд модонд хэдэн орой байгааг олж буцаана.
  Олдохгүй бол -1-ийг буцаана.
 */
int bs_size(const BST *ptree, int x)
{
   Elm *temp = bs_get(ptree, x);

   if (temp)
      return temp->len;

   return -1;
}

/*
  XXMноос `x`-ээс бага буюу тэнцүү байх хамгийн их утгын `Elm *` хаягийг олж буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
 */
Elm *bs_floor(const BST *ptree, int x)
{
   Elm *root = ptree->root;
   Elm *floor = NULL;

   if (root == NULL)
      return NULL;

   while (root != NULL)
   {
      if (root->x == x)
         return root;

      if (root->x > x)
         root = root->L;
      else
      {
         floor = root;
         root = root->R;
      }
   }

   return floor;
}

/*
  XXMноос `x`-ээс их буюу тэнцүү байх хамгийн бага утгын `Elm *` хаягийг олж буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
 */
Elm *bs_ceiling(const BST *ptree, int x)
{
   Elm *root = ptree->root;
   Elm *ceil = NULL;

   if (root == NULL)
      return NULL;

   while (root != NULL)
   {
      if (root->x == x)
         return root;

      if (root->x < x)
         root = root->R;
      else
      {
         ceil = root;
         root = root->L;
      }
   }

   return ceil;
}

/*
  ХХМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
  дэд модны өндөр хэд байгааг олж буцаана. Олдохгүй бол -1-ийг буцаана.
 */
int bs_height(const BST *ptree, int x)
{
   Elm *temp = bs_get(ptree, x);

   if (temp)
      return temp->height;

   return -1;
}
