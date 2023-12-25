#include <iostream>
using namespace std;

int maxNum(int a, int b, int c) {
   if(a > b && a > c){
      return a;
   }
   else if(b > a && b > c) {
      return b;
   }
   else {
      return c;
   }
}

int main() {

   int a, b, c;
   cout << "3 too oruul: \n";
   cin >> a >> b >> c;

   cout << "Hamgiin ih too: " << maxNum(a, b, c);

   return 0;
}