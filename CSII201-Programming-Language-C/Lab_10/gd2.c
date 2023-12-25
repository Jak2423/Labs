#include <stdio.h>
#include <string.h>

int check(char u[], char p[]) {
   int cu, cp, i, j, k, len, ind;
   char user[4][100] = {"bat", "dorj", "bold", "tsetsgee"};
   char pwd[4][100] = {"123456", "password", "pass247", "justinbeaber"};

   cu = 0;
   cp = 0;
   
   for(i = 0; i < 4; i++) {
     if(strcmp(user[i], u) == 0) {
        cu = 1;
        break;
     }
   }

   for(j = 0; pwd[i][j] != '\0'; j++) {
      if(strcmp(pwd[i], p) == 0) {
         cp = 1;
         break;
      }  
   }

   if(cp == 1 && cu == 1) {
      return 1;
   }

   return 0;
}

int main() {
   int c;
   char u[100], p[100];
   printf("Hereglegchiin ner: \n");
   gets(u);
   printf("Hereglegchiin nuuts ug: \n");
   gets(p);

   c = check(u, p);

   if(c == 1) {
      printf("Hereglegchiin ner, nuuts ug taarch baina,\n");
   }
   else {
      printf("Hereglegchiin ner, nuuts ug taarahgui baina,\n");
   }
}