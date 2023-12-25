#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char fname[100], lname[100], color[100], hob[100], ftime[100];
   int y, m, d, age;
   printf("Tani ovog?\n");
   scanf("%s", lname);
   printf("Tani ner?\n");
   scanf("%s", fname);
   printf("Tani tursun on sar udur?\n");
   scanf("%d %d %d", &y, &m, &d);
   printf("durtai ungu?\n");
   scanf("%s", color);
   printf("Hobby yu ve?\n");
   scanf("%s", hob);
   printf("Chuluut tsagaara yu hiideg ve?\n");
   scanf("%s", ftime);

   age = 2022 - y;

   printf("%s ovogtoi %s ni  %d / %d / %d-ni udur tursun. Odoo %d nastai. Tuuni durtai ungu bol %s. Ter chuluut tsagaaraa %s hiideg. Tuunii hobby bol %s\n", lname, fname, y, m, d, age, color, ftime, hob);
}