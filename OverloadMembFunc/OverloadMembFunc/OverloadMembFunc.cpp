// OverloadMembFunc.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Training based on Advanced C++ Programming book
// This one is chapter 1 Operator overloading

#include <iostream>

using namespace std
#include "Header.h"

int main()
{
    cout << "Hello World!\n";
    Fraction a(2, 3), b(5, 2), c;
    c = a * b;
    c.print();

    //extend use for lambda sample from utube A Tutorial Introduction to C++11/14 - Part II
    double target = 4.9;
    double epsilon = 0.3;

    auto withinEpsilon = [=](double val) //keeping= but better [target,epsilon]
    {return fabs(target - val) < epsilon; };

    cout << (withinEpsilon(5.1) ? "Yes" : "No");

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
