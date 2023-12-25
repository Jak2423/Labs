#include <stdio.h>

int main() {

   int bool;
   printf("Shultui, ustai hool ideh uu?\n");
   scanf("%d", &bool);

   if (bool == 1) {
      
      printf("Tsaitai bol tiim, ugui bol shultui\n");
      scanf("%d", &bool);

      if (bool == 1) {
         printf("Budaatai bol tiim, ugui bol banshtai baih ni\n");
         scanf("%d", &bool);
      
         if (bool == 1) {
            printf("Budaatai tsai\n");
         }
         else{
            printf("Banshtai tsai\n");
         }
      }
      else{
         printf("Yutai shul idmeer baina?\n");
         scanf("%d", &bool);

         switch (bool) {
         case 1:
            printf("Lafsha\n");
            break;
         case 2:
            printf("Huitsai\n");
            break;
         case 3:
            printf("Goimontoi shul\n");
            break;
         case 4:
            printf("Banshtai shul\n");
            break;
         case 5:
            printf("Har shul\n");
            break;
         case 6:
            printf("Nogootoi shul\n");
            break;
         default:
            break;
         }
      }
   }
   else {
      printf("Mah tatsan uu?\n");
      scanf("%d", &bool);

      if (bool == 1) {
         printf("Guriland orooson uu?\n");
         scanf("%d", &bool);
         
         if (bool == 1) {
            printf("Yaj bolgoson?\n");
            scanf("%d", &bool);

            if (bool == 1) {
               printf("Sharsan\n");
               scanf("%d", &bool);

               if (bool == 1) {
                  printf("Piroshki\n");
               }
               else {
                  printf("Huushuur\n");
               }
               
            }
            else {
               printf("Jignesen\n");
               scanf("%d", &bool);

               if (bool == 1) {
                  printf("Mantuun buuz\n");
               }
               else {
                  printf("Buuz\n");
               }
            }
         }
         else {
            printf("Budaatai yu?\n");
            scanf("%d", &bool);

            if (bool == 1) {
                  printf("Undugtei pifshteks\n");
               }
               else {
                  printf("Tefteli\n");
               }
         }
         
      }
      else {
         printf("Yutai holison?\n");
         scanf("%d", &bool);

         switch (bool) {
         case 1:
            printf("Tsuivan\n");
            break;
         case 2:
            printf("Undugtei huurga\n");
            break;
         case 3:
            printf("Hoorond holih uu?\n");
            scanf("%d", &bool);
            if (bool == 1) {
               printf("Guliash\n");
            }
            else {
               printf("Budaatai huurga\n");
            }
            break;
         case 4:
            printf("Nogootoi huurga\n");
            break;
         default:
            break;
         }
      }
   }
}
   
