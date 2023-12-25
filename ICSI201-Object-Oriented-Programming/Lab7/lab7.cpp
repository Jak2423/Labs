#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define pi 3.14

class Shape
{
protected:
   char *name;

public:
   Shape()
   {
      name = new char[2];
      strcpy(name, "");
   }

   ~Shape()
   {
      delete name;
   }
};

class TwoDiShape : public Shape
{
protected:
   int *x;
   int *y;

public:
   float area();
   float perimeter();
};

class Circle : public TwoDiShape
{
private:
   float rad;

public:
   Circle()
   {
      name = new char[6];
      strcpy(name, "Circle");
      x = new int[1];
      y = new int[1];
      rad = 0;
   }
   ~Circle()
   {
      delete name;
      delete x;
      delete y;
   }

   void setX(int _x)
   {
      x = &_x;
   }
   void setY(int _y)
   {
      y = &_y;
   }
   void setRad(int r)
   {
      rad = r;
   }

   float area()
   {
      return pi * rad * rad;
   }
   float perimeter()
   {
      return 2 * pi * rad;
   }
};

class Square : public TwoDiShape
{
private:
   float a;

public:
   Square()
   {
      name = new char[6];
      strcpy(name, "Square");
      x = new int[4];
      y = new int[4];
      a = 0;
   }

   ~Square()
   {
      delete name;
      delete x;
      delete y;
   }
   void setX(int _x)
   {
      x[0] = _x;
      x[1] = _x + a;
      x[2] = _x + a;
      x[3] = _x;
   }
   void setY(int _y)
   {
      y[0] = _y;
      y[1] = _y;
      y[2] = _y - a;
      y[3] = _y - a;
   }

   void setA(int side)
   {
      a = side;
   }

   float area()
   {
      return a * a;
   }
   float perimeter()
   {
      return 4 * a;
   }
};

class Triangle : public TwoDiShape
{
private:
   float a;

public:
   Triangle()
   {
      name = new char[8];
      strcpy(name, "Triangle");
      x = new int[3];
      y = new int[3];
      a = 0;
   }

   ~Triangle()
   {
      delete name;
      delete x;
      delete y;
   }
   void setX(int _x)
   {
      x[0] = _x;
      x[1] = _x + a / 2;
      x[2] = _x - a / 2;
   }
   void setY(int _y)
   {
      float undur = sqrt(3) / 4 * a;
      y[0] = _y;
      y[1] = _y - undur;
      y[2] = _y - undur;
   }

   void setA(int side)
   {
      a = side;
   }
   float area()
   {
      return sqrt(3) / 4 * a * a;
   }
   float perimeter()
   {
      return 3 * a;
   }
};

int main()
{
   Circle c;
   Square s;
   Triangle t;

   c.setRad(3);
   s.setA(4);
   t.setA(2);

   s.setX(4);
   s.setY(4);

   cout
       << "Toirgiin talbai: " << c.area() << endl;
   cout << "Toirgiin perimetr: " << c.perimeter() << endl;

   cout << "Durvuljini talbai: " << s.area() << endl;
   cout << "Durvuljini perimetr: " << s.perimeter() << endl;

   cout << "Gurvaljni talbai: " << t.area() << endl;
   cout << "Gurvaljni perimetr: " << t.perimeter() << endl;

   return 0;
}