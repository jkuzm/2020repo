// STL_elements_learning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ostream_operator_example from http://www.cplusplus.com/reference/iterator/ostream_iterator/


#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>

int main()
{
    std::cout << "Hello World!\n";
    std::vector<int> myvector { 1,2,3,4,5 };
    //nice!!! automation of separator when outputting containers
    std::ostream_iterator<int> out_it(std::cout, ", ");
    std::copy(myvector.begin(), myvector.end(), out_it);
    std::cout << "\nnow front_inserter";
    std::deque<int> myqueue{ 11,22,33 };
    std::copy(myvector.begin(), myvector.end(), std::front_inserter(myqueue));
    std::copy(myqueue.begin(), myqueue.end(), out_it);
    //output looks like 5,4,3,2,1,11,22,33 so insertion happens from original pos[0] to the left
    //another way of output
    for (auto i : myqueue)
        std::cout << i << " ";
    std::cout << "\n";
    std::vector<int> queue_input { 1,8,5,6,3,4,0,9,7,2 };
    //lambda function for prioritizing function
    auto cmp = [](int left, int right) {return(left < right); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> myq(cmp);
    for (auto i : queue_input)
        myq.push(i);
    while(!myq.empty()) {
        std::cout << myq.top() << " ";
        myq.pop();
    }
    std::cout << "\n";
    // Function to return the only odd 
    // occurring element 
    std::vector<int> v_oneoddnum { 1,2,3,6,4,5,1,2,3,4,5 };
    int res = 0;
    
    for (auto i = v_oneoddnum.begin(); i != v_oneoddnum.end(); ++i) {
        std::cout << *i << " ";
        res ^= *i;
    }
    std::cout << "found one odd num: " << res;
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
