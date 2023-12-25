#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


struct Student {
   char fname[20], lname[20], id[10];
   float golch;
};

typedef struct Student Student;

void read_students(Student a[], int n) {
   int i;

   for(i = 0; i < n; i++) {
      scanf("%s %s %s %f", a[i].fname, a[i].lname, a[i].id, &a[i].golch);
   }
}

void print_students(Student a[], int n) {
   int i;
   for(i = 0; i < n; i++) {
      printf("Ner: %s, Ovog: %s, ID: %s, Golch: %.1f\n", a[i].fname, a[i].lname, a[i].id, a[i].golch);
   }
}

void print(Student st) {
   printf("Ner: %s\n", st.fname);
   printf("Ovog: %s\n", st.lname);
   printf("Id: %s\n", st.id);
   printf("Golch: %.1f\n", st.golch);
}

int search_by_fname(Student a[], int n, char fname[]) {
   int i;
   for(i = 0; i < n; i++) {
      if(strcmp(a[i].fname, fname) == 0)
         return i;
   }

   return -1;
}

int search_by_lname(Student a[], int n, char lname[]) {
   int i;
   for(i = 0; i < n; i++) {
      if(strcmp(a[i].lname, lname) == 0)
         return i;
   }
   
   return -1;
}

int search_by_id(Student a[], int n, char id[]) {
   int i;
   for(i = 0; i < n; i++) {
      if(strcmp(a[i].id, id) == 0)
         return i;
   }
   
   return -1;
}

int search_by_golch(Student a[], int n, float golch) {
   int i;
   for(i = 0; i < n; i++) {
      if(a[i].golch == golch)
         return i;
   }
   
   return -1;
}

void sort_by_golch(Student a[], int n) {
   Student temp[100];
   int i, j;
   
   for(i = 0; i < n - 1; i++) {
      for(j = 0; j < n - i - 1; j++) {
         if(a[j].golch > a[j + 1].golch) {
            temp[i] = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp[i];
         }
      }
   }
}

int main() {
   Student a[100];
   int n, cmd, idx;
   printf("Oyutnii too: ");
   scanf("%d", &n);
   read_students(a, n);
   print_students(a, n);

   char fname[20], lname[20], id[20];
   float golch;

   while(1) {

      printf("1: Nereer haih, 2: Ovgoor haih, 3: ID-aar haih, 4: Golchoor haih, 5: Golchoor erembleh, 6: Xevleh, 7: Garah\n");
      scanf("%d", &cmd);

      if(cmd == 1) {
         printf("Haih ner: \n");
         scanf("%s", fname);
         idx = search_by_fname(a, n, fname);

         if(idx == -1) 
            printf("Oyutan oldsongui\n");
         else 
            print(a[idx]);
      }
      else if(cmd == 2) {
         printf("Haih ovog: \n");
         scanf("%s", lname);
         idx = search_by_lname(a, n, lname);

         if(idx == -1) 
            printf("Oyutan oldsongui\n");
         else 
            print(a[idx]);
      }
      else if(cmd == 3) {
         printf("Haih ID: \n");
         scanf("%s", id);
         idx = search_by_id(a, n, id);

         if(idx == -1) 
            printf("Oyutan oldsongui\n");
         else 
            print(a[idx]);
      }
      else if(cmd == 4) {
         printf("Haih golch: \n");
         scanf("%f", &golch);
         idx = search_by_golch(a, n, golch);
         if(idx == -1) 
            printf("Oyutan oldsongui\n");
         else 
            print(a[idx]);
      }
      else if(cmd == 5) {
         sort_by_golch(a, n);
      }
      else if(cmd == 6) {
         print_students(a, n);
      }
      else  
         break;
   }

   return 0;
}

