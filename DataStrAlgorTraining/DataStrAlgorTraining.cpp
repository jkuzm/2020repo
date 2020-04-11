// DataStrAlgorTraining.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <string>
#include <array>

using namespace std;

void reverse(string str) {
    if (str.size() == 0)
        return;
    reverse(str.substr(1));
    cout << str[0];
}

bool isPalindrome(char str[], int start, int end) {
    //cout << "checking positions " << start << " and " << end << endl;
    if (start == end) {
        //cout << "[" << str[start] << "] & ret true" << endl;
        return true;
    }
    if (str[start] != str[end]) {
        //cout << "[" << str[start] << "] != [" <<  str[start] << "] & ret false" << endl;
        return false;
    }
    if (start < end + 1) {
        //cout << "going into recursion with start pos " << start + 1 << " end pos " << end - 1 << endl;
        return isPalindrome(str, start + 1, end - 1);
    }
    //cout << "final return true" << endl;
    return true;
}

int firstNonRepeating(char* str) {
    //lets keep record of each of 256 characters, initializing each with -1 while it's not met
    array<int, 256> allchars;
    allchars.fill(-1);

    for (int i = 0; str[i]; ++i) {
        //allchars[str[i]] = (allchars[str[i]] == -1) ? i : -2;
        cout << "set pos " << (int)str[i];
        if (allchars[str[i]] == -1) {
            allchars[str[i]] = i;
            cout << " to idx " << i << endl;
        }
        else {
            allchars[str[i]] = -2;
            cout << " to -2" << endl;
        }
    }

    int res = INT_MAX;
    int i = 0;
    for (; i < 256; ++i) {
        if (allchars[i] >= 0) {
            res = min(allchars[i], res);
        }
    }
    return res;
}

int main()
{
    std::cout << "Hello World!\n";
    //find mising number in array of consequitive numbers
    vector<int> numbers{ 1,2,3,5 };
    //expSum = n * (n+1) / 2
    const int expSum = (numbers.size() + 1) * (numbers.size() + 2) / 2;
    int actSum = 0;
    for (const auto i : numbers) {
        actSum += i;
    }
    int misNum = expSum - actSum;
    cout << "for array: ";
    for (const auto& v : numbers)
        cout << v << " ";
    cout << "\n and missing number is : " << misNum << endl;

    //how to swap 2 integers
    int x = 2, y = 3;
    cout << "started with x = " << x << ", y = " << y << endl;
    x = x + y;
    y = x - y;
    x = x - y;
    cout << "ended with x = " << x << ", y = " << y << endl;

    //find middle of list in one iteration
    list<int> mylist{ 1,2,3,4,5 };
    mylist.push_back(6);
    mylist.push_front(0);
    auto halfslow_it = mylist.begin();
    unsigned char bin = 0;
    //std::_List_iterator, auto halfslow_it = mylist.cbegin() ????
    for (auto norm_it = mylist.cbegin(); norm_it != mylist.cend(); norm_it++) {
        cout << *norm_it << " ";
        //bin++ % 2 ? halfslow_it++; ?????
    }
    string s = "My simple string";
    //istringstream iss(s);
    cout << "\n" << s << endl;
    //std::vector<std::string> words = ((istream_iterator<std::string>(iss)), istream_iterator<std::string>());
    vector<int> myv{ 1,2,3,4,5 };
    auto a = find_if(myv.begin(), myv.end(), [](int i) { return (i > 2); });
    cout << "first >2 number is : " << *a;

    //interview question: find dups in one loop (0)N or so
    //initiate an array of indexes for each of char 
    const char charssize = 'z' - 'a' + 1;
    static array<int, charssize> charoccurrences;
    charoccurrences.fill(0);
    char mystr[] = "abcdee";
    cout << "size of all chars counters : " << charoccurrences.size() << endl;

    for (int i = 0; i < sizeof(mystr) - 1; ++i) {
        int ii = (int)mystr[i] - (int)'a';
        cout << "for char " << mystr[i] << " index is " << ii << endl;
        if (++charoccurrences[ii] > 1)
            cout << "symbol " << mystr[i] << " has duplicates" << endl;
    }

    //reverse a string using recursion
    //this python sample was more intuitive: https://www.cs.usfca.edu/~galles/visualization/RecReverse.html

    cout << "Lets reverse the string: " << mystr << endl;
    reverse(mystr);
    cout << endl;

    char pal[] = "arosaupalanalapuasora";
    //char pal[] = "abba";
    //check if string is a palindrome
    string resultstr = isPalindrome(pal, 0, sizeof(pal) - 2) ? " is a palindrome." : " is NOT a palindrome.";
    cout << "String " << pal << " " << resultstr << endl;
   
    // First non-repeating character using one traversal of string
    // https://www.geeksforgeeks.org/first-non-repeating-character-using-one-traversal-of-string-set-2/
    char str2[] = "swiss";
    int pos = firstNonRepeating(str2);
    if (pos != INT_MAX) 
        cout << "first non-repeating char in str " << str2 << " is in position : " << pos << endl;
    else
        cout << "No non-repeating chars in str " << str2 << endl;
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
