// MultiInheritanceTraining.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Point {
protected:
    int x, y;
public:
    Point()
    {
        x = 10;
        y = 20;
        cout << "In default Point constructor" << endl;
    }
    Point(int a, int b) : x(a), y(b)
    {
        cout << "Point constructor" << endl;
    }
    Point(const Point& arg) : x(arg.x), y(arg.y)
    {
        cout << "Point copy constructor" << endl;
    }
};

class ColorPoint : virtual public Point {
protected:
    int color;
public:
    ColorPoint(int a, int b, int col) :
        Point(a, b), color(col)
    {
        cout << "ColorPoint ctor\n" << endl;
    }
};

class WidePoint : virtual public Point {
protected:
    int width;
public:
    WidePoint(int a, int b, int wid) :
        Point(a, b), width(wid)
    {
        cout << "WidePoint ctor" << endl;
    }
};

class WCPoint : public ColorPoint, public WidePoint
{
public:
    WCPoint(int a, int b, int col, int wid) :
        Point(a,b), ColorPoint(a, b, col), WidePoint(a, b, wid)
    {
        cout << "WCPoint constructor" << endl;
    }

   void print()
    {
       cout << "x:" << this->x << endl;
       cout << "y:" << this->y << endl;
       cout << "color:" << this->color << endl;
       cout << "width:" << this->width << endl;
    };
};
int main()
{
    std::cout << "Hello World!\n";

    WCPoint wcp1(1, 2, 3, 4);
    wcp1.print();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
