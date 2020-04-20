// Test1inRepo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Fraction.h"
#include <fstream>

using namespace std;

int main()
{
    Fraction a(2, 3), b(5, 2), c(4, 3);

    c = a * b;
    c.print();
    char str2file[] = "It\'s a test\nto write into file.";
    ofstream fout;
    fout.open("test.txt");
    fout.write(str2file, sizeof(str2file));
    fout.close();
    int strlen = sizeof(str2file) / sizeof(str2file[0]);
    cout << "size of str written into file: " << strlen << endl;

    ifstream fin;
    fin.open("test.txt");
    
    fin.seekg(0, fin.end);
    int len = fin.tellg();
    cout << "size of file text is " << len << endl;
    fin.seekg(0, fin.beg);
    char* mytext = new char[len];
    fin.read(mytext, len);
    fin.close();
    cout << "we read from file:" << endl;
    cout.write(mytext, len-2);
    cout << endl;
    cout << "Last 3 letters in mystr up to len: " << 
        mytext[len - 3] << mytext[len - 2]<< mytext[len - 1] << endl;
    //note to myself, last actual letter from text is in pos [len-3]
    delete[] mytext;
    return 0;
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
