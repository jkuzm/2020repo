// STL_elements_learning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ostream_operator_example from http://www.cplusplus.com/reference/iterator/ostream_iterator/


#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <utility>
#include <list>

template<typename Cont>
auto findNull(const Cont& c) -> decltype(std::begin(c)) //needed in C++11 and appears C++14 needs it too
{
    auto it = std::begin(c);
    for (; it != std::end(c); ++it)
        if (*it == nullptr)
            break;
    return it;
}


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

    std::priority_queue<int, std::vector<int>> myq0;
    std::cout << "queue with default sorter function" << std::endl;
    for (auto i : queue_input)
        myq0.push(i);
    while(!myq.empty()) {
        std::cout << myq0.top() << " ";
        myq0.pop();
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
    std::vector<std::pair<int, int>> pair_input{ {1,10},{2,25},{3,30},{2,20} };
    //lambda function for prioritizing function
    auto cmp2 = [](std::pair<int, int> pr1, std::pair<int, int> pr2) 
                                    {return(pr1.first > pr2.first); };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp2)> myq2(cmp2);
    for (auto i : pair_input)
        myq2.push(i);
    std::cout << "\nQueue sorted by priority: ";
    while (!myq2.empty()) {
        auto tmppr = myq2.top();
        std::cout << myq2.top().second << " ";
        myq2.pop();
    }
    //retyped later, memory exersize
    auto cmp3 = [](std::pair<int, int>pr1, std::pair<int, int>pr2)
    {return(pr1.first > pr2.first); };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp3)>myq3(cmp3);

    for (auto i : pair_input)
        myq3.push(i);
    std::cout << "\nQueue mq3 sorted by priority: ";

    while (!myq3.empty()) {
        std::cout << myq3.top().second << " ";
        myq3.pop();
    }
    //1st priority msg comes on top etc, so - Queue sorted by priority: 10 25 20 30
    std::cout << std::endl;
    //will add some samples from slidesof yutube "A Tutorial Introduction to C++11 & 14 Part 1"
    // https://github.com/boostcon/cppnow_presentations_2014/blob/master/files/tutorial_intro_cpp_11_14.pdf
    auto strlenGT4 = [](const char* s) { return (strlen(s) > 4); };
    const char* names[]{ "Huey","Dewey","Louie" };
    auto firstGT4 = std::find_if(std::begin(names), std::end(names), strlenGT4);
    if (firstGT4 != std::end(names))
        std::cout << "First long name: " << *firstGT4 << std::endl;

    int a = 1000, b = 2000, c = 3000;
    std::vector<int*>vpi{ &a,&b,&c,0 };
    auto cit = findNull(vpi);
    if (cit != vpi.end())
    {
        auto pos = cit - vpi.begin();
        std::cout << "Null position: " << pos << std::endl;
    }

    int ai[]{ 10,20,100,200,-500,999,333 };
    for (auto i : ai)
        std::cout << i << " ";
    std::cout << std::endl;
    std::list<int> li(std::begin(ai), std::end(ai));
    for (auto &elt : li)
        elt += 10000;
    for (const auto &elt : li)
        std::cout << elt << " ";
    std::cout <<  std::endl;

    //start next with slide 25 static_assert sample
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
