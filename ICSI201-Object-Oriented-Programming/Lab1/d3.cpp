#include <iostream>
using namespace std;

int main() {

   int n, i, max;
   cin >> n;

   cout << "Husnegtiin elementuudiig oruul: \n";
   int arr[n];
   for(i = 0; i < n; i++) {
      cin >> arr[i];
   }

   cout << "Tegsh toonuud: \n";
   for(i = 0; i < n; i++) {
      if(arr[i] % 2 == 0) {
         cout << arr[i] << endl;
      }
   }

   return 0;
}