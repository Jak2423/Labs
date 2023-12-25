#include "DS.h"

int isRed(Elm *x)
{
   if (x == NULL)
      return 0;
   return x->color;
}

void flipColor(Elm *x)
{
   x->color = 1;
   x->R->color = 0;
   x->L->color = 0;
}

Elm *rightRotate(Elm *root)
{
   Elm *left = root->L;
   root->L = left->R;
   left->R = root;
   left->color = root->color;
   root->color = 1;

   return left;
}

Elm *leftRotate(Elm *root)
{
   Elm *right = root->R;
   root->R = right->L;
   right->L = root;

   right->color = root->color;
   root->color = 1;

   return right;
}

/*
  Хоёр оюутны мэдээллийн хооронд нь харьцуулах функц
*/
int less(const Student *a, const Student *b)
{
   return strcmp(a->id, b->id);
}

Elm *insertion(Elm *root, const Student *px)
{
   if (root == NULL)
   {
      Elm *temp = (Elm *)malloc(sizeof(Elm));
      temp->x.age = px->age;
      temp->x.gpa = px->gpa;
      strcpy(temp->x.name, px->name);
      strcpy(temp->x.id, px->id);
      temp->L = temp->R = NULL;
      temp->color = 1;

      return temp;
   }

   int n = less(&root->x, px);

   if (n == 0)
   {
      root->x.age = px->age;
      root->x.gpa = px->gpa;
      strcpy(root->x.name, px->name);
      strcpy(root->x.id, px->id);
   }
   else if (n > 0)
      root->R = insertion(root->R, px);
   else
      root->L = insertion(root->L, px);

   if (isRed(root->R) && !isRed(root->L))
      root = leftRotate(root);
   if (isRed(root->L) && isRed(root->L->L))
      root = rightRotate(root);
   if (isRed(root->L) && isRed(root->R))
      flipColor(root);

   return root;
}
/*
  `ptree`-ийн зааж байгаа модонд `x` утгыг оруулна.
  Мод хоосон байсан бол `ptree->root` хаяг өөрчлөгдөж шинээр орсон оройг заана.
  Хэрэв мод тэнцвэрээ алдсан бол тохирох тэнцвэржүүлэх үйлдлүүдийг хийнэ.
 */
void rb_put(RBT *ptree, const Student *px)
{
   ptree->root = insertion(ptree->root, px);
}

/*
  `ptree`-ийн зааж байгаа модноос `x` утгыг хайн олдсон оройн `Elm*` хаягийг буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
  Мод дандаа ялгаатай элементүүд хадгална гэж үзэж болно.
 */
Elm *rb_get(const RBT *ptree, const char id[])
{
   Elm *temp = ptree->root;

   while (temp != NULL)
   {
      int n = strcmp(temp->x.id, id);

      if (n == 0)
         return temp;
      else if (n > 0)
         temp = temp->R;
      else
         temp = temp->L;
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

Elm *deletion(Elm *root, const char id[])
{
   if (root == NULL)
      return NULL;

   int n = strcmp(root->x.id, id);

   if (n < 0)
      root->L = deletion(root->L, id);
   else if (n > 0)
      root->R = deletion(root->R, id);
   else if (n == 0)
   {
      if ((root->L == NULL) || (root->R == NULL))
      {
         Elm *temp = root->L ? root->L : root->R;
         if (temp == NULL)
         {
            temp = root;
            root = NULL;
         }
         else
            *root = *temp;
         free(temp);
      }
      else
      {
         Elm *temp = min(root->R);
         root->x = temp->x;
         root->R = deletion(root->R, temp->x.id);
      }
   }

   return root;
}

/*
  Устгах функц: ТМноос `x` утгыг хайж олоод устгана.
  Олдохгүй бол юу ч хийхгүй.
  Хэрэв мод тэнцвэрээ алдсан бол тохирох тэнцвэржүүлэх үйлдлүүдийг хийнэ.
 */
void rb_del(RBT *ptree, const char id[])
{
   ptree->root = deletion(ptree->root, id);
}

void print(Elm *p)
{
   if (p)
      printf("%s %s %d %.1f\n", p->x.name, p->x.id, p->x.age, p->x.gpa);
   else
      printf("None\n");
}
