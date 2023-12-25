#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int case_insensitive = 0;
/*
  s тэмдэгтэн цувааны hash-ыг буцаана
 */
int hash(const char *s)
{
   int hash = 0, n = strlen(s);

   for (int i = 0; i < n; i++)
   {
      if (case_insensitive)
         hash = (256 * hash + tolower(s[i])) % 101;
      else
         hash = (256 * hash + s[i]) % 101;
   }

   return hash;
}

/*
  Функц нь buf доторх тэмдэгтэн цуваанаас index байрлалаас эхлэн
  pattern тэмдэгтийг хайна. Олдвол олдсон индексийг буцанаа.
  Олдохгүй бол -1 утгыг буцаана.
  case_insensitive = 1 бол том жижиг гэж ялгалгүйгээр тааруулна.
  Мөн мөрний мэдээллийг давхар хариуцаж явна.
  Мөр шилжих үед (*pline)++

  buf     :    Хайлт хийх тэмдэгтэн цуваа
  n       :    buf-ын урт
  index   :    Хайлтыг эхлэх индекс
  pattern :    Хайх үг
  m       :    pattern-ны урт
  pat_hash:    pattern хэвийн hash
  pline   :    Мөрийн мэдээлэл хадгалах хувьсагчийн хаяг
 */
int find(const char *buf, int n, int index, const char *pattern, int m, int pat_hash, int *pline)
{
   int buf_hash = 0;
   int i, j, h = 1;

   for (i = 0; i < m - 1; i++)
      h = (h * 256) % 101;

   for (i = index; i < index + m; i++)
      buf_hash = (256 * buf_hash + buf[i]) % 101;

   for (i = index; i <= n - m; i++)
   {
      if (buf[i] == '\n')
         (*pline)++;

      for (j = 0; j < m; j++)
      {
         if (case_insensitive)
         {
            if (tolower(buf[i + j]) != tolower(pattern[j]))
               break;
         }
         else
         {
            if (buf[i + j] != pattern[j])
               break;
         }
      }

      if (j == m)
         return i;

      if (i < n - m)
      {
         if (case_insensitive)
            buf_hash = (256 * (buf_hash - tolower(buf[i]) * h) + tolower(buf[i + m])) % 101;
         else
            buf_hash = (256 * (buf_hash - buf[i] * h) + buf[i + m]) % 101;

         if (buf_hash < 0)
            buf_hash += 101;
      }
   }
   return -1;
}

int main(int argc, char *argv[])
{
   // Аргументийн тоо ядаж 3 байх ёстой.
   if (argc < 3)
   {
      printf("%s [-i] pattern FILE", argv[0]);
      exit(-1);
   }

   const char *pattern;
   if (argc > 3 && strcmp("-i", argv[1]) == 0)
   {
      case_insensitive = 1; // Том жижгийг хайхрахгүй адил гэж үзнэ.
      pattern = argv[2];
   }
   else
      pattern = argv[1];

   FILE *fin;
   fin = fopen(argv[argc - 1], "r");
   if (fin == NULL)
   {
      printf("Error openning %s file", argv[argc - 1]);
      exit(-1);
   }
   int len = 0;
   char ch;
   while (!feof(fin))
   {
      ch = fgetc(fin);
      len++; // Файлд доторх тэмдэгтүүдийг тоолъё.
   }
   char *buf;
   buf = (char *)malloc(sizeof(char) * (len + 1)); // Энд тэмдэгтүүдийг хадгална
   fseek(fin, 0, SEEK_SET);                        // Файл заагчийг буцаад эхлэлд нь аваачна.
   int i = 0;
   while (!feof(fin))
      buf[i++] = fgetc(fin); // Өгөгдлийг уншиж байна.
   buf[len - 1] = 0;         /* тэмдэгт мөр төгсгөл заагч */

   int ret = -1;
   int line = 0;
   int pat_hash = hash(pattern); // hash кодыг тооцоолно
   int m = strlen(pattern);

   do
   {
      ret = find(buf, len - 1, ret + 1, pattern, m, pat_hash, &line);
      if (ret != -1)
      {
         printf("%d: ", line);
         /*
           Олдсон газраас доошоо 5
           дээшээ 5 тэмдэгтийг хэвлэнэ.
          */
         int L = ret - 5;
         int K = ret + strlen(pattern) + 5;
         if (L < 0)
            L = 0;
         if (K >= len)
            K = len - 1;
         for (i = L; i <= K; i++)
            printf("%c", buf[i]);
         printf("\n");
      }
   } while (ret != -1);

   free(buf);
   return 0;
}
