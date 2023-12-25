#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
private:
   sint id;
   string name;
   string position;
   float hoursWorked;

public:
   Employee()
   {
      id = 0;
      name = "";
      position = "";
      hoursWorked = 0;
   }

   Employee(int id, string fname, string pos, float hrs)
   {
      id = id;
      name = fname;
      position = pos;
      hoursWorked = hrs;
   }

   int getId()
   {
      return id;
   }

   string getName()
   {
      return name;
   }

   string getPosition()
   {
      return position;
   }

   int getHoursWorked()
   {
      return hoursWorked;
   }

   void setId(int i)
   {
      id = i;
   }

   void setName(string fname)
   {
      name = fname;
   }

   void setPosition(string pos)
   {
      position = pos;
   }

   void setHoursWorked(float hrs)
   {
      hoursWorked = hrs;
   }

   float calSalary()
   {
      if (position == "zahiral")
      {
         return salaryBoss();
      }
      return hoursWorked * 5;
   }

private:
   float salaryBoss()
   {
      return hoursWorked * 8;
   }

public:
   bool incHoursWork(float hrs)
   {
      if (hrs >= 0 && hrs <= 24)
      {
         hoursWorked += hrs;
         return 1;
      }
      return 0;
   }

   ~Employee()
   {
      cout << "Destructor working\n";
   }
};

int main()
{
   Employee emp[2];
   int i, j, id;
   float hrs;
   string pos, name;

   for (i = 0; i <= 2; i++)
   {
      cout << "ID: ";
      cin >> id;
      emp[i].setId(id);
      cout << "Ner: ";
      cin >> name;
      emp[i].setName(name);
      cout << "Alban tushaal: ";
      cin >> pos;
      emp[i].setPosition(pos);
      cout << "Ajilsan tsag: ";
      cin >> hrs;
      emp[i].setHoursWorked(hrs);
   }

   for (i = 0; i <= 2; i++)
   {
      for (j = i + 1; j <= 2; j++)
      {
         if (emp[i].calSalary() > emp[j].calSalary())
         {
            Employee temp = emp[i];
            emp[i] = emp[j];
            emp[j] = temp;
         }
      }
   }

   for (i = 0; i <= 2; i++)
   {
      cout << emp[i].getId() << ", ";
   }

   return 0;
}