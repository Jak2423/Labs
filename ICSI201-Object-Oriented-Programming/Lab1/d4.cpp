#include <iostream>
#include <iomanip>
using namespace std;

int main() {

   int n, i, sum, count;
   float avg;

   cin >> n;
   int arr[n];
   sum = 0;
   count = 0;

   cout << "Husnegtiin elementuudiig oruul: \n";
   for(i = 0; i < n; i++) {
      cin >> arr[i];
   }

   for(i = 0; i < n; i++) {
      if(arr[i] % 2 != 0) {
         sum += arr[i];
         count++;
      }
   }

   avg = sum / count;
   cout << "Sondgoi toonii dundaj: " << fixed << setprecision(2) << avg << endl;

   return 0;
}