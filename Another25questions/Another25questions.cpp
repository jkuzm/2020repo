// Another25questions.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.toptal.com/c-plus-plus/interview-questions

// tricky (for me) solution explained here
// https://stackoverflow.com/questions/39467087/implement-a-template-function-that-takes-two-classes-as-template-parameters-and
// which would otherwise be solved by std::is_base_of
// another trick is an analog of std::is_same, if class is same

#include <iostream>
#include <type_traits>

using namespace std;

template<typename D, typename B>
class isDerivedFromHelper {
    class No {};
    class Yes { No no[3]; };

    static Yes Test(B*);
    static No  Test(...);

 public:
     enum { Is = sizeof(Test(static_cast<D*>(0))) == sizeof(Yes) };
};

template< typename C, typename P>
bool isDerivedFrom() {
    return isDerivedFromHelper<C, P>::Is;
};

template<typename T, typename U>
struct is_same_mine {
    static const bool val = false;
};

template<typename T>
struct is_same_mine<T, T> {
    static const bool val = true;
};

template<typename A, typename B>
bool isSameClass() {
    return is_same_mine<A, B>::val;
}

double division(int a, int b) {
    if (b == 0) {
        throw("Division by 0 condition!!!");
    }
    return (a / b);
}

class A {};
class B:A {};
class C {};

int main()
{
    std::cout << "Hello World!\n";

    //std::cout << (25u - 50); warning arithmetic overflow
    // will print UINT32_MAX (0xffff'ffff) -25
 
    cout << "B is same as A" << isSameClass<A,B>() << endl;
    cout << "A is same as A" << isSameClass<A,A>() << endl;
    cout << "int and int32 is same? ";
    cout << std::is_same<int, std::int32_t>() << endl;
    int a = 20, b = 0;
    double z = 0;

    try {
        z = division(a,b);
        cout << "a/b=" << z << endl;
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }

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
