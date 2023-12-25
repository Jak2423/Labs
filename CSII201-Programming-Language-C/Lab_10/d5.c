#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid(char pwd[]) {
   int i, len, ch, count, big;
   count = 0;
   len = strlen(pwd);
   big = 0;
   ch = 0;
   if(len < 6)
      return 1;
      
   for(i = 0; i < len; i++) {
      if(pwd[i] >= '0' && pwd[i] <= '9') {
         count++;
      }
      if(pwd[i] >= 'A' && pwd[i] <= 'Z') {
         big = 1;
      }
      if(pwd[i] == '?' || pwd[i] == '!' || pwd[i] == '$' || pwd[i] == '*' || pwd[i] == ',' || pwd[i] == '-' || pwd[i] == '+') {
         ch = 1;
      }
   }
   if(big ==  0) {
      return 2;
   }
   
   if(count < 3) {
      return 3;
   }
   else if(ch == 0) {
      return 4;
   }

   return 0;
}

int main() {
   char pwd[100], check;
   gets(pwd);

   check = is_valid(pwd);

   if(check == 0) {
      printf("Buh nuhtsul bielj baina.\n");
   }
   else if(check == 1) {
      printf("Urt ni ydaj 6 baina.\n");
   }
   else if(check == 2) {
      printf("Dor hayj 1 tom useg orson baina.\n");
   }
   else if(check == 3) {
      printf("Ydaj 3 shirheg too.\n");
   }
   else {
      printf("?, !, $, *, (,), -, + temdegtuudiin ydaj neg ni baih.\n");
   }

   return 0;
}