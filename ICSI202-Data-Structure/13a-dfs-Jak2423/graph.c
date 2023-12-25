#include "DS.h"
/*
  Графыг эхлүүлэх функц: `g` графын хөршүүдийг хадгалах жагсаалтан хүснэгтийг эхлүүлэх функц.
  Санах ойг бэлдэж, жагсаалтын `head`, `tail` утгуудад `NULL` онооно.
 */
void gr_init_graph(Graph *g, int n)
{
   int i;
   g->adj = (List *)malloc(sizeof(List) * (n + 1));
   g->n = n;
   for (i = 0; i <= n; i++)
   {
      g->adj[i].head = g->adj[i].tail = NULL;
      g->adj[i].len = 0;
   }
}

/*
  Гүний нэвтрэлтийн функц: `g` граф дээр гүний нэвтрэлт хийн холбоост бүрдлүүдийн талаарх
  даалгаварт заагдсан мэдээллийг хэвлэнэ.
 */
void gr_connected_components(Graph *g, int *cc)
{
   int count = 1;
   int *vis = (int *)malloc(sizeof(int) * g->n + 1);
   int *stack = (int *)malloc(sizeof(int) * g->n);
   int top = 0;
   Elm *elm;
   cc[0] = 0;

   for (int i = 1; i <= g->n; i++)
   {
      if (!vis[i])
      {
         vis[i] = 1;
         cc[count] = 1;
         stack[top++] = i;

         while (top)
         {
            int u = stack[--top];
            for (elm = g->adj[u].head; elm != NULL; elm = elm->next)
            {
               if (!vis[elm->x])
               {
                  vis[elm->x] = 1;
                  cc[count]++;
                  stack[top++] = elm->x;
               }
            }
         }
         count++;
      }
   }
   cc[0] = count - 1;
   free(vis);
   free(stack);
}

/*
  Ирмэг нэмэх функц: `g` графын ирмэгүүдийг хадгалах `adj` жагсаалтан хүснэгтэд ирмэг нэмнэ.
  Уг граф нь чиглэлгүй граф тул `x`-с `y`, `y`-с `x` гэсэн хоёр ирмэгийг оруулна.
 */
void gr_add_edge(Graph *g, int x, int y)
{
   l_push_back(&g->adj[x], y);
   l_push_back(&g->adj[y], x);
}
