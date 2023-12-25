#include <iostream>
using namespace std;

class Employee {

   public:
      int id;
      string name;
      string position;
      float hoursWorked;

      Employee() {
         id = 0;
         name = "";
         position = "";
         hoursWorked = 0;
      }
      void inputData() {
         cout << "Ajilchinii ID: ";
         cin >> id;
         cout << "Ajilchinii Ner: ";
         cin >> name;
         cout << "Ajilchinii Alban tushaal: ";
         cin >> position;
         cout << "Ajilchinii Ajilsan tsag: ";
         cin >> hoursWorked;
      }
      void displayData() {
         cout << "ID: " << id << "\n" << "Name: " << name << "\n" << "Position: " << position << "\n" << "Worked hours: " << hoursWorked << "\n";
      }
      float calSalary() {
         if(position == "zahiral") {
            return salaryBoss();
         }
         return hoursWorked * 5;
      }
      float salaryBoss() {
         return hoursWorked * 8;
      }
      bool incHoursWork(float hrs) {
         if(hrs >= 0 && hrs <= 24) {
            return 1;
         }
         return 0;
      }
};

int main() {
   Employee emp1;
   emp1.inputData();
   emp1.displayData();
   cout << emp1.calSalary() << endl;
   cout << emp1.incHoursWork(12) << endl;

   return 0;
}