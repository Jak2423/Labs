#include <iostream>
#include <vector>
using namespace std;

const int NUM_LECTURES = 16;
const int NUM_LABORATORY = 16;

class Person
{
private:
   string name;

public:
   Person()
   {
      name = "";
   }
   Person(string n)
   {
      name = n;
   }
   string getName()
   {
      return name;
   }
   void setName(string n)
   {
      name = n;
   }
   void inputData()
   {
      cout << "Ner: ";
      cin >> name;
   }
};

class Teacher : public Person
{
private:
   string id;

public:
   Teacher()
   {
      setName("");
      id = "";
   }
   Teacher(string _id, string _name)
   {
      id = _id;
      setName(_name);
   }
   string getId()
   {
      return id;
   }
   void setId(string n)
   {
      id = n;
   }
   void inputData()
   {
      string n;
      cout << "ID: ";
      cin >> id;
      cout << "Ner: ";
      cin >> n;
      setName(n);
   }
   void showData()
   {
      cout << "ID: " << id << "Name: " << getName() << endl;
   }
};

class Student : public Person
{
private:
   string id;
   string status[16];

public:
   Student()
   {
      id = "";
      setName("");
   }
   string getId()
   {
      return id;
   }
   void getStatus()
   {
      for (int i = 0; i < 16; i++)
      {
         cout << i + 1 << ": " << status[i] << endl;
      }
   }
   void setId(string n)
   {
      id = n;
   }
   void setStatus(int n, string s)
   {
      status[n] = s;
   }
   void inputData()
   {
      string n;
      cout << "ID: ";
      cin >> id;
      cout << "Ner: ";
      cin >> n;
      setName(n);
   }
   void showData()
   {
      cout << "ID: " << id << " "
           << "Name: " << getName() << endl;
   }
};

class Course
{
private:
   int LecOrolt;
   int LabOrolt;
   string index;
   string name;
   int lec_num_students;
   int lab_num_students;
   int labs;
   string sedev[16];

public:
   Teacher LecTeacher;
   Teacher LabTeacher;
   vector<Student>
       LecStudents;
   vector<Student>
       LabStudents;

   Course()
   {
      index = "";
      name = "";
      lec_num_students = 0;
      LecOrolt = 1;
   }
   Course(string _id, string _name, Teacher t)
   {
      index = _id;
      name = _name;
      LecTeacher = t;
   }
   string getIndex()
   {
      return index;
   }
   string getName()
   {
      return name;
   }
   string getSedev(int n)
   {
      return sedev[n];
   }
   void setIndex(string _id)
   {
      index = _id;
   }
   void setName(string _name)
   {
      name = _name;
   }
   void setSedev(string _sedev)
   {
      sedev[LecOrolt] = _sedev;
   }
   void setLecTeacher(Teacher t)
   {
      LecTeacher = t;
   }
   Teacher getLecTeacher()
   {
      return LecTeacher;
   }
   void inputLecStudents()
   {
      int n;
      cout << "Lektsiin suragchdiin too: ";
      cin >> n;
      lec_num_students = n;
      string name, id;
      for (int i = 0; i < lec_num_students; i++)
      {
         Student s;
         cout << "ID: ";
         cin >> id;
         cout << "Name: ";
         cin >> name;
         s.setId(id);
         s.setName(name);
         LecStudents.push_back(s);
      }
   }

   void registerLecStudent()
   {
      string sedev;
      cout << "Orson lektsiin sedev: ";
      cin >> sedev;
      setSedev(sedev);
      for (int i = 0; i < lec_num_students; i++)
      {
         int n;
         cout << "ID: " << LecStudents[i].getId() << endl;
         cout << "Ner: " << LecStudents[i].getName() << endl;
         cout << "Irts: 1-Irsen, 2-Tasalsan, 3-Uvchtei, 4-Chuluutei\n";
         cin >> n;
         if (n == 1)
         {
            LecStudents[i].setStatus(LecOrolt, "Irsen");
         }
         else if (n == 2)
         {
            LecStudents[i].setStatus(LecOrolt, "Tasalsan");
         }
         else if (n == 3)
         {
            LecStudents[i].setStatus(LecOrolt, "Uvchtei");
         }
         else if (n == 4)
         {
            LecStudents[i].setStatus(LecOrolt, "Chuluutei");
         }
         else
         {
            break;
         }
      }
      LecOrolt++;
   }
   void lecStudentsData()
   {
      for (int i = 0; i < lec_num_students; i++)
      {
         if (LecStudents.empty() == true)
         {
            break;
         }
         cout << "ID: " << LecStudents[i].getId() << " "
              << "Ner: " << LecStudents[i].getName() << endl;
         cout << "Irts: \n";
         LecStudents[i].getStatus();
      }
   };
   void inputLabStudents()
   {
      int n;
      cout << "Labiin suragchdiin too: ";
      cin >> n;
      lab_num_students = n;
      string name, id;
      for (int i = 0; i < lab_num_students; i++)
      {
         Student s;
         cout << "ID: ";
         cin >> id;
         cout << "Name: ";
         cin >> name;
         s.setId(id);
         s.setName(name);
         LabStudents.push_back(s);
      }
   }
   void registerLabStudent()
   {
      for (int i = 0; i < lab_num_students; i++)
      {
         int n;
         cout << "ID: " << LabStudents[i].getId() << endl;
         cout << "Ner: " << LabStudents[i].getName() << endl;
         cout << "Irts: 1-Irsen, 2-Tasalsan, 3-Uvchtei, 4-Chuluutei\n";
         cin >> n;
         if (n == 1)
         {
            LabStudents[i].setStatus(LabOrolt, "Irsen");
         }
         else if (n == 2)
         {
            LabStudents[i].setStatus(LabOrolt, "Tasalsan");
         }
         else if (n == 3)
         {
            LabStudents[i].setStatus(LabOrolt, "Uvchtei");
         }
         else if (n == 4)
         {
            LabStudents[i].setStatus(LabOrolt, "Chuluutei");
         }
         else
         {
            break;
         }
      }
      LabOrolt++;
   }
   void labStudentsData()
   {
      for (int i = 0; i < lab_num_students; i++)
      {
         if (LabStudents.empty() == true)
         {
            break;
         }
         cout << "ID: " << LabStudents[i].getId() << " "
              << "Ner: " << LabStudents[i].getName() << endl;
         cout << "Irts: \n";
         LabStudents[i].getStatus();
      }
   };
};

int main()
{
   Teacher t1("t1", "Uganbayar");
   Course oop("ICSI201", "Object Oriented Programming", t1);

   while (1)
   {
      int n;
      cout << "\n1: Hicheeliin medeelliig harah, 2: Lektsiin suragchdiin medeelliig oruulah, 3: Labortoriin suragchdiin medeelliig oruulah, 4: Lektsiin irtsiin burtgeh, 5: Labiin irts burtgeh, 6: Lektsiin irtsiin medeelel, 7: Labiin irtsiin medeelel\n";
      cin >> n;

      if (n == 1)
      {
         cout << "Hicheeliin index: " << oop.getIndex() << endl;
         cout << "Hicheeliin ner: " << oop.getName() << endl;
      }
      else if (n == 2)
      {
         oop.inputLecStudents();
      }
      else if (n == 3)
      {
         oop.inputLabStudents();
      }
      else if (n == 4)
      {
         oop.registerLecStudent();
      }
      else if (n == 5)
      {
         oop.registerLabStudent();
      }
      else if (n == 6)
      {
         oop.lecStudentsData();
      }
      else if (n == 7)
      {
         oop.labStudentsData();
      }
      else
      {
         break;
      }
   }

   return 0;
}