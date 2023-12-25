#include <iostream>
using namespace std;

int main() {
   int n, count, digit;
   count = 0;
   cin >> n;

   while(n != 0) {
     digit = n % 10;
     cout << "Ugugdsun toonii tsifr: " << digit << endl;
     n = n / 10;
     count++;
   }

   cout << "Ugugdsun toonii orongiin too: " << count << endl;

   return 0;
}