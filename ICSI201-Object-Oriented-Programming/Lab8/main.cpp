#include <iostream>
#include <vector>
using namespace std;

struct Date
{
   int year;
   int month;
   int day;
};

class Person
{
private:
   string name;
   string ssNum;
   int age;

public:
   Person()
   {
      name = "javkhlan";
      ssNum = "UTs02242051";
      age = 16;
   }
   Person(string n, string ss, int a)
   {
      name = n;
      ssNum = ss;
      age = a;
   }
   string getName()
   {
      return name;
   }
   string getSSNum()
   {
      return ssNum;
   }
   int getAge()
   {
      return age;
   }
   void setName(string n)
   {
      name = n;
   }
   void setSSNum(string ss)
   {
      ssNum = ss;
   }
   void setAge(int a)
   {
      age = a;
   }
   void inputData(string n, string ss, int a)
   {
      name = n;
      ssNum = ss;
      age = a;
   }
};

class Spouse : public Person
{
private:
   Date anniversaryDate;

public:
   Spouse()
   {
      inputData("", "", 0);
      anniversaryDate.year = 2022;
      anniversaryDate.month = 11;
      anniversaryDate.day = 1;
   }
   Spouse(string n, string ss, int a, int y, int m, int d)
   {
      inputData(n, ss, a);
      anniversaryDate.year = y;
      anniversaryDate.month = m;
      anniversaryDate.day = d;
   }
   Date getAnniversaryDate()
   {
      return anniversaryDate;
   }
   void setAnniversaryDate(Date d)
   {
      anniversaryDate = d;
   }
};

class Child : public Person
{
private:
   string favoriteToy;

public:
   Child()
   {
      inputData("", "", 0);
      favoriteToy = "";
   }
   Child(string n, string ss, int a, string t)
   {
      inputData(n, ss, a);
      favoriteToy = t;
   }
   string getFavoriteToy()
   {
      return favoriteToy;
   }
   void setFavoriteToy(string toy)
   {
      favoriteToy = toy;
   }
};

class Division
{
private:
   string divisionName;

public:
   Division()
   {
      divisionName = "";
   }
   string getDivisionName()
   {
      return divisionName;
   }
   void setDivisionName(string division)
   {
      divisionName = division;
   }
};

class JobDescription
{
private:
   string jobDescription;

public:
   JobDescription()
   {
      jobDescription = "";
   }
   string getJobDescription()
   {
      return jobDescription;
   }
   void setJobDescription(string job)
   {
      jobDescription = job;
   }
};

class Employee : public Person
{
private:
   string companyId;
   string title;
   Date startDate;

public:
   vector<Spouse> spouse;
   vector<Child> childs;
   Division div;
   vector<JobDescription> jDescription;
   Employee()
   {
      inputData("", "", 0);
      companyId = "";
      title = "";
      startDate.year = 2022;
      startDate.month = 11;
      startDate.day = 1;
   }
   Employee(string n, string ss, int a, string id, string t, int y, int m, int d)
   {
      inputData(n, ss, a);
      companyId = id;
      title = t;
      startDate.year = y;
      startDate.month = m;
      startDate.day = d;
   }
   string getCompanyId()
   {
      return companyId;
   }
   string getTitle()
   {
      return title;
   }
   Date getStartDate()
   {
      return startDate;
   }
   void setCompanyId(string id)
   {
      companyId = id;
   }
   void setTitle(string t)
   {
      title = t;
   }
   void setStartDate(Date d)
   {
      startDate = d;
   }
};

int main()
{
   string n;
   Date a;

   Employee emp1("Bold", "UY21332421 ", 32, "N1", "MCS", 2016, 10, 1),
       emp2("Bataa", "US9023243", 28, "N2", "Unitel", 2020, 10, 1);

   Division div1, div2;
   JobDescription j1, j2;
   Child child1("Bat", "UB2013213", 5, "car"), child2("Anu", "UB2433242", 2, "doll");
   Spouse s1("Hulan", "UI2142343", 32, 2010, 12, 23), s2("Amar", "UI2131243", 28, 2012, 4, 10);

   emp1.spouse.push_back(s1);
   emp1.childs.push_back(child1);
   emp1.childs.push_back(child2);

   emp1.spouse.push_back(s2);

   cout << "Division name: ";
   cin >> n;
   emp1.div.setDivisionName(n);
   emp2.div.setDivisionName(n);

   cout << "Job description: ";
   cin >> n;
   j1.setJobDescription(n);
   emp1.jDescription.push_back(j1);
   emp2.jDescription.push_back(j1);

   cout << "Emp1 ner: " << emp1.getName() << endl;
   cout << "Emp1 register dugaar: " << emp1.getSSNum() << endl;
   cout << "Emp1 nas: " << emp1.getAge() << endl;

   cout << "Emp1 spouse name: " << emp1.spouse[0].getName() << endl;
   cout << "Emp1 spouse age: " << emp1.spouse[0].getAge() << endl;

   cout << "Emp1 company id: " << emp1.getCompanyId() << endl;
   cout << "Emp1 company title: " << emp1.getTitle() << endl;
   a = emp1.getStartDate();
   cout << "Emp1 job started date: "
        << "year: " << a.year << ", "
        << "month: " << a.month << ", "
        << "day: " << a.day << ", " << endl;

   a = emp1.spouse[0].getAnniversaryDate();
   cout << "Emp1 annivesary date: "
        << "year: " << a.year << ", "
        << "month: " << a.month << ", "
        << "day: " << a.day << ", " << endl;

   for (int i = 0; i < emp1.childs.size(); i++)
   {
      cout << "Emp1 child name: \n";
      cout << emp1.childs[i].getName() << endl;
      cout << "Emp1 child age: \n";
      cout << emp1.childs[i].getAge() << endl;
      cout << "Emp1 child favorite toy: \n";
      cout << emp1.childs[i].getFavoriteToy() << endl;
   }

   return 0;
}