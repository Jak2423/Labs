#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
private:
   int id;
   char *name;
   char *position;
   float hoursWorked;

public:
   Employee()
   {
      id = 0;
      name = new char[1];
      strcpy(name, " ");
      position = new char[1];
      strcpy(position, " ");
      hoursWorked = 0;
   }

   Employee(int idx, char *fname, char *pos, float hrs)
   {
      id = idx;
      name = new char[strlen(fname) + 1];
      position = new char[strlen(pos) + 1];
      strcpy(name, fname);
      strcpy(position, pos);
      hoursWorked = hrs;
   }

   Employee(Employee &emp)
   {
      id = emp.id;
      strcpy(name, emp.name);
      strcpy(position, emp.position);
      hoursWorked = emp.hoursWorked;
   }

   int getId()
   {
      return id;
   }

   char getName()
   {
      return *name;
   }

   char getPosition()
   {
      return *position;
   }

   int getHoursWorked()
   {
      return hoursWorked;
   }

   void setId(int i)
   {
      id = i;
   }

   void setName(char *fname)
   {
      strcpy(name, fname);
   }

   void setPosition(char *pos)
   {
      strcpy(position, pos);
   }

   void setHoursWorked(float hrs)
   {
      hoursWorked = hrs;
   }

   float calSalary()
   {
      if (strcmp(position, "zahiral") == 0)
      {
         return salaryBoss();
      }
      return hoursWorked * 5;
   }
   void inputData()
   {
      cout << "Id:";
      cin >> id;
      cout << "Name:";
      cin >> name;
      cout << "Position:";
      cin >> position;
      cout << "Hours:";
      cin >> hoursWorked;
   }
   void showData()
   {
      cout << "Id:" << id << endl;
      cout << "Name:" << name << endl;
      // cout << "Position:" << position << endl;
      // cout << "Hours:" << hoursWorked << endl;
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
      delete name;
      delete position;
   }

   void swap(Employee &emp1, Employee &emp2)
   {
      Employee temp;
      temp = emp1;
      emp1 = emp2;
      emp2 = temp;
   }

private:
   float salaryBoss()
   {
      return hoursWorked * 8;
   }
};

int main()
{
   int i, j;
   Employee *emp = new Employee[4];

   for (i = 0; i < 3; i++)
   {
      cout << "Shine Ajilchinii medeelliig oruulna uu: \n";
      emp[i].inputData();

      while (1)
      {
         int q = 0;
         for (j = 0; j < i; j++)
         {
            if (emp[i].getId() == emp[j].getId())
            {
               q++;
            }
         }
         if (q == 0)
            break;
         else
         {
            cout << "!!!Ajilchinii ID davhtsaj bn. Dahin medeellee oruulna uu. \n";
            emp[i].inputData();
         }
      }
   }

   for (i = 0; i < 3; i++)
   {
      for (j = i; j < 3; j++)
      {
         if (emp[i].getName() > emp[j].getName())
         {
            Employee temp;
            temp = emp[i];
            emp[i] = emp[j];
            emp[j] = temp;
         }
      }
   }

   for (i = 0; i < 3; i++)
   {
      cout << "Ajilchid: \n";
      emp[i].showData();
   }

   return 0;
}