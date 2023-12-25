#include <stdio.h>
#include <string.h>

typedef struct{
   char fname[20], lname[20], id[10];
   float golch;
} Student;

void read(Student *s) {
   scanf("%s %s %s %f", s->fname, s->lname, s->id, &s->golch);
}

void print(Student s) {
    printf("Ner: %s, Ovog: %s, ID: %s, Golch: %.1f\n", s.fname, s.lname, s.id, s.golch);
}

void set_fname(Student *p, char ner[]) {
   strcpy(p->fname, ner);
}

void set_lname(Student *p, char ovog[]) {
   strcpy(p->lname, ovog);
}

void set_id(Student *p, char id[]) {
   strcpy(p->id, id);
}

void set_golch(Student *p, float golch) {
   p->golch = golch;
}

void change_name(Student *p) {
   scanf("%s", p->fname);
}

int main() {
   Student bat, t;
   read(&bat);
   print(bat);
   set_fname(&t, "dorj");
   set_lname(&t, "bold");
   set_id(&t, "1234");
   set_golch(&t, 3);
   print(t);
   change_name(&bat);
   print(bat);
   return 0;
}